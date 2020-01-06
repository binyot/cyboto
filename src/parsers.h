#ifndef FUNCTIONSIGNATURE_H
#define FUNCTIONSIGNATURE_H

#include <string>
#include <initializer_list>

#include "consts.h"

class FunctionSignature
{
 public:
  using FunctionArgs = std::string;
  using FunctionName = std::string; //TODO think about implementation

  FunctionSignature(std::string input) : raw_input_(input) {}
  FunctionName GetFunctionName() { return raw_input_; }
  FunctionArgs GetArgs() { static_assert("not implemented"); return "";}
 private:
  std::string raw_input_;
};

#endif // FUNCTIONSIGNATURE_H
