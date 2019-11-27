/*
 * LineTracer.cpp
 * Copyright (C) 2019 azurata
 */
#include "LineTracer.h"

int LineTracer::getBrightnessRGB(rgb_raw_t rgb)
{
  return 0.298912 * rgb.r + 0.586611 * rgb.g + 0.114478 * rgb.b;
}

void LineTracer::initTurnValues(TurnValues *turnValues)
{
  this->turnValues = turnValues;
}

void LineTracer::setWhite(int white)
{
  this->white = white;
}

void LineTracer::setBlack(int black)
{
  this->black = white;
}

void LineTracer::setWhiteRGB(rgb_raw_t rgb)
{
  this->white = getBrightnessRGB(rgb);
}

void LineTracer::setBlackRGB(rgb_raw_t rgb)
{
  this->black = getBrightnessRGB(rgb);
}

void LineTracer::setGain(float KP, float KI, float KD)
{
  this->KP = KP;
  this->KI = KI;
  this->KD = KD;
}

void LineTracer::calcPID(int brightness)
{
  last = now;
  now = brightness - (white + black) / 2;
  integral += (now - last) / 2 * DELTA_T;
  turnValues->setPID(KP * now, KI * integral, (now - last) / DELTA_T);
}

void LineTracer::calcColorPID(rgb_raw_t rgb)
{
  calcPID(getBrightnessRGB(rgb));
}
