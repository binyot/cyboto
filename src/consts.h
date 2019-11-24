#ifndef CONSTS_H
#define CONSTS_H

#include <limits>

namespace consts {
  static const double undefined_double = std::numeric_limits<double>::max() - 10/*to be not ecual to max*/;
  static const double atomic_time_value = 100; //ms smallest unit of time, each base component func must durate that value.
};


#endif // CONSTS_H
