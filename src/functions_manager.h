#ifndef FUNCTIONSMANAGER_H
#define FUNCTIONSMANAGER_H

#include <map>
#include <string>
#include <memory>
#include <thread>
#include <vector>
#include <iostream>

#include "base_component.h"
#include "function.h"
#include "parsers.h"
#include "physical_components_manager.h"

class FunctionsManager : public EventsManager
{
 public:
  static FunctionsManager& getManager() { //singleton
    static FunctionsManager manager;
    return manager;
  }
  FunctionsManager(FunctionsManager const&) = delete;
  void operator=(FunctionsManager const&) = delete;
  bool AddFunction(); //TODO parse and add new func type
  void SentEvents(FunctionBasement::Events events) {} //TODO
  virtual bool CallFunction(FunctionSignature func_signature) override;
 private:
  PhysicalComponentsManager& physical_manager_() {
    return PhysicalComponentsManager::getManager(); }
  FunctionsManager();
  std::map<std::string, StandartFunction> function_map_;
};

#endif // FUNCTIONSMANAGER_H
