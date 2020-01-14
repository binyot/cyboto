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

class PhysicalComponentsManager : public EventsManager
{
 public:
  static PhysicalComponentsManager& getManager() { //singleton
    static PhysicalComponentsManager manager;
    return manager;
  }
  PhysicalComponentsManager(PhysicalComponentsManager const&) = delete;
  void operator=(PhysicalComponentsManager const&) = delete;
  static void test_event_loop(const unsigned int update_interval_ms);
  virtual void HandleFunction(std::unique_ptr<FunctionBasement> & function) override;
 private:
  PhysicalComponentsManager();
  static std::map<std::string,  PhysicalComponent*> component_map_;
};

#endif // BASECOMPONENTMANAGER_H
