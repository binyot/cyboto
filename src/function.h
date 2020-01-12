#ifndef FUNCTIONBASEMENT_H
#define FUNCTIONBASEMENT_H

#include <string>

#include "parsers.h"

class FunctionBasement
{
 public:
  using Event = std::string;
  using Events = std::vector<Event>;

  virtual void FunctionCalled() {};
  Events ReceiveEvents();
  bool need_to_delete() { return need_to_delete_; }
 protected:
  Events event_pool_;
  bool need_to_delete_ = false;
};

class PhysicalFunction : public FunctionBasement {
 public:
  PhysicalFunction(const std::string& target_component,
                   FunctionSignature function_signature,
                   int left_lifetime = consts::atomic_time_value)
    : target_component_(target_component),
      function_signature_(function_signature),
      left_lifetime_(left_lifetime) {}
  virtual void FunctionCalled() override;
  const std::string& target_component() const { return target_component_; }
  FunctionSignature& function_signature() { return function_signature_; }
 private:
  int left_lifetime_;
  const std::string target_component_;
  FunctionSignature function_signature_;
};

class StandartFunction : public FunctionBasement {

};

#endif // FUNCTIONBASEMENT_H
