#include "functions_manager.h"
#include "consts.h"

FunctionsManager::FunctionsManager() {
  PhysicalComponentsManager::getManager(); //init
  //test
  CallFunction({"ExampleRotate3Motors@1@-0.03@3@0.03@5@0.02"});
}

bool FunctionsManager::CallFunction(FunctionSignature func_signature) {
  // TODO check if function exists
  AddActiveFunction(static_cast<FunctionBasement*>(functions_.GetFunction(func_signature)));
  return true;
}

void FunctionsManager::HandleFunction(std::unique_ptr<
                                          FunctionBasement>& function) {
  if (auto phys_func = dynamic_cast<PhysicalFunction*>(function.get())) {
    physical_manager_().AddActiveFunction(phys_func); // TODO not safe
    assert(false && "physical function not in physical manager");
  } else if (auto std_func = dynamic_cast<StandartFunction*>(function.get())) {
    if (std_func->status() == FunctionStatus::NotActivated) {
      for (auto child_func : std_func->GetBodyFunctions())
        physical_manager_().AddActiveFunction(child_func);
      std::cout << "base function body added" << std::endl;
    }
  }
}

