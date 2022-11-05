#include <benchmark/benchmark.h>
#include <jet/box3.h>
#include <jet/implicit_surface_set3.h>
#include <jet/timer.h>
#include <jet/volume_particle_emitter3.h>
using jet::BoundingBox3D;
using jet::Box3;
using jet::ImplicitSurfaceSet3;
using jet::ParticleSystemData3;
class VolumeParticleEmitter3 : public ::benchmark::Fixture
{
  protected:
    jet::VolumeParticleEmitter3Ptr emitter;
    void SetUp(const ::benchmark::State&)
    {
        double dx = 0.2;
        double lx = 30.0;
        double ly = 30.0;
        double lz = 30.0;
        double pd = 0.001;
        // Build emitter
        auto box1 = Box3::builder()
                        .withLowerCorner({ 0, 0, 0 })
                        .withUpperCorner(
                            { 0.5 * lx + pd, 0.75 * ly + pd, 0.75 * lz + pd })
                        .makeShared();
        auto box2 = Box3::builder()
                        .withLowerCorner({ 2.5 * lx - pd, 0, 0.25 * lz - pd })
                        .withUpperCorner(
                            { 3.5 * lx + pd, 0.75 * ly + pd, 1.5 * lz + pd })
                        .makeShared();
        auto boxSet = ImplicitSurfaceSet3::builder()
                          .withExplicitSurfaces({ box1, box2 })
                          .makeShared();
        emitter = jet::VolumeParticleEmitter3::builder()
                      .withSurface(boxSet)
                      .withMaxRegion(BoundingBox3D({ 0, 0, 0 }, { lx, ly, lz }))
                      .withSpacing(0.5 * dx)
                      .withAllowOverlapping(true)
                      .makeShared();
        auto particles = std::make_shared<ParticleSystemData3>();
        emitter->setTarget(particles);
    }
};
BENCHMARK_DEFINE_F(VolumeParticleEmitter3, Update)(benchmark::State& state)
{
    while (state.KeepRunning()) {
        emitter->update(0.0, 0.01);
    }
}

BENCHMARK_REGISTER_F(VolumeParticleEmitter3, Update);
