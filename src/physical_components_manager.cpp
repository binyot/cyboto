#include "physical_components_manager.h"

#include <ctime>
#include <iostream>
#include <chrono>
#include <mutex>

std::map<std::string,  PhysicalComponent*> PhysicalComponentsManager::component_map_;

/// inialization of all basic (physical) components
PhysicalComponentsManager::PhysicalComponentsManager() {
  component_map_.emplace(phys_comp::servo_m1, new ServoMotor(phys_comp::servo_m1, {-90, 90}));
  component_map_.emplace(phys_comp::servo_m2, new ServoMotor(phys_comp::servo_m2, {-90, 180}));
  component_map_.emplace(phys_comp::servo_m3, new ServoMotor(phys_comp::servo_m3, {0, 270}));
  // test
//  AddActiveFunction(new PhysicalFunction(
//                        UnificatedArguments(phys_comp::servo_m3,
//                                            consts::atomic_time_value * 5,
//                                            "Rotate@0.07")));
//  AddActiveFunction(new PhysicalFunction(UnificatedArguments(phys_comp::servo_m2,
//                                                             consts::atomic_time_value * 2,
//                                                             "@Rotate@-0.1")));
  std::cout << "PhysicalComponentsManager created" << std::endl;
}

void PhysicalComponentsManager::HandleFunction(std::unique_ptr<FunctionBasement>& function) {
//  std::cout << "PhysicalComponentsManager: HandleFunction started" << std::endl;
  const auto physical_function = static_cast<PhysicalFunction*>(function.get());
  assert(physical_function && "wrong function type");
  const auto component = component_map_.find(physical_function->target_component());
  assert(component != component_map_.end() && "component does not exist");
  component->second->CallFunctiuon(physical_function->function_signature());
  component->second->PrintAllInfo();
  auto events = physical_function->ReceiveEvents();
  if (!events.empty())
    std::cout << "events receved, first one: "
              << events.front().GetEventAndSender().first << std::endl;
}


