/*****************************************************************************/
/* File Name : main.c                                                        */
/*****************************************************************************/
/* インクルード */
#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "main.h"
#include "title.h"
#include "disp_table.h"
/* #include "player_input.h" */
#include "result_judge.h"

/* 定数定義 */
#define TABLE_INIT      (0)

/* プロトタイプ宣言 */
void main_init(void);
void start_message(void);
void end_message(JUDGE_RESULT result);
void player_change(void);

/* 変数定義 */
signed char num_table[TABLE_X_NUM][TABLE_Y_NUM];    /* テーブル */
BOOL end_flg;                                       /* 終了フラグ */
JUDGE_RESULT result;                                /* 判定結果 */
PLAYER player;                                      /* プレイヤー */

int main(void)
{
    /* 変数定義 */

    /* とりあえず今回は単発 */
    end_flg = title();      /* タイトル表示・開始/終了選択 */

    if (end_flg == FALSE) {

        main_init();    /* 初期化 */

        start_message();    /* 開始時メッセージ */

        while ((end_flg == FALSE) && (result == RESULT_CONTD)) {
            /* 終了条件：中断値が入力された or ゲームの決着 */

            disp_table(&num_table[0][0]);  /* テーブル表示 */

            /* end_flg = player_input(player, num_table); */    /* ユーザ入力 */

            result = result_judge(num_table);   /* 結果判定 */

            player_change();
        }

        end_message(result);
    }

    printf("(デバッグ)main終了\n");
    system("pause");
    return 0;
}

void main_init(void)
{
    unsigned char loop_x;
    unsigned char loop_y;

    for (loop_x = 0; loop_x < (unsigned char)TABLE_X_NUM; loop_x++) {
        for (loop_y = 0; loop_y < (unsigned char)TABLE_X_NUM; loop_y++) {
            num_table[loop_x][loop_y] = (signed char)TABLE_INIT;
        }
    }

    end_flg = FALSE;
    result = RESULT_CONTD;
    player = PLAYER1;

    return;
}

void start_message(void)
{
    /* ルールとか表示させる？ */
    return;
}

void end_message(JUDGE_RESULT result)
{
    switch (result) {
        case RESULT_P1_WIN:
            printf("Player1の勝利\n");
        break;
        case RESULT_P2_WIN:
            printf("Player2の勝利\n");
        break;
        case RESULT_CONTD:
        default:
            printf("中断が選択されました。ゲームを終了します。\n");
        break;
    }
    return;
}

void player_change(void)
{
    /* プレイヤーを切り替える */
    if (player == PLAYER1) {
        player = PLAYER2;
    } else {
        player = PLAYER1;
    }
    return;
}
