#include "base_component.h"

#include <chrono>
#include <mutex>
#include <iterator>

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
  active_functions_.insert(active_functions_.end(),
                           std::make_move_iterator(active_functions_pool_.begin()),
                           std::make_move_iterator(active_functions_pool_.end()));
}

void EventsManager::ProcessActiveFunctions() {
  while(true) {
    std::this_thread::sleep_for(std::chrono::milliseconds(consts::atomic_time_value));
    MoveFunctionsPoolToMainArray();
    for(auto & acative_function : active_functions_)
      HandleFunction(acative_function);
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
