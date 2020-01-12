#include "function.h"

#include <iostream>

// not so much(

void PhysicalFunction::FunctionCalled() {
  left_lifetime_ -= consts::atomic_time_value;
  if (left_lifetime_ <= 0) {
      need_to_delete_ = true;
  }
}
