/*
 * Utils.h
 * Copyright (C) 2019 azurata
 */
#pragma once
#include "ev3api.h"
#include "Port.h"
#include "Clock.h"
#include "Motor.h"
#include "Steering.h"
#include "Parts/TailMotor.h"
#include "TouchSensor.h"
#include "Parts/SonarAlerter.h"
#include "ColorSensor.h"
#include "GyroSensor.h"
#include "Parts/Logger.h"
#include "Parts/TurnValues.h"
#include "Parts/LineTracer.h"
#include "balancer/BalancerCpp.h"

using namespace ev3api;

class Utils
{
  public:
    static Clock* clock;
    static Motor* motorL;
    static Motor* motorR;
    static Steering* steering;
    static TailMotor* tailMotor;
    static TouchSensor* touchSensor;
    static SonarAlerter* sonarAlerter;
    static ColorSensor* colorSensor;
    static GyroSensor* gyroSensor;
    static Logger* logger;
    static LineTracer* lineTracer;
    static TurnValues* turnValues;
    static Balancer* balancer;
};
