#ifndef CONSTS_H
#define CONSTS_H

#include <limits>
#include <string>

namespace consts {
  static constexpr double undefined_double = std::numeric_limits<double>::max();
  /// ms smallest unit of time, each base component func must durate that value.
  static constexpr double atomic_time_value = 500;
  static constexpr char function_manager_name[] = "function manager";
};


#endif // CONSTS_H
