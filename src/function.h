#ifndef FUNCTIONBASEMENT_H
#define FUNCTIONBASEMENT_H

#include <string>

class FunctionBasement
{
 public:
  FunctionBasement();
};

class BasicFunction : public FunctionBasement {
 public:
  BasicFunction(const std::string& target_component_);
  const std::string& target_component() { return target_component_; }
 private:
  const std::string target_component_;
};

#endif // FUNCTIONBASEMENT_H
