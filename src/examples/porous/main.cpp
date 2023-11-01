
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

  // radius range 설정
  float minRadius = 0.1;
  float maxRadius = 0.19;

  // 각 구조물에 대한 랜덤한 radius distribution 설정
  std::uniform_real_distribution<float> distribution1(minRadius, maxRadius);
  std::uniform_real_distribution<float> distribution2(minRadius, maxRadius);
  std::uniform_real_distribution<float> distribution3(minRadius, maxRadius);
  std::uniform_real_distribution<float> distribution4(minRadius, maxRadius);
  std::uniform_real_distribution<float> distribution5(minRadius, maxRadius);
  std::uniform_real_distribution<float> distribution6(minRadius, maxRadius);
  std::uniform_real_distribution<float> distribution7(minRadius, maxRadius);
  std::uniform_real_distribution<float> distribution8(minRadius, maxRadius);
  std::uniform_real_distribution<float> distribution9(minRadius, maxRadius);
  std::uniform_real_distribution<float> distribution10(minRadius, maxRadius);
  std::uniform_real_distribution<float> distribution11(minRadius, maxRadius);
  std::uniform_real_distribution<float> distribution12(minRadius, maxRadius);
  std::uniform_real_distribution<float> distribution13(minRadius, maxRadius);
  std::uniform_real_distribution<float> distribution14(minRadius, maxRadius);
  std::uniform_real_distribution<float> distribution15(minRadius, maxRadius);
  std::uniform_real_distribution<float> distribution16(minRadius, maxRadius);
  std::uniform_real_distribution<float> distribution17(minRadius, maxRadius);
  std::uniform_real_distribution<float> distribution18(minRadius, maxRadius);

  // 랜덤한 radius 설정
  float randomRadius1 = distribution1(generator);
  float randomRadius2 = distribution2(generator);
  float randomRadius3 = distribution3(generator);
  float randomRadius4 = distribution4(generator);
  float randomRadius5 = distribution5(generator);
  float randomRadius6 = distribution6(generator);
  float randomRadius7 = distribution7(generator);
  float randomRadius8 = distribution8(generator);
  float randomRadius9 = distribution9(generator);
  float randomRadius10 = distribution10(generator);
  float randomRadius11 = distribution11(generator);
  float randomRadius12 = distribution12(generator);
  float randomRadius13 = distribution13(generator);
  float randomRadius14 = distribution14(generator);
  float randomRadius15 = distribution15(generator);
  float randomRadius16 = distribution16(generator);
  float randomRadius17 = distribution17(generator);
  float randomRadius18 = distribution18(generator);

  // 도메인 범위
  float maxDomainX = 2.4;
  float maxDomainY = 1.8;
  BoundingBox2D domain(Vector2D(), Vector2D(maxDomainX, maxDomainY));

  // Build solver
  auto solver = PciSphSolver2::builder().withTargetDensity(1000.0).withTargetSpacing(targetSpacing).makeShared();

  solver->setPseudoViscosityCoefficient(0.0);
  solver->setTimeStepLimitScale(10.0);

  // Build emitter
  BoundingBox2D sourceBound(domain);
  sourceBound.expand(-targetSpacing);

  auto box1 = Box2::builder().withLowerCorner({ 0.0, 1.4 }).withUpperCorner({ 2.4, 1.5 }).makeShared();
  auto boxSet = ImplicitSurfaceSet2::builder().withExplicitSurfaces({ box1 }).makeShared();
  auto emitter = VolumeParticleEmitter2::builder().withSurface(boxSet).withMaxRegion(sourceBound).withSpacing(targetSpacing).makeShared();

  solver->setEmitter(emitter);

  // Build collider
  auto cyl1 = Sphere2::builder().withCenter({ 0.2, 0.4 }).withRadius(randomRadius1).makeShared();
  auto cyl2 = Sphere2::builder().withCenter({ 0.2, 0.8 }).withRadius(randomRadius2).makeShared();
  auto cyl3 = Sphere2::builder().withCenter({ 0.2, 1.2 }).withRadius(randomRadius3).makeShared();
  auto cyl4 = Sphere2::builder().withCenter({ 0.6, 0.4 }).withRadius(randomRadius4).makeShared();
  auto cyl5 = Sphere2::builder().withCenter({ 0.6, 0.8 }).withRadius(randomRadius5).makeShared();
  auto cyl6 = Sphere2::builder().withCenter({ 0.6, 1.2 }).withRadius(randomRadius6).makeShared();
  auto cyl7 = Sphere2::builder().withCenter({ 1.0, 0.4 }).withRadius(randomRadius7).makeShared();
  auto cyl8 = Sphere2::builder().withCenter({ 1.0, 0.8 }).withRadius(randomRadius8).makeShared();
  auto cyl9 = Sphere2::builder().withCenter({ 1.0, 1.2 }).withRadius(randomRadius9).makeShared();
  auto cyl10 = Sphere2::builder().withCenter({ 1.4, 0.4 }).withRadius(randomRadius10).makeShared();
  auto cyl11 = Sphere2::builder().withCenter({ 1.4, 0.8 }).withRadius(randomRadius11).makeShared();
  auto cyl12 = Sphere2::builder().withCenter({ 1.4, 1.2 }).withRadius(randomRadius12).makeShared();
  auto cyl13 = Sphere2::builder().withCenter({ 1.8, 0.4 }).withRadius(randomRadius13).makeShared();
  auto cyl14 = Sphere2::builder().withCenter({ 1.8, 0.8 }).withRadius(randomRadius14).makeShared();
  auto cyl15 = Sphere2::builder().withCenter({ 1.8, 1.2 }).withRadius(randomRadius15).makeShared();
  auto cyl16 = Sphere2::builder().withCenter({ 2.2, 0.4 }).withRadius(randomRadius16).makeShared();
  auto cyl17 = Sphere2::builder().withCenter({ 2.2, 0.8 }).withRadius(randomRadius17).makeShared();
  auto cyl18 = Sphere2::builder().withCenter({ 2.2, 1.2 }).withRadius(randomRadius18).makeShared();

  auto box = Box2::builder().withIsNormalFlipped(true).withBoundingBox(domain).makeShared();
  auto surfaceSet = ImplicitSurfaceSet2::builder()
                      .withExplicitSurfaces(
                        { cyl1, cyl2, cyl3, cyl4, cyl5, cyl6, cyl7, cyl8, cyl9, cyl10, cyl11, cyl12, cyl13, cyl14, cyl15, cyl16, cyl17, cyl18, box })
                      .makeShared();
  auto collider = RigidBodyCollider2::builder().withSurface(surfaceSet).makeShared();

  solver->setCollider(collider);

  // Print simulation info
  char basename[256];
  snprintf(basename, sizeof(basename), "info.txt");
  std::string filename = pystring::os::path::join(rootDir, basename);
  std::ofstream file(filename.c_str());
  if (file) {
    file << randomRadius1 << ' ' << randomRadius2 << ' ' << randomRadius3 << ' ' << randomRadius4 << ' ' << randomRadius5 << ' ' << randomRadius6
         << ' ' << randomRadius7 << ' ' << randomRadius8 << ' ' << randomRadius9 << ' ' << randomRadius10 << ' ' << randomRadius11 << ' '
         << randomRadius12 << ' ' << randomRadius13 << ' ' << randomRadius14 << ' ' << randomRadius15 << ' ' << randomRadius16 << ' '
         << randomRadius17 << ' ' << randomRadius18 << std::endl;
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
  int numberOfFrames = 200;
  double fps = 200.0;

  for (int i = 0; i != 10; i++) {

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