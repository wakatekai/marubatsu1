/*****************************************************************************/
/* File Name : Result Judge.c                                                */
/*****************************************************************************/
#include "result_judge.h"
/* #include "main.h" */ /* �w�b�_��include�ς� */

#define PLAYER1_WIN     (TABLE_X_NUM)
#define PLAYER2_WIN     (-TABLE_X_NUM)

#define INDEX_TBL_NUM   (8)

typedef struct {
    unsigned char x;
    unsigned char y;
} INDEX;

typedef struct {
    INDEX num1;
    INDEX num2;
    INDEX num3;
} CALC_INDEX_TABLE;

const CALC_INDEX_TABLE calc_index_table[INDEX_TBL_NUM] = {
    {{0, 0}, {0, 1}, {0, 2}},       /* 1�s��    */
    {{1, 0}, {1, 1}, {1, 2}},       /* 2�s��    */
    {{2, 0}, {2, 1}, {2, 2}},       /* 3�s��    */
    {{0, 0}, {1, 0}, {2, 0}},       /* 1���    */
    {{0, 1}, {1, 1}, {2, 1}},       /* 2���    */
    {{0, 2}, {1, 2}, {2, 2}},       /* 3���    */
    {{0, 0}, {1, 1}, {2, 2}},       /* �΂�(�_) */
    {{0, 2}, {1, 1}, {2, 0}}        /* �΂�(�^) */
};

/* �v���g�^�C�v�錾 */
unsigned char count_zero(signed char *data, unsigned char size);

JUDGE_RESULT result_judge(signed char num_table[TABLE_X_NUM][TABLE_Y_NUM])
{
    JUDGE_RESULT result;
    unsigned char loop;
    signed char sum;
    unsigned char zero_cnt;

    result = RESULT_CONTD;      /* ���ʂ��p���ŏ����� */

    for (loop = (unsigned char)0; loop < INDEX_TBL_NUM; loop++) {
        sum = 0;
        sum += num_table[calc_index_table[loop].num1.x][calc_index_table[loop].num1.y];
        sum += num_table[calc_index_table[loop].num2.x][calc_index_table[loop].num2.y];
        sum += num_table[calc_index_table[loop].num3.x][calc_index_table[loop].num3.y];

        if (sum == (signed char)PLAYER1_WIN) {
            result = RESULT_P1_WIN;
            break;
        } else if (sum == (signed char)PLAYER2_WIN) {
            result = RESULT_P2_WIN;
            break;
        } else {
            /* �����͂�������΁A���������Ɣ��肷�� */
            zero_cnt = count_zero(&num_table[0][0], (unsigned char)TABLE_SIZE);
            if (zero_cnt == (unsigned char)0) {
                result = RESULT_DRAW;
            } else {
                /* ���s�����Ȃ��ꍇ�͔�����p�� */
            }
        }
    }

    return result;
}

unsigned char count_zero(signed char *data, unsigned char size)
{
    unsigned char cnt;
    unsigned char loop;
    
	cnt = (unsigned char)0;
    
    for (loop = (unsigned char)0; loop < size; loop++) {
        if (*(data + loop) == (signed char)TABLE_INIT) {
            cnt++;
        }
    }
    
    return cnt;
}
