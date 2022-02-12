/*****************************************************************************/
/* File Name : Result Judge.h                                                */
/*****************************************************************************/
/* 多重インクルードガード */
#ifndef RESULT_JUDGE_H
#define RESULT_JUDGE_H

#include "main.h"

typedef enum {
    RESULT_CONTD = 0,      /* 0:継続 */
    RESULT_P1_WIN,         /* 1:Player1の勝利 */
    RESULT_P2_WIN,         /* 2:Player2の勝利 */
    RESULT_DRAW            /* 3:引き分け */
} JUDGE_RESULT;


extern JUDGE_RESULT result_judge(signed char num_table[TABLE_X_NUM][TABLE_Y_NUM]);

#endif  /* RESULT_JUDGE_H */
