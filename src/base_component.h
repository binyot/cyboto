#ifndef BASECOMPONENT_H
#define BASECOMPONENT_H

#include <string>
#include <vector>
#include <functional>
#include <map>

#include "consts.h"
#include "parsers.h"

class Core;

class BaseComponent
{
 public:
  using FunctionCall = std::pair<std::string, FunctionSignature>; //
  using FunctionCalls = std::vector<FunctionCall>;
  using FunctionsForUser
        = std::map<FunctionSignature::FunctionName,
                   std::function<FunctionCalls(FunctionSignature::FunctionArgs)>>;

  /// parse signature and call needed function
  virtual bool CallFunction(FunctionSignature func_signature);
  std::vector<std::string> AvailableFunctions();
  static void SetCore(Core* core) { core_ = core; }
 protected:
  FunctionsForUser functions_for_user_;
  static Core* core_;
};

#endif // BASECOMPONENT_H
