#include "base_component.h"

#include <chrono>
#include <mutex>
#include <iterator>
#include <iostream>
#include <algorithm>

Core* BaseComponent::core_ = nullptr;
std::mutex active_functions_pool_mutex;

bool BaseComponent::CallFunction(FunctionSignature func_signature) {
  assert(false && "not implemented"); return false;
}

EventsManager::EventsManager() {
    call_loop_ = std::thread(&EventsManager::ProcessActiveFunctions, this);
}

void EventsManager::MoveFunctionsPoolToMainArray() {
  const std::lock_guard<std::mutex> lock(active_functions_pool_mutex);
  if(!active_functions_pool_.empty()) {
    active_functions_.insert(active_functions_.end(),
                             std::make_move_iterator(active_functions_pool_.begin()),
                             std::make_move_iterator(active_functions_pool_.end()));
    active_functions_pool_.clear();
  }
}

void EventsManager::ProcessActiveFunctions() {
  while(true) {
    // TODO compute spent time and subtruct from atomic_time_value
    std::this_thread::sleep_for(std::chrono::milliseconds(consts::atomic_time_value));
    MoveFunctionsPoolToMainArray();
    auto function_handler = [this](auto & function) {
        function->FunctionCalled();
        HandleFunction(function);
        return function->need_to_delete();
    };
    active_functions_.erase(std::remove_if(active_functions_.begin(),
                                           active_functions_.end(),
                                           function_handler),
                            active_functions_.end());
  }
}

void EventsManager::AddActiveFunction(std::unique_ptr<FunctionBasement> & function) {
  const std::lock_guard<std::mutex> lock(active_functions_pool_mutex);
  active_functions_pool_.emplace_back(std::move(function));
}

void EventsManager::AddActiveFunction(FunctionBasement* function) {
  const std::lock_guard<std::mutex> lock(active_functions_pool_mutex);
  active_functions_pool_.emplace_back(std::unique_ptr<FunctionBasement>(function));
}

void EventsManager::HandleFunction(std::unique_ptr<FunctionBasement> & function) {
  assert(false && "This function must be implemented in child class");
}
