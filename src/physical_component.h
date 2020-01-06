#ifndef PHYSICALCOMPONENT_H
#define PHYSICALCOMPONENT_H

#include<string>

#include"consts.h"

/// we do not take components by gettrs, only their info
struct Component_info {

};

enum class ComponentType {
  Basic,
  ServoMotor
};

class PhysicalComponent
{
 public:
  PhysicalComponent() : type_(ComponentType::Basic) {}
 protected:
  ComponentType type_;
};

class ServoMotor: public PhysicalComponent {
  using RotationLimits = std::pair<double, double>; // min max

 public:
  ServoMotor(std::string_view name, RotationLimits rotation_limits);
  /// duration is const and atomic.
  /// This func must be called periodically
  /// sign depends on direction
  void Rotate(double rotation_speed);
  void PrintAllInfo();
  const std::string& name() { return component_name_; }
 private:
  const std::string component_name_;
  double current_angle_ = 0;
  RotationLimits rotation_limits_;
};


#endif // PHYSICALCOMPONENT_H
