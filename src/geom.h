#ifndef GEOM_H
#define GEOM_H


#include <limits>
#include <utility>
#include <assert.h>

namespace geom { //TODO bad name

  template<typename ValueType>
  bool IsInRange(ValueType value, std::pair<ValueType, ValueType> bounds) {
    assert(bounds.first < bounds.second
           && "second value must be bigger or equal to the first one");
    return (value >= bounds.first) &&
           (value <= bounds.second);
  }
}

#endif // GEOM_H
