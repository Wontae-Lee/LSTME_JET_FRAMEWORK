//
// Created by LSTME on 2022-09-22.
//

#ifndef LSTME_APIC_SOLVER2_HPP
#define LSTME_APIC_SOLVER2_HPP


#include <pic_solver2.hpp>

namespace lstme {
 
//!
//! \brief 2-D Affine Particle-in-Cell (APIC) implementation
//!
//! This class implements 2-D Affine Particle-in-Cell (APIC) solver from the
//! SIGGRAPH paper, Jiang 2015.
//!
//! \see Jiang, Chenfanfu, et al. "The affine particle-in-cell method."
//!      ACM Transactions on Graphics (TOG) 34.4 (2015): 51.
//!
class ApicSolver2 : public PicSolver2 {
public:
  class Builder;

  //! Default constructor.
  ApicSolver2();

  //! Constructs solver with initial grid size.
  ApicSolver2(
    const Size2& resolution,
    const Vector2D& gridSpacing,
    const Vector2D& gridOrigin);

  //! Default destructor.
  virtual ~ApicSolver2();

  //! Returns builder fox ApicSolver2.
  static Builder builder();

protected:
  //! Transfers velocity field from particles to grids.
  void transferFromParticlesToGrids() override;

  //! Transfers velocity field from grids to particles.
  void transferFromGridsToParticles() override;

private:
  Array1<Vector2D> _cX;
  Array1<Vector2D> _cY;
};

//! Shared pointer type for the ApicSolver2.
typedef std::shared_ptr<ApicSolver2> ApicSolver2Ptr;


//!
//! \brief Front-end to create ApicSolver2 objects step by step.
//!
class ApicSolver2::Builder final
  : public GridFluidSolverBuilderBase2<ApicSolver2::Builder> {
public:
  //! Builds ApicSolver2.
  ApicSolver2 build() const;

  //! Builds shared pointer of ApicSolver2 instance.
  ApicSolver2Ptr makeShared() const;
};

}  // namespace lstme



#endif // LSTME_APIC_SOLVER2_HPP
