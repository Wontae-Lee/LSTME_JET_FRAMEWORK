#pragma once
#include <jet/jet.h>
class MyPhysicsSolver : public jet::PhysicsAnimation
{
  public:
    MyPhysicsSolver();
    virtual ~MyPhysicsSolver();

  protected:
    void onInitialize() override;
    void onAdvanceTimeStep(double timeIntervalInSeconds) override;
};
