#include "functions_manager.h"
#include "consts.h"

//std::thread FunctionsManager::loop_
//    = std::thread(FunctionsManager::ProcessActiveFunctions,
//                  consts::atomic_time_value /*ms*/);

FunctionsManager::FunctionsManager() {
  call_loop_ = std::thread(&FunctionsManager::ProcessActiveFunctions,
                           this, consts::atomic_time_value /*ms*/);
}

bool FunctionsManager::CallFunction(FunctionSignature func_signature) {
  auto needed_function = function_map_.find(func_signature.GetFunctionName());
  if (needed_function == function_map_.end())
    return false;
  else
    // theread safety
    active_functions_.push_back(StandartFunction(needed_function->second));
}

void FunctionsManager::ProcessActiveFunctions(const unsigned int update_interval_ms) {
  const auto wait_duration = std::chrono::milliseconds(update_interval_ms);
  while(true) {

    std::this_thread::sleep_for(wait_duration);
  }
}
