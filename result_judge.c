/*****************************************************************************/
/* File Name : Result Judge.c                                                */
/*****************************************************************************/
#include "result_judge.h"

#define PLAYER1_WIN     (3)
#define PLAYER2_WIN     (-3)

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
    {{0, 0}, {0, 1}, {0, 2}},       /* 1s–Ú    */
    {{1, 0}, {1, 1}, {1, 2}},       /* 2s–Ú    */
    {{2, 0}, {2, 1}, {2, 2}},       /* 3s–Ú    */
    {{0, 0}, {1, 0}, {2, 0}},       /* 1—ñ–Ú    */
    {{0, 1}, {1, 1}, {2, 1}},       /* 2—ñ–Ú    */
    {{0, 2}, {1, 2}, {2, 2}},       /* 3—ñ–Ú    */
    {{0, 0}, {1, 1}, {2, 2}},       /* Î‚ß(_) */
    {{0, 2}, {1, 1}, {2, 0}}        /* Î‚ß(^) */
};

JUDGE_RESULT result_judge(signed char num_table[3][3])
{
    JUDGE_RESULT result;
    unsigned char loop;
    signed char sum;

    result = RESULT_CONTD;      /* Œ‹‰Ê‚ğŒp‘±‚Å‰Šú‰» */

    for (loop = 0; loop < INDEX_TBL_NUM; loop++) {
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
            /* Ÿ”s‚ª‚Â‚©‚È‚¢ê‡‚Í”»’è‚ğŒp‘± */
        }
    }

    return result;
}
