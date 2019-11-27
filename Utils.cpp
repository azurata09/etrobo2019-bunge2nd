/*
 * Utils.cpp
 * Copyright (C) 2019 azurata
 */
#include "Utils.h"

using namespace ev3api;

Clock* Utils::clock = new Clock();
Motor* Utils::motorL = new Motor(PORT_C);
Motor* Utils::motorR = new Motor(PORT_B);
TailMotor* Utils::tailMotor = new TailMotor(PORT_A);
TouchSensor* Utils::touchSensor = new TouchSensor(PORT_1);
SonarAlerter* Utils::sonarAlerter = new SonarAlerter(PORT_2);
ColorSensor* Utils::colorSensor = new ColorSensor(PORT_3);
GyroSensor* Utils::gyroSensor = new GyroSensor(PORT_4);
Logger* Utils::logger = new Logger();
LineTracer* Utils::lineTracer = new LineTracer();
TurnValues* Utils::turnValues = new TurnValues();
Balancer* Utils::balancer = new Balancer();
