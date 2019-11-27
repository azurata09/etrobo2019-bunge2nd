/*
 * SonarAlerter.cpp
 * Copyright (C) 2019 azurata
 */
#include "SonarAlerter.h"
#define SONAR_ALERT_DISTANCE 30

using namespace ev3api;

SonarAlerter::SonarAlerter(ePortS port)
{
  sonarSensor = new SonarSensor(port);
}

void SonarAlerter::setAlert()
{
  signed int distance;
  distance = sonarSensor->getDistance();
  if ((distance <= SONAR_ALERT_DISTANCE) && (distance >= 0))
    alert = 1; /* 障害物を検知 */
  else
    alert = 0; /* 障害物無し */
}

bool SonarAlerter::getAlert()
{
  return alert;
}
