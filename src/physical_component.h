#ifndef PHYSICALCOMPONENT_H
#define PHYSICALCOMPONENT_H

#include <fstream>

#include <string>
#include <map>
#include <functional>
#include <iostream>

#include "consts.h"
#include "parsers.h"

/// we do not take components by gettrs, only their info
struct Component_info {

};

enum class ComponentType {
  Basic,
  ServoMotor,
  Leds
};

class PhysicalComponent
{
 public:
  PhysicalComponent(std::string_view name)
    : type_(ComponentType::Basic), component_name_(name) {}
  bool CallFunctiuon(FunctionSignature signature);
  virtual void PrintAllInfo() {
    std::cout << "Base PhysicalComponent info" << std::endl;};
  const std::string& name() const { return component_name_; };
  ComponentType type() const { return type_; }
 protected:
  std::map<std::string,
           std::function<void(UnificatedArguments)>> available_functions_;
  ComponentType type_;
  const std::string component_name_;
  //TODO static memory map (PhysicalComponents must be hardcoded)
};

class ServoMotor: public PhysicalComponent {
  using RotationLimits = std::pair<double, double>; // min max

 public:
  ServoMotor(std::string_view name, RotationLimits rotation_limits);
  /// duration is const and atomic.
  /// This func must be called periodically
  /// sign depends on direction
  void Rotate(UnificatedArguments args);
  virtual void PrintAllInfo() override;
 private:
  double current_angle_ = 0;
  RotationLimits rotation_limits_;
};

class Leds: public PhysicalComponent
{
 public:
  Leds(std::string_view name, const std::string &filename="/dev/custom_leds");
  void Set(UnificatedArguments args);
 private:
  std::ofstream stream_;
  size_t state_;
};

#endif // PHYSICALCOMPONENT_H
