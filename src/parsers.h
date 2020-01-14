#ifndef FUNCTIONSIGNATURE_H
#define FUNCTIONSIGNATURE_H

#include <string>
#include <initializer_list>

#include "consts.h"

class UnificatedArguments {
 public:
  UnificatedArguments(std::string raw_arguments)
    : raw_arguments_(raw_arguments) {}
// TODO make template!
 template<typename T>
 T NextArgument();

 std::string raw_arguments() { return raw_arguments_; }
 private:
  // separation by '@' this symbol not allowoded
  std::string raw_arguments_;
};

class FunctionSignature {
 public:
  using FunctionName = std::string; //TODO think about implementation

  FunctionSignature(std::string input);
  FunctionName FuncName() { return func_name_; }
  UnificatedArguments Args() { return func_args_;}
 private:
  FunctionName func_name_;
  UnificatedArguments func_args_;
};

template<typename T>
 T NextArgument() {
  assert(false && "invalid return type");
}
template<>
double UnificatedArguments::NextArgument();
template<>
int UnificatedArguments::NextArgument();
template<>
std::string UnificatedArguments::NextArgument();

#endif // FUNCTIONSIGNATURE_H
