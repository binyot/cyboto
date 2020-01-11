#ifndef FUNCTIONBASEMENT_H
#define FUNCTIONBASEMENT_H

#include <string>

#include "parsers.h"

class FunctionBasement
{
 public:
};

class PhysicalFunction : public FunctionBasement {
 public:
  PhysicalFunction(const std::string& target_component,
                   FunctionSignature function_signature)
    : target_component_(target_component),
      function_signature_(function_signature) {}
  const std::string& target_component() const { return target_component_; }
  FunctionSignature function_signature() { return function_signature_; }
 private:
  const std::string target_component_;
  FunctionSignature function_signature_;
};

class StandartFunction : public FunctionBasement {

};

#endif // FUNCTIONBASEMENT_H
