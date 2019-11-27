/*
 * LineTracer.h
 * Copyright (C) 2019 azurata
 */
#pragma once
#include "ev3api.h"
#include "TurnValues.h"

class LineTracer
{
  private:
    float KP = 0;
    float KI = 0;
    float KD = 0;
    float DELTA_T = 0.004;
    int white = 55;
    int black = 0;
    int32_t integral;
    int last;
    int now;
    TurnValues *turnValues;
    int getBrightnessRGB(rgb_raw_t rgb);
  public:
    void initTurnValues(TurnValues *turnValues);
    void setWhite(int white);
    void setBlack(int black);
    void setWhiteRGB(rgb_raw_t rgb);
    void setBlackRGB(rgb_raw_t rgb);
    void setGain(float KP, float KI, float KD);
    void calcPID(int brightness);
    void calcColorPID(rgb_raw_t rgb);
};
