#include "function.h"

#include <iostream>

int FunctionBasement::id_setter_ = 0;

FunctionBasement::FunctionBasement(FunctionType type) : type_(type){
  id_ = id_setter_;
}

FunctionBasement::Events FunctionBasement::ReceiveEvents() {
  auto buffer = event_pool_;
  event_pool_.clear();
  return buffer;
}

void FunctionBasement::FunctionCalled() {
  assert(false && "must be called child function");
}

void PhysicalFunction::FunctionCalled() {
  left_lifetime_ -= consts::atomic_time_value;
  if (left_lifetime_ <= 0) {
      need_to_delete_ = true;
      event_pool_.push_back(EventSignature(
                              std::string(consts::function_finished) + "@1"));
  }
}
