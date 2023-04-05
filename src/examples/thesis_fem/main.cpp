// Copyright (c) 2018 Doyub Kim
//
// I am making my contributions/submissions to this project solely in my
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

//
//
// 잠정중단 Finite Element method 였음.
//
//

#include <clara.hpp>
#include <example_utils/clara_utils.h>
#include <jet/jet.h>
#include <pystring/pystring.h>
#include <sys/stat.h>

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#define APP_NAME "thesis_fem"

using namespace jet;

void
saveResults(const GridSystemData2Ptr& gridData, const std::string& rootDir, int frameCnt)
{
  auto scalarData = gridData->scalarDataAt(0);
  auto check = scalarData->dataAccessor().data();
  printf("asfdasdfasdf");



}

void
printInfo(const LevelSetLiquidSolver2Ptr& solver)
{
  auto grids = solver->gridSystemData();
  Size2 resolution = grids->resolution();
  BoundingBox2D domain = grids->boundingBox();
  Vector2D gridSpacing = grids->gridSpacing();

  printf("Resolution: %zu x %zu x \n", resolution.x, resolution.y);
  printf("Domain: [%f, %f] x [%f, %f]\n", domain.lowerCorner.x, domain.lowerCorner.y, domain.upperCorner.x, domain.upperCorner.y);
  printf("Grid spacing: [%f, %f]\n", gridSpacing.x, gridSpacing.y);
}

void
runSimulation(const std::string& rootDir, const LevelSetLiquidSolver2Ptr& solver, int numberOfFrames, double fps)
{

  auto grids = solver->gridSystemData();

  for (Frame frame(0, 1.0 / fps); frame.index < numberOfFrames; ++frame) {
    solver->update(frame);
    saveResults(grids,rootDir,frame.index);

  }
}

// 2D Dam-breaking example
void
runExample(const std::string& rootDir, size_t resX, int numberOfFrames, double fps)
{
  // Build solver
  auto solver = LevelSetLiquidSolver2::builder().withResolution({ 3 * resX, 3 * resX }).withDomainSizeX(3.0).makeShared();
  solver->setUseCompressedLinearSystem(true);

  auto grids = solver->gridSystemData();
  BoundingBox2D domain = grids->boundingBox();

  // Build emitter
  auto box1 = Box2::builder().withLowerCorner({ -0.5, -0.5 }).withUpperCorner({ 0.5, 0.75 }).makeShared();
  auto box2 = Box2::builder().withLowerCorner({ 2.5, -0.5 }).withUpperCorner({ 3.5, 0.75 }).makeShared();
  auto boxSet = ImplicitSurfaceSet2::builder().withExplicitSurfaces({ box1, box2 }).makeShared();
  auto emitter = VolumeGridEmitter2::builder().withSourceRegion(boxSet).makeShared();

  solver->setEmitter(emitter);
  emitter->addSignedDistanceTarget(solver->signedDistanceField());

  // Build collider

  // Print simulation info
  printf("Running example 2 (dam-breaking)\n");
  printInfo(solver);

  // Run simulation
  runSimulation(rootDir, solver, numberOfFrames, fps);
}

int
main(int argc, char* argv[])
{
  bool showHelp = false;
  size_t resX = 50;
  int numberOfFrames = 100;
  double fps = 60.0;
  int exampleNum = 1;
  std::string logFilename = APP_NAME ".log";
  std::string outputDir = APP_NAME "_output";

  runExample(outputDir, resX, numberOfFrames, fps);

  return EXIT_SUCCESS;
}
