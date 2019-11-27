#ifdef __cplusplus
extern "C" {
#endif

/* ターゲット依存の定義 */
#include "target_test.h"

/* 各タスクの優先度の定義 */
#define MAIN_PRIORITY TMIN_APP_TPRI + 1 /* メインタスクの優先度 HIGH_PRIORITYより高くすること */
#define HIGH_PRIORITY TMIN_APP_TPRI + 3 /* 並行実行されるタスクの優先度 */
#define MID_PRIORITY TMIN_APP_TPRI + 5
#define LOW_PRIORITY TMIN_APP_TPRI + 7

/* ターゲットに依存する可能性のある定数の定義 */
#ifndef TASK_PORTID
#define TASK_PORTID 1 /* 文字入力するシリアルポートID */
#endif /* TASK_PORTID */

#ifndef STACK_SIZE
#define STACK_SIZE 4096 /* タスクのスタックサイズ */
#endif /* STACK_SIZE */

/* タスク・サイクラ用関数のプロトタイプ宣言 */
#ifndef TOPPERS_MACRO_ONLY

extern void main_task(intptr_t exinf);
extern void bt_task(intptr_t exinf);
extern void calc_pid_cyc(intptr_t exinf);
extern void sonar_alert_cyc(intptr_t exinf);

#endif /* TOPPERS_MACRO_ONLY */

#ifdef __cplusplus
}
#endif
