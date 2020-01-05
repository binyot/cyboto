#include "physical_components_manager.h"
#include <ctime>
#include <iostream>
#include <chrono>

std::thread PhysicalComponentsManager::loop_
    = std::thread(PhysicalComponentsManager::test_event_loop,
                  consts::atomic_time_value /*ms*/);

/// inialization of all basic (physical) components
PhysicalComponentsManager::PhysicalComponentsManager() {
  

}


void PhysicalComponentsManager::test_event_loop(const unsigned int update_interval_ms) {
  const auto wait_duration = std::chrono::milliseconds(update_interval_ms);
  while(true) {
    time_t my_time = time(NULL);
    std::cout << "loop called at " << ctime(&my_time) << std::endl;
    std::this_thread::sleep_for(wait_duration);
  }
}

