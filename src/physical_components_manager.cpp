#include "physical_components_manager.h"

#include <ctime>
#include <iostream>
#include <chrono>
#include <mutex>

//std::thread PhysicalComponentsManager::test_loop_
//    = std::thread(PhysicalComponentsManager::test_event_loop,
//                  consts::atomic_time_value /*ms*/);

void PhysicalComponentsManager::test_event_loop(const unsigned int update_interval_ms) {
  const auto wait_duration = std::chrono::milliseconds(update_interval_ms);
  while(true) {
    time_t my_time = time(NULL);
    std::cout << "test_event_loop loop called at " << ctime(&my_time) << std::endl;
    std::this_thread::sleep_for(wait_duration);
  }
}

/// inialization of all basic (physical) components
PhysicalComponentsManager::PhysicalComponentsManager() {
  component_map_.emplace("servo_1", new ServoMotor("servo_1", {-90, 90}));
  component_map_.emplace("servo_2", new ServoMotor("servo_2", {-90, 180}));
  component_map_.emplace("servo_3", new ServoMotor("servo_3", {0, 270}));
  std::string comp_name = "servo_2";
  AddActiveFunction(new PhysicalFunction(comp_name, FunctionSignature("Rotate@7@")));
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


