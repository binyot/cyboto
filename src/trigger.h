#ifndef BASICTRIGGER_H
#define BASICTRIGGER_H

#include "parsers.h"

/// base, should not be used
class BasicTrigger {
 public:
  BasicTrigger();
  bool Triggered() const { return state_; }
 private:
  bool state_ = false;
  int time_since_triggered_ = 0; // or we need trigger time?
};

/// counts calls of function, alse used as a timer
template<typename T>
class CountTrigger : public BasicTrigger {
 public:
  CountTrigger();
 private:
  T value_;
};

template<typename T>
class ComparisonTrigger : public BasicTrigger {
 public:
  // TODO use it as lambda
  enum class ComparisonType {
    More,
    MoreOrEqual,
    Less,
    LessOrEqual,
    Equal
  };

  ComparisonTrigger();
 private:
  ComparisonType comparison_type_;
  T compared_value_;
};

class ComplexTrigger : public BasicTrigger {
 public:
  enum class OperationType {
    And,
    Or
  };

  ComplexTrigger();
 private:
  OperationType operation_type_;
};

/// can call functions
class FunctionTrigger : public BasicTrigger {
 public:
  FunctionTrigger();
 private:
  const BasicTrigger* trigger;
};

#endif // BASICTRIGGER_H
