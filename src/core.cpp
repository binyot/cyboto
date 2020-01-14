#include "core.h"
#include <iostream>

Core::Core() {
  BaseComponent::SetCore(this);
  component_map_.emplace(consts::function_manager_name, &FunctionsManager::getManager());

}

void Core::TestSignal(std::string func_name) {
  if (func_name == "test") {
    std::cout << "Test func called, smth done... (not implemented)" << std::endl;
  } else {
    std::cout << "Test func called, to call some logic"
                 " send 'test' as string argument. Current agrument is: '"
              << func_name << "'." << std::endl;
  }
}
