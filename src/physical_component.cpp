#include "physical_component.h"


PhysicalComponent::PhysicalComponent()
{

}

// FIXME test version
void ServoMotor::Rotate(double rotation_speed) {
  current_angle_ += rotation_speed;
}
