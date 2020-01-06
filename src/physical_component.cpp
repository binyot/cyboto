#include "physical_component.h"

#include <iostream>

#include "geom.h"

ServoMotor::ServoMotor(std::string_view name, RotationLimits rotation_limits)
  : component_name_(name), rotation_limits_(rotation_limits) {
  assert(rotation_limits.first < rotation_limits.second
         && "second value must be bigger or equal to the first one");
  // to check default position with bounds
  Rotate(0);
  type_ = ComponentType::ServoMotor;
}

// FIXME test version
void ServoMotor::Rotate(double rotation_speed) {
  double new_angle = current_angle_ + rotation_speed;
  if (geom::IsInRange(new_angle, rotation_limits_)) {
    current_angle_ = new_angle;
  } else {
    new_angle > rotation_limits_.second ?
        current_angle_ = rotation_limits_.second :
        current_angle_ = rotation_limits_.first;
  }
}

void ServoMotor::PrintAllInfo() {
  std::cout << "ServoMotor name: " << component_name_ <<std::endl;
  std::cout << "current angle: " << current_angle_ <<std::endl;
}
