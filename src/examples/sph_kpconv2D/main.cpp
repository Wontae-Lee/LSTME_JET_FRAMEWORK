// Copyright (c) 2018 Doyub Kim
//
// I am making my contributions/submissions to this project solely in my
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#include <jet/jet.h>
#include <pystring/pystring.h>
#include <sys/stat.h>

#include <clara.hpp>
#include <example_utils/clara_utils.h>

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#define APP_NAME "sph_sim"
using namespace jet;

void
saveParticleAsPos(const ParticleSystemData2Ptr& particles, const std::string& rootDir, int frameCnt)
{
  Array1<Vector2D> positions(particles->numberOfParticles());
  copyRange1(particles->positions(), particles->numberOfParticles(), &positions);
  char basename[256];
  snprintf(basename, sizeof(basename), "frame_%06d.pos", frameCnt);
  std::string filename = pystring::os::path::join(rootDir, basename);
  std::ofstream file(filename.c_str(), std::ios::binary);
  if (file) {
    printf("Writing %s...\n", filename.c_str());
    std::vector<uint8_t> buffer;
    serialize(positions.constAccessor(), &buffer);
    file.write(reinterpret_cast<char*>(buffer.data()), buffer.size());
    file.close();
  }
}

void
saveParticleAsXyz(const ParticleSystemData2Ptr& particles, const std::string& rootDir, int frameCnt)
{
  Array1<Vector2D> positions(particles->numberOfParticles());
  copyRange1(particles->positions(), particles->numberOfParticles(), &positions);
  char basename[256];
  snprintf(basename, sizeof(basename), "frame_%06d.xyz", frameCnt);
  std::string filename = pystring::os::path::join(rootDir, basename);
  std::ofstream file(filename.c_str());
  if (file) {
    printf("Writing %s...\n", filename.c_str());
    for (const auto& pt : positions) {
      file << pt.x << ' ' << pt.y << std::endl;
    }
    file.close();
  }
}

void
printInfo(const SphSolver2Ptr& solver)
{
  auto particles = solver->sphSystemData();
  printf("Number of particles: %zu\n", particles->numberOfParticles());
}

void
runSimulation(const std::string& rootDir, const SphSolver2Ptr& solver, int numberOfFrames, const std::string& format, double fps)
{
  auto particles = solver->sphSystemData();

  for (Frame frame(0, 1.0 / fps); frame.index < numberOfFrames; ++frame) {
    solver->update(frame);
    if (format == "xyz") {
      saveParticleAsXyz(particles, rootDir, frame.index);
    } else if (format == "pos") {
      saveParticleAsPos(particles, rootDir, frame.index);
    }
  }
}

// Dam-breaking example
void
runExample(const std::string& rootDir, double targetSpacing, int numberOfFrames, const std::string& format, double fps)
{
  // 랜덤 엔진 초기화
  std::default_random_engine generator;
  generator.seed(std::random_device()()); // 현재 시간을 기반으로 시드 설정

  // 0.0에서 1.0 사이의 실수를 랜덤으로 생성하는 분포 설정
  std::uniform_real_distribution<float> distribution1(0.2, 0.8);
  std::uniform_real_distribution<float> distribution2(0.5, 2.0);

  // 랜덤한 숫자 생성
  float randomPosX = distribution1(generator);
  float randomPoxY = distribution2(generator);

  // 도메인 범위
  BoundingBox2D domain(Vector2D(), Vector2D(1, 3));

  // Build solver
  auto solver = PciSphSolver2::builder().withTargetDensity(1000.0).withTargetSpacing(targetSpacing).makeShared();

  solver->setPseudoViscosityCoefficient(0.0);
  solver->setTimeStepLimitScale(10.0);

  // Build emitter
  BoundingBox2D sourceBound(domain);
  sourceBound.expand(-targetSpacing);

  auto box1 = Box2::builder().withLowerCorner({ 0.1, 2.7 }).withUpperCorner({ 0.9, 2.9 }).makeShared();
  auto boxSet = ImplicitSurfaceSet2::builder().withExplicitSurfaces({ box1 }).makeShared();
  auto emitter = VolumeParticleEmitter2::builder().withSurface(boxSet).withMaxRegion(sourceBound).withSpacing(targetSpacing).makeShared();

  solver->setEmitter(emitter);

  // Build collider
  auto cyl = Sphere2::builder().withCenter({ randomPosX, randomPoxY }).withRadius(0.15).makeShared();
  auto box = Box2::builder().withIsNormalFlipped(true).withBoundingBox(domain).makeShared();
  auto surfaceSet = ImplicitSurfaceSet2::builder().withExplicitSurfaces({ cyl, box }).makeShared();
  auto collider = RigidBodyCollider2::builder().withSurface(surfaceSet).makeShared();

  solver->setCollider(collider);

  // Print simulation info
  char basename[256];
  snprintf(basename, sizeof(basename), "info.txt");
  std::string filename = pystring::os::path::join(rootDir, basename);
  std::ofstream file(filename.c_str());
  if (file) {
    file << randomPosX << ' ' << randomPoxY << ' ' << 0.15 << std::endl;
  }
  file.close();

  printf("Running example (dam-breaking with PCISPH)\n");
  printInfo(solver);

  // Run simulation
  runSimulation(rootDir, solver, numberOfFrames, format, fps);
}

int
main(int argc, char* argv[])
{
  bool showHelp = false;
  double targetSpacing = 0.02;
  int numberOfFrames = 100;
  double fps = 60.0;

  for (int i = 0; i != 100; i++) {

    std::string numData = std::to_string(i);
    std::string logFilename = APP_NAME ".log";
    std::string outputDir = APP_NAME "_output" + numData;
    std::string dataFilename = APP_NAME "info" + numData;
    std::string format = "xyz";

    // Parsing
    auto parser = clara::Help(showHelp) | clara::Opt(targetSpacing, "targetSpacing")["-s"]["--spacing"]("target particle spacing (default is 0.02)") |
                  clara::Opt(numberOfFrames, "numberOfFrames")["-f"]["--frames"]("total number of frames (default is 100)") |
                  clara::Opt(fps, "fps")["-p"]["--fps"]("frames per second (default is 60.0)") |
                  clara::Opt(logFilename, "logFilename")["-l"]["--log"]("log file name (default is " APP_NAME ".log)") |
                  clara::Opt(outputDir, "outputDir")["-o"]["--output"]("output directory name (default is " APP_NAME "_output)") |
                  clara::Opt(format, "format")["-m"]["--format"]("particle output format (xyz or pos. default is xyz)");

    auto result = parser.parse(clara::Args(argc, argv));
    if (!result) {
      std::cerr << "Error in command line: " << result.errorMessage() << '\n';
      exit(EXIT_FAILURE);
    }

    if (showHelp) {
      std::cout << toString(parser) << '\n';
      exit(EXIT_SUCCESS);
    }

    mkdir(outputDir.c_str(), S_IRWXU | S_IRWXG | S_IRWXO);

    std::ofstream logFile(logFilename.c_str());
    if (logFile) {
      Logging::setAllStream(&logFile);
    }
    runExample(outputDir, targetSpacing, numberOfFrames, format, fps);
  }
  return EXIT_SUCCESS;
}
