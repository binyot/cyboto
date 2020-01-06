#ifndef FUNCTIONSMANAGER_H
#define FUNCTIONSMANAGER_H

#include <map>
#include <string>
#include <memory>
#include <thread>
#include <vector>

#include "base_component.h"
#include "function.h"
#include "parsers.h"

class FunctionsManager : public BaseComponent
{
 public:
  FunctionsManager();
  bool AddFunction(); //TODO
  virtual bool CallFunction(FunctionSignature func_signature) override;
  void ProcessActiveFunctions(const unsigned int update_interval_ms);
 private:
  std::thread call_loop_;
  std::vector<StandartFunction> active_functions_;
  std::map<std::string, StandartFunction> function_map_;
};

#endif // FUNCTIONSMANAGER_H
