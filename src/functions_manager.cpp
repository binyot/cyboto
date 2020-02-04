#include "functions_manager.h"
#include "consts.h"

FunctionsManager::FunctionsManager() {
  PhysicalComponentsManager::getManager(); //init
  FillFunctionMapWithDefaulFunctions();
}

bool FunctionsManager::CallFunction(FunctionSignature func_signature) {
  auto needed_function = function_map_.find(func_signature.FunctionName());
  if (needed_function == function_map_.end())
    return false;
  else
    // theread safety
    AddActiveFunction(static_cast<FunctionBasement*>(
                        new StandartFunction(needed_function->second)));
  return true;
}

void FunctionsManager::HandleFunction(std::unique_ptr<
                                          FunctionBasement>& function) {
  if (auto phys_func = dynamic_cast<PhysicalFunction*>(function.get())) {
    physical_manager_().AddActiveFunction(phys_func); // TODO not safe
  }

}

void FunctionsManager::FillFunctionMapWithDefaulFunctions() {

}
