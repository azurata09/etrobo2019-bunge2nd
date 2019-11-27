/*
 * Logger.h
 * Copyright (C) 2019 azurata
 */
#pragma once
#include "ev3api.h"

class Logger
{
  private:
    int line = 1;
  public:
    void println(char* msg);
    Logger();
};
