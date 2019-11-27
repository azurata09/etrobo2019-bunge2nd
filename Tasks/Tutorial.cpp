/*
 * Tutorial.cpp
 * Copyright (C) 2019 azurata
 */
#include "Tutorial.h"

using namespace ev3api;

void Tutorial::run()
{
  /* テールを上げる */
  int pwmL, pwmR;
  Utils::balancer->setCommand(0, 0);
  for(int angle = 88; angle >= 3; angle--)
  {
    Utils::tailMotor->setAngle(angle);
    Utils::balancer->update(
      Utils::gyroSensor->getAnglerVelocity(),
      Utils::motorR->getCount(),
      Utils::motorL->getCount(),
      ev3_battery_voltage_mV()
    );
    pwmL = Utils::balancer->getPwmLeft();
    pwmR = Utils::balancer->getPwmRight();
    Utils::motorL->setPWM(pwmL);
    Utils::motorR->setPWM(pwmR);
    Utils::clock->sleep(4);
  }
  Utils::tailMotor->fixAngle();

  /* 5秒間倒立しながらPID制御で走行 */
  int turn;
  for(int i = 0; i < 1250; i++)
  {
    turn = Utils::turnValues->getTurn(); 
    Utils::balancer->setCommand(30, turn);
    Utils::balancer->update(
      Utils::gyroSensor->getAnglerVelocity(),
      Utils::motorR->getCount(),
      Utils::motorL->getCount(),
      ev3_battery_voltage_mV()
    );
    pwmL = Utils::balancer->getPwmLeft();
    pwmR = Utils::balancer->getPwmRight();
    Utils::motorL->setPWM(pwmL);
    Utils::motorR->setPWM(pwmR);
    Utils::clock->sleep(4);
  }

  /* テールを下げる */
  Utils::tailMotor->unfixAngle();
  Utils::balancer->setCommand(0, 0);
  for(int angle = 3; angle <= 88; angle++)
  {
    Utils::tailMotor->setAngle(angle);
    Utils::balancer->update(
      Utils::gyroSensor->getAnglerVelocity(),
      Utils::motorR->getCount(),
      Utils::motorL->getCount(),
      ev3_battery_voltage_mV()
    );
    pwmL = Utils::balancer->getPwmLeft();
    pwmR = Utils::balancer->getPwmRight();
    Utils::motorL->setPWM(pwmL);
    Utils::motorR->setPWM(pwmR);
    Utils::clock->sleep(4);
  }
  Utils::tailMotor->fixAngle();

  /* 5秒間テールを下げて走行 */
  for(int i = 0; i < 1250; i++)
  {
    turn = Utils::turnValues->getTurn();
    Utils::motorL->setPWM(30 - turn);
    Utils::motorR->setPWM(30 + turn);
    Utils::clock->sleep(4);
  }

}
