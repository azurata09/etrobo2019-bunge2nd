/*
 * TurnValues.cpp
 * Copyright (C) 2019 azurata
 */
#include "TurnValues.h"

int TurnValues::restruct(int value, unsigned int absMax)
{
  int absMax_ = static_cast<int>(absMax);
  if(invert)
    value = -value;
  if(value > absMax_)
    return absMax;
  else if(value < -absMax_)
    return -absMax;
  else
    return value;
}

void TurnValues::setInvert(bool invert)
{
  this->invert = invert;
}

void TurnValues::setPID(float p, float i, float d)
{
  this->p = p;
  this->i = i;
  this->d = d;
}

void TurnValues::setMode(TraceMode mode)
{
  this->mode = mode;
}

int TurnValues::getTurn()
{
  switch(mode)
  {
  case TM_P:
    return restruct(p, 100);
  case TM_PI:
    return restruct(p+i, 100);
  case TM_PD:
    return restruct(p+d, 100);
  case TM_PID:
    return restruct(p+i+d, 100);
  }
}
