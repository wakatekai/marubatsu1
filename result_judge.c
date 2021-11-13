/*****************************************************************************/
/* File Name : Result Judge.c                                                */
/*****************************************************************************/
#include "result_judge.h"

#define PLAYER1_WIN     (3)
#define PLAYER2_WIN     (-3)

typedef struct {
    unsigned char x;
    unsigned char y;
} INDEX;

typedef struct {
    INDEX num1;
    INDEX num2;
    INDEX num3;
} CALC_INDEX_TABLE;

const CALC_INDEX_TABLE calc_index_table[8] = {
    {{0, 0}, {0, 1}, {0, 2}},       /* 1行目    */
    {{1, 0}, {1, 1}, {1, 2}},       /* 2行目    */
    {{2, 0}, {2, 1}, {2, 2}},       /* 3行目    */
    {{0, 0}, {1, 0}, {2, 0}},       /* 1列目    */
    {{0, 1}, {1, 1}, {2, 1}},       /* 2列目    */
    {{0, 2}, {1, 2}, {2, 2}},       /* 3列目    */
    {{0, 0}, {1, 1}, {2, 2}},       /* 斜め(＼) */
    {{0, 2}, {1, 1}, {2, 0}}        /* 斜め(／) */
};

JUDGE_RESULT result_judge(signed char num_table[3][3])
{
    JUDGE_RESULT result;
    unsigned char loop;
    signed char sum;

    result = RESULT_CONTD;      /* 結果を継続で初期化 */

    for (loop = 0; loop < 8; loop++) {
        sum = 0;
        sum += num_table[calc_index_table[loop].num1.x][calc_index_table[loop].num1.y];
        sum += num_table[calc_index_table[loop].num2.x][calc_index_table[loop].num2.y];
        sum += num_table[calc_index_table[loop].num3.x][calc_index_table[loop].num3.y];

        if (sum == PLAYER1_WIN) {
            result = RESULT_P1_WIN;
            break;
        } else if (sum == PLAYER2_WIN) {
            result = RESULT_P2_WIN;
            break;
        } else {
            /* 勝敗がつかない場合は判定を継続 */
        }
    }

    return result;
}


#if 0
/* main.cの内容を本ファイルにバックアップ */

#include <stdio.h>
#include "result_judge.h"

int main()
{
     JUDGE_RESULT result;
     /* I/Fについては他メンバーと検討する */
     /* ↓デバッグ用 */
     /*  0:未入力 */
     /*  1:Player1 */
     /* -1:Player2 */ 
    signed char num_table[3][3] = {
        {-1, 0, 1},
        {0, -1, 1},
        {1, 0, -1}
    };

    result = result_judge(num_table);

    printf("結果 -> ");
    switch (result) {
        case RESULT_CONTD:
            printf("継続\n");
        break;
        case RESULT_P1_WIN:
            printf("Player1の勝利\n");
        break;
        case RESULT_P2_WIN:
            printf("Player2の勝利\n");
        break;
        default:
            printf("何かがおかしい...\n");
        break;
    }
    return 0;
}
#endif