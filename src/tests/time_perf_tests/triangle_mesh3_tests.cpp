#include <benchmark/benchmark.h>
#include <jet/triangle_mesh3.h>
#include <random>
using jet::Vector3D;
class TriangleMesh3 : public ::benchmark::Fixture
{
  protected:
    std::mt19937 rng{ 0 };
    std::uniform_real_distribution<> dist{ 0.0, 1.0 };
    jet::TriangleMesh3 triMesh;
    void SetUp(const ::benchmark::State&)
    {
        std::ifstream file(RESOURCES_DIR "/bunny.obj");
        if (file) {
            triMesh.readObj(&file);
            file.close();
        }
    }
    Vector3D makeVec() { return Vector3D(dist(rng), dist(rng), dist(rng)); }
};
BENCHMARK_DEFINE_F(TriangleMesh3, ClosestPoint)(benchmark::State& state)
{
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(triMesh.closestPoint(makeVec()));
    }
}
BENCHMARK_REGISTER_F(TriangleMesh3, ClosestPoint);
BENCHMARK_DEFINE_F(TriangleMesh3, IsInside)(benchmark::State& state)
{
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(triMesh.isInside(makeVec()));
    }
}
BENCHMARK_REGISTER_F(TriangleMesh3, IsInside);
