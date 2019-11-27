/*
 * TailMotor.h
 * Copyright (C) 2019 azurata
 */
#pragma once
#include "ev3api.h"
#include "Port.h"
#include "Motor.h"

using namespace ev3api;

class TailMotor
{
private:
  Motor* motor;
public:
  TailMotor(ePortM port);
  void setAngle(signed int angle);
  void fixAngle();
  void unfixAngle();
};
