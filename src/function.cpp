#include "function.h"

#include <iostream>

// not so much(

FunctionBasement::Events FunctionBasement::ReceiveEvents() {
  auto buffer = event_pool_;
  event_pool_.clear();
  return buffer;
}

void PhysicalFunction::FunctionCalled() {
  left_lifetime_ -= consts::atomic_time_value;
  if (left_lifetime_ <= 0) {
      need_to_delete_ = true;
      event_pool_.push_back("Function finished");
  }
}
