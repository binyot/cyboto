#ifndef BASECOMPONENT_H
#define BASECOMPONENT_H

#include<string>

/// we do not take components by gettrs, only their info
struct Component_info {

};

class BaseComponent
{
 public:
  BaseComponent();
};

class ServoMotor: public BaseComponent {
 public:
  ServoMotor(std::string_view name);
  /// duration is const and atomic.
  /// This func must be called periodically
  /// sign depends on direction
  void Rotate(double rotation_speed);
  const std::string& name() { return component_name_; }
 private:
  const std::string component_name_;
  double current_angle_;
  double max_angle_;
  double min_angle_;
};


#endif // BASECOMPONENT_H
