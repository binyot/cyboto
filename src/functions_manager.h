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

class FunctionsManager : public EventsManager
{
 public:
  FunctionsManager();
  bool AddFunction(); //TODO parse and add new func type
  virtual bool CallFunction(FunctionSignature func_signature) override;
 private:
  std::map<std::string, StandartFunction> function_map_;
};

#endif // FUNCTIONSMANAGER_H
