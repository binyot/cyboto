#include "physical_components_manager.h"

#include <ctime>
#include <iostream>
#include <chrono>
#include <mutex>

std::thread PhysicalComponentsManager::test_loop_
    = std::thread(PhysicalComponentsManager::test_event_loop,
                  consts::atomic_time_value /*ms*/);


/// inialization of all basic (physical) components
PhysicalComponentsManager::PhysicalComponentsManager() {
  component_map_.emplace("servo_1", ServoMotor("servo_1", {-90, 90}));
  component_map_.emplace("servo_1", ServoMotor("servo_2", {-90, 180}));
  component_map_.emplace("servo_1", ServoMotor("servo_3", {0, 270}));
}

void PhysicalComponentsManager::test_event_loop(const unsigned int update_interval_ms) {
  const auto wait_duration = std::chrono::milliseconds(update_interval_ms);
  while(true) {
    time_t my_time = time(NULL);
    std::cout << "test_event_loop loop called at " << ctime(&my_time) << std::endl;
    std::this_thread::sleep_for(wait_duration);
  }
}


