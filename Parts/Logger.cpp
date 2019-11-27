/*
 * Logger.cpp
 * Copyright (C) 2019 azurata
 */
#include "Logger.h"
#define CALIB_FONT (EV3_FONT_SMALL)
#define CALIB_FONT_WIDTH (6)
#define CALIB_FONT_HEIGHT (8)

Logger::Logger()
{
  ev3_lcd_fill_rect(0, 0, EV3_LCD_WIDTH, EV3_LCD_HEIGHT, EV3_LCD_WHITE);
  println("EV3way-ET AiRPS");
}

void Logger::println(char* msg)
{
  ev3_lcd_draw_string(msg, 0, CALIB_FONT_HEIGHT * line);
  line++;
}