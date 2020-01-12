#include "physical_components_manager.h"

#include <ctime>
#include <iostream>
#include <chrono>
#include <mutex>

/// inialization of all basic (physical) components
PhysicalComponentsManager::PhysicalComponentsManager() {
  component_map_.emplace("servo_1", new ServoMotor("servo_1", {-90, 90}));
  component_map_.emplace("servo_2", new ServoMotor("servo_2", {-90, 180}));
  component_map_.emplace("servo_3", new ServoMotor("servo_3", {0, 270}));
  AddActiveFunction(new PhysicalFunction("servo_3", FunctionSignature("Rotate@7@"),
                                         consts::atomic_time_value * 3));
  AddActiveFunction(new PhysicalFunction("servo_1", FunctionSignature("Rotate@-1@"),
                                         consts::atomic_time_value * 10));
  std::cout << "PhysicalComponentsManager created" << std::endl;
}

void PhysicalComponentsManager::HandleFunction(std::unique_ptr<FunctionBasement>& function) {
  std::cout << "HandleFunction started" << std::endl;
  const auto physical_function = static_cast<PhysicalFunction*>(function.get());
  assert(physical_function && "wrong function type");
  const auto component = component_map_.find(physical_function->target_component());
  assert(component != component_map_.end() && "component does not exist");
  component->second->CallFunctiuon(physical_function->function_signature());
  component->second->PrintAllInfo();
}


