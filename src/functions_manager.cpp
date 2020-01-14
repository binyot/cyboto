#include "functions_manager.h"
#include "consts.h"

FunctionsManager::FunctionsManager() {
  PhysicalComponentsManager::getManager(); //init
}

bool FunctionsManager::CallFunction(FunctionSignature func_signature) {
  auto needed_function = function_map_.find(func_signature.FuncName());
  if (needed_function == function_map_.end())
    return false;
  else
    // theread safety
    AddActiveFunction(static_cast<FunctionBasement*>(
                        new StandartFunction(needed_function->second)));
  return true;
}

