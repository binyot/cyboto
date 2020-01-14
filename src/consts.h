#ifndef CONSTS_H
#define CONSTS_H

#include <limits>
#include <string>
#include <vector>
#include <assert.h>

namespace consts {
  static constexpr double undefined_double = std::numeric_limits<double>::max();
  /// ms smallest unit of time, each base component func must durate that value.
  static constexpr unsigned int atomic_time_value =100;
  static constexpr char function_manager_name[] = "function manager";
  static constexpr char argument_separator[] = "@";
};


#endif // CONSTS_H
