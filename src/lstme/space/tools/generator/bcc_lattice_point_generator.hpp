//
// Created by LSTME on 2022-09-22.
//

#ifndef LSTME_BCC_LATTICE_POINT_GENERATOR_HPP
#define LSTME_BCC_LATTICE_POINT_GENERATOR_HPP


#include <point_generator3.hpp>

namespace lstme {

//!
//! \brief Body-centered lattice points generator.
//!
//! \see http://en.wikipedia.org/wiki/Cubic_crystal_system
//!      http://mathworld.wolfram.com/CubicClosePacking.html
//!
class BccLatticePointGenerator final : public PointGenerator3 {
public:
  //!
  //! \brief Invokes \p callback function for each BCC-lattice points inside
  //! \p boundingBox.
  //!
  //! This function iterates every BCC-lattice points inside \p boundingBox
  //! where \p spacing is the size of the unit cell of BCC structure.
  //!
  void forEachPoint(
    const BoundingBox3D& boundingBox,
    double spacing,
    const std::function<bool(const Vector3D&)>& callback) const override;
};

//! Shared pointer type for the BccLatticePointGenerator.
typedef std::shared_ptr<BccLatticePointGenerator> BccLatticePointGeneratorPtr;

}  // namespace lstme


#endif // LSTME_BCC_LATTICE_POINT_GENERATOR_HPP
