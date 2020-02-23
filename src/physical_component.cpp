#include <fstream>

#include "physical_component.h"
#include "common.h"

bool PhysicalComponent::CallFunctiuon(FunctionSignature signature) {
  try {
    available_functions_.at(signature.FunctionName())(signature.Args());
  } catch(...){
    return false;
  }
  return true;
}

ServoMotor::ServoMotor(std::string_view name, RotationLimits rotation_limits)
  : PhysicalComponent(name) , rotation_limits_(rotation_limits) {
  assert(rotation_limits.first < rotation_limits.second
         && "second value must be bigger or equal to the first one");
  // to check default position with bounds
  Rotate(UnificatedArguments("0"));
  type_ = ComponentType::ServoMotor;
  available_functions_.emplace("Rotate", [=](UnificatedArguments args)
                                            {this->Rotate(args);});
}

// FIXME test version
void ServoMotor::Rotate(UnificatedArguments args) {
  double angular_speed = args.NextArgument<double>();
  double new_angle = current_angle_ + angular_speed * consts::atomic_time_value;
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
  std::cout << "Current angle: " << current_angle_ <<std::endl;
}

Leds::Leds(std::string_view name, const std::string &filename)
 : PhysicalComponent(name) {
  type_ = ComponentType::Leds;
  available_functions_.emplace("Set", [=](UnificatedArguments args) {this->Set(args);});
  stream_.open(filename, std::ios_base::in);
  state_ = 0xFF;
}

void Leds::Set(UnificatedArguments args) {
  auto bit = args.NextArgument<int>();
  auto val = args.NextArgument<int>();
  auto old_state = state_;
  state_ &= ~(~val << bit);
}