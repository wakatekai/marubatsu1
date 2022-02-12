/*****************************************************************************/
/* File Name : Result Judge.h                                                */
/*****************************************************************************/
/* ���d�C���N���[�h�K�[�h */
#ifndef RESULT_JUDGE_H
#define RESULT_JUDGE_H

#include "main.h"

typedef enum {
    RESULT_CONTD = 0,      /* 0:�p�� */
    RESULT_P1_WIN,         /* 1:Player1�̏��� */
    RESULT_P2_WIN,         /* 2:Player2�̏��� */
    RESULT_DRAW            /* 3:�������� */
} JUDGE_RESULT;


extern JUDGE_RESULT result_judge(signed char num_table[TABLE_X_NUM][TABLE_Y_NUM]);

#endif  /* RESULT_JUDGE_H */
