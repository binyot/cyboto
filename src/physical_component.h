#ifndef PHYSICALCOMPONENT_H
#define PHYSICALCOMPONENT_H

#include<string>

#include"consts.h"

/// we do not take components by gettrs, only their info
struct Component_info {

};

class PhysicalComponent
{
 public:
  PhysicalComponent();
};

class ServoMotor: public PhysicalComponent {
 public:
  ServoMotor(std::string_view name);
  /// duration is const and atomic.
  /// This func must be called periodically
  /// sign depends on direction
  void Rotate(double rotation_speed);
  const std::string& name() { return component_name_; }
 private:
  const std::string component_name_;
  double current_angle_ = 0;
  double max_angle_;
  double min_angle_;
};


#endif // PHYSICALCOMPONENT_H
