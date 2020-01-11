#ifndef FUNCTIONSIGNATURE_H
#define FUNCTIONSIGNATURE_H

#include <string>
#include <initializer_list>

#include "consts.h"

class UnificatedArguments {
 public:
  UnificatedArguments(std::string raw_arguments) : raw_arguments_(raw_arguments) {}
// TODO make template!
 template<typename T>
 void NextArgument(T& result);
 std::string raw_arguments() { return raw_arguments_; }
 private:
  // TODO improve parsing
  // separation by '@' this symbol not allowoded
  // in string data, input string must end with '@'
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
 void NextArgument(T& result) {
  assert(false && "invalid return type");
}


#endif // FUNCTIONSIGNATURE_H
