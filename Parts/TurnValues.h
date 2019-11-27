/*
 * TurnValues.h
 * Copyright (C) 2019 azurata
 */
#pragma once

enum TraceMode
{
  TM_P,
  TM_PI,
  TM_PD,
  TM_PID
};

class TurnValues
{
  private:
    TraceMode mode = TM_PID;
    bool invert;
    float  p = 0;
    float  i = 0;
    float d = 0;
    int restruct(int value, unsigned int absMax);
  public:
    void setInvert(bool invert);
    void setPID(float p, float i, float d);
    void setMode(TraceMode mode);
    int getTurn();
};
