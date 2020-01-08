#include "functions_manager.h"
#include "consts.h"

FunctionsManager::FunctionsManager() {

}

bool FunctionsManager::CallFunction(FunctionSignature func_signature) {
  auto needed_function = function_map_.find(func_signature.GetFunctionName());
  if (needed_function == function_map_.end())
    return false;
  else
    // theread safety
    AddActiveFunction(static_cast<FunctionBasement*>(new StandartFunction(needed_function->second)));
}

