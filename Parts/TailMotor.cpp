/*
 * TailMotor.cpp
 * Copyright (C) 2019 azurata
 */
#include "TailMotor.h"
#define P_GAIN 2.5F
#define PWM_ABS_MAX 60

using namespace ev3api;

TailMotor::TailMotor(ePortM port)
{
  motor = new Motor(port);
  motor->reset();
}

void TailMotor::setAngle(signed int angle)
{
  signed int pwm = (signed int)((angle - motor->getCount())*P_GAIN);
  if (pwm > PWM_ABS_MAX)
  {
    pwm = PWM_ABS_MAX;
  }
  else if (pwm < -PWM_ABS_MAX)
  {
    pwm = -PWM_ABS_MAX;
  }
  if (pwm == 0)
  {
    motor->stop();
  }
  else
  {
    motor->setPWM(pwm);
  }
}

void TailMotor::fixAngle()
{
  motor->setPWM(0);
  motor->setBrake(true);
}

void TailMotor::unfixAngle()
{
  motor->setBrake(false);
}
