#ifndef FUNCTIONBASEMENT_H
#define FUNCTIONBASEMENT_H

#include <string>

class FunctionBasement
{
 public:
};

class PhysicalFunction : public FunctionBasement {
 public:
  PhysicalFunction(const std::string& target_component)
    : target_component_(target_component) {}
  const std::string& target_component() const { return target_component_; }
 private:
  // const std::string target_component_; //do not works
  std::string target_component_;
};

class StandartFunction : public FunctionBasement {

};

#endif // FUNCTIONBASEMENT_H
