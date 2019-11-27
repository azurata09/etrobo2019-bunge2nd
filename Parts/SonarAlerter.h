/*
 * SonarAlerter.h
 * Copyright (C) 2019 azurata
 */
#pragma once
#include "ev3api.h"
#include "Port.h"
#include "SonarSensor.h"

using namespace ev3api;

class SonarAlerter
{
  private:
    SonarSensor* sonarSensor;
    bool alert = false;
  public:
    SonarAlerter(ePortS port);
    void setAlert();
    bool getAlert();
};
