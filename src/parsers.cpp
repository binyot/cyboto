#include "parsers.h"

std::string NextRawArgument(std::string& raw_arguments) {
  std::string argument = "";
  const auto separator = raw_arguments.find(consts::argument_separator);
  if (separator == std::string::npos) {
    assert(false && "no mor arguments left");
  } else {
    argument = raw_arguments.substr(0, separator);
    raw_arguments = raw_arguments.substr(separator + 1 /*ignore separator*/);
  }
  return argument;
}

// full specialisation in cpp
template<>
void UnificatedArguments::NextArgument(int& result) {
  result = std::stoi(NextRawArgument(raw_arguments_));
}
template<>
void UnificatedArguments::NextArgument(double& result) {
  result = std::stod(NextRawArgument(raw_arguments_));
}
template<>
void UnificatedArguments::NextArgument(std::string& result) {
  result = NextRawArgument(raw_arguments_);
}

FunctionSignature::FunctionSignature(std::string input)
  : func_name_(NextRawArgument(input)), func_args_(input) {
}
