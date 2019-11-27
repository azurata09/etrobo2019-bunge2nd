#include "ev3api.h"
#include "app.h"
#include "Utils.h"
#include "Tasks/Tutorial.h"

#define DEBUG

#ifdef DEBUG
#define _debug(x) (x)
#else
#define _debug(x)
#endif

// Bluetooth
static int32_t bt_cmd = 0;
static FILE *bt = NULL;

// Run
Tutorial tutorial;

static void calc_pid();

void main_task(intptr_t unused)
{
  // Open Bluetooth file
  bt = ev3_serial_open_file(EV3_SERIAL_BT);
  assert(bt != NULL);

  // bt_task起動
  act_tsk(BT_TASK);

  // LineTracerにTurnValuesを保持させる
  Utils::lineTracer->initTurnValues(Utils::turnValues);

  // キャリブレーション状態LED点灯(オレンジ)
  ev3_led_set_color(LED_ORANGE);

  // カラーモードに設定
  Utils::colorSensor->getColorNumber();

  // キャリブレーション処理
  while(1) if (!(Utils::touchSensor->isPressed())) break;
  Utils::logger->println("Put on white");
  while(1)
  {
    if(Utils::touchSensor->isPressed())
    {
      rgb_raw_t rgb;
      Utils::colorSensor->getRawColor(rgb);
      Utils::lineTracer->setWhiteRGB(rgb);
      ev3_speaker_play_tone(NOTE_C4, 10);
      break;
    }
    Utils::clock->sleep(100);
  }

  while(1) if (!(Utils::touchSensor->isPressed())) break;
  Utils::logger->println("Put on black");
  while(1)
  {
    if(Utils::touchSensor->isPressed())
    {
      rgb_raw_t rgb;
      Utils::colorSensor->getRawColor(rgb);
      Utils::lineTracer->setBlackRGB(rgb);
      ev3_speaker_play_tone(NOTE_C4, 10);
      break;
    }
    Utils::clock->sleep(100);
  }
  Utils::logger->println("Calibrating...");
  while(1) if (!(Utils::touchSensor->isPressed())) break;
  while (1)
  {
    if(bt_cmd == 1) break;
    if(Utils::touchSensor->isPressed()) break;
    Utils::tailMotor->setAngle(87);
    Utils::clock->sleep(10);
  }

  // モータ・ジャイロセンサリセット
  Utils::motorL->reset();
  Utils::motorR->reset();
  Utils::gyroSensor->reset();

  // 倒立振子API初期化
  Utils::balancer->init(0);

  // 走行状態LED点灯(緑)
  ev3_led_set_color(LED_GREEN);

  // サイクラ開始
  ev3_sta_cyc(CALC_PID_CYC);
  ev3_sta_cyc(SONAR_ALERT_CYC);

  // 動作
  tutorial.run();

  // 全てのモータの動作停止
  Utils::motorL->setBrake(true);
  Utils::motorR->setBrake(true);
  Utils::tailMotor->fixAngle();

  // bt_task停止
  ter_tsk(BT_TASK);
  fclose(bt);

  // サイクラ停止
  ev3_stp_cyc(CALC_PID_CYC);
  ev3_stp_cyc(SONAR_ALERT_CYC);

  ext_tsk();
}

void bt_task(intptr_t unused)
{
  while (1)
  {
    uint8_t c = fgetc(bt);
    switch (c)
    {
    case '1':
      bt_cmd = 1;
      break;
    case '2':
      bt_cmd = 2;
      break;
    default:
      break;
    }
    fputc(c, bt);
  }
}

void calc_pid_cyc(intptr_t unused)
{
  calc_pid();
}

void calc_pid()
{
  static rgb_raw_t rgb;
  Utils::colorSensor->getRawColor(rgb);
  Utils::lineTracer->calcColorPID(rgb);
}

void sonar_alert_cyc(intptr_t unused)
{
  Utils::sonarAlerter->setAlert();
}
