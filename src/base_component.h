#ifndef BASECOMPONENT_H
#define BASECOMPONENT_H


class BaseComponent
{
 public:
  BaseComponent();
};

class ServoMotor: public BaseComponent {
 public:
  ServoMotor();
 private:
  double current_angle_;
  double max_angle_;
  double min_angle_;
};


#endif // BASECOMPONENT_H
