#ifndef FUNCTIONBASEMENT_H
#define FUNCTIONBASEMENT_H

#include <string>

class FunctionBasement
{
 public:
  FunctionBasement();
};

class PhysicalFunction : public FunctionBasement {
 public:
  PhysicalFunction(const std::string& target_component_);
  const std::string& target_component() { return target_component_; }
 private:
  const std::string target_component_;
};

class StandartFunction : public FunctionBasement {

};

#endif // FUNCTIONBASEMENT_H
