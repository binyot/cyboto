#include "base_function.h"

#include <iostream>

int FunctionBasement::id_setter_ = 0;

FunctionBasement::FunctionBasement(FunctionType type,
                                   FunctionBasement* parent)
  : type_(type), parent_(parent) {
  id_ = id_setter_++;
}

FunctionBasement::Events FunctionBasement::ReceiveEvents() {
  auto buffer = event_pool_;
  event_pool_.clear();
  return buffer;
}

void FunctionBasement::DeleteFunction() {
  status_ = FunctionStatus::finished;
  need_to_delete_ = true;
  if (parent_)
    parent_->ChildFunctionStatusUpdated(this);
}

void FunctionBasement::FunctionCalled() {
  assert(false && "must be called child function");
}

void FunctionBasement::ChildFunctionStatusUpdated(const FunctionBasement * /*child_func*/) {
    assert(false && "must be called child function");
}

PhysicalFunction::PhysicalFunction(UnificatedArguments&& target_components,
                                   FunctionBasement* parent)
  : FunctionBasement(FunctionType::Physical, parent)
  , target_component_(target_components.NextArgument<std::string>())
  , left_lifetime_(target_components.NextArgument<int>())
  , function_signature_(target_components.raw_arguments()) {
  is_initialized_ = true;
}

void PhysicalFunction::FunctionCalled() {
  left_lifetime_ -= consts::atomic_time_value;
  if (left_lifetime_ <= 0) {
      DeleteFunction();
      event_pool_.push_back(EventSignature(
                              std::string(consts::function_finished) + "@1"));
  }
}

PhysicalFunction PhysicalFunction::Timer(int life_units,
                                         FunctionBasement* parent) {
  return PhysicalFunction(ToFuncArgs(consts::fake_component,
                                     life_units * consts::atomic_time_value),
                          parent);
}

bool StandartFunction::check_state() {
  return static_trigger_.Triggered();
}

void StandartFunction::FunctionCalled() {

}

FunctionBasement::Functions StandartFunction::GetBodyFunctions() {
  FunctionBasement::Functions result;
  if(status() == FunctionStatus::NotActivated) {
    status_ = FunctionStatus::Running;
    result = body_funcs_;
  }
  return result;
}
