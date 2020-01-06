#ifndef BASECOMPONENTMANAGER_H
#define BASECOMPONENTMANAGER_H

#include <map>
#include <string>
#include <memory>
#include <thread>
#include <vector>

#include "base_component.h"
#include "consts.h"
#include "physical_component.h"
#include "function.h"

class PhysicalComponentsManager : public BaseComponent
{
 public:
  static PhysicalComponentsManager& getManager() { //singleton
    static PhysicalComponentsManager manager;
    return manager;
  }
  PhysicalComponentsManager(PhysicalComponentsManager const&) = delete;
  void ProcessActiveFunctions(const unsigned int update_interval_ms);
  void operator=(PhysicalComponentsManager const&) = delete;
  static void test_event_loop(const unsigned int update_interval_ms);
 private:
  PhysicalComponentsManager();
  static std::thread test_loop_; //TODO delete
  std::thread call_loop_;
  std::map<std::string,  PhysicalComponent> component_map_;
  std::vector<PhysicalFunction> active_functions_;
};

#endif // BASECOMPONENTMANAGER_H
