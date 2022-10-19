//
// Created by LSTME on 2022-10-16.
//

#ifndef LSTME_FACTORY_HPP
#define LSTME_FACTORY_HPP

#include <point_neighbor_searcher2.hpp>
#include <point_neighbor_searcher3.hpp>
#include <scalar_grid2.hpp>
#include <scalar_grid3.hpp>
#include <string>
#include <vector_grid2.hpp>
#include <vector_grid3.hpp>


namespace lstme {

class Factory
{
public:
  static ScalarGrid2Ptr buildScalarGrid2(const std::string& name);

  static ScalarGrid3Ptr buildScalarGrid3(const std::string& name);

  static VectorGrid2Ptr buildVectorGrid2(const std::string& name);

  static VectorGrid3Ptr buildVectorGrid3(const std::string& name);

  static PointNeighborSearcher2Ptr buildPointNeighborSearcher2(
    const std::string& name);

  static PointNeighborSearcher3Ptr buildPointNeighborSearcher3(
    const std::string& name);
};

} // namespace lstme

#endif // LSTME_FACTORY_HPP
