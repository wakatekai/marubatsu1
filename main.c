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
#include "player_input.h"
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

        disp_table(&num_table[0][0]);  /* テーブル表示(初回) */

        while ((end_flg == FALSE) && (result == RESULT_CONTD)) {
            /* 終了条件：中断値が入力された or ゲームの決着 */

            end_flg = player_input(player, num_table);    /* ユーザ入力 */

            disp_table(&num_table[0][0]);  /* テーブル表示 */

            result = result_judge(num_table);   /* 結果判定 */

            player_change();
        }

        end_message(result);
    }

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
    system("cls");  /* コンソール画面をクリアする */

    printf("【ルール説明】\n");
    printf("  ○×ゲームはプレイヤー2人で遊べるゲームです。\n");
    printf("\n");
    printf("  3×3の9マスをプレイヤー1、プレイヤー2の順で1マスずつ取り合っていきます。\n");
    printf("\n");
    printf("  プレイヤー1が選択したマスは「○」に、プレイヤー2が選択したマスは「×」となります。\n");
    printf("\n");
    printf("  交互にマスを取り合い、先に、縦・横・斜めのいずれかをそろえたプレイヤーの勝利です。\n");
    printf("\n");
    printf("  9マスすべてを取り合った状態でも勝敗がつかない場合は、引き分けとなります。\n");
    printf("\n");
    printf("\n");
    printf("【操作説明】\n");
    printf("  本ゲームは0～9の半角数字を入力して行います。\n");
    printf("\n");
    printf("   １｜２｜３\n");
    printf("   －＋－＋－\n");
    printf("   ４｜５｜６\n");
    printf("   －＋－＋－\n");
    printf("   ７｜８｜９\n");
    printf("\n");
    printf("  上記のようにマスは左上から1～9の数字が割り振られており、そのマスの数字を指定することで選択されます。\n");
    printf("\n");
    printf("  ゲームを中断したい場合は0を入力してください。\n");
    printf("\n");
    printf("【作成】\n");
    printf("  若手会\n");
    printf("   GitHub Account : 610engineer / alpc2632 / susususuin\n");
    printf("   Link : https://github.com/wakatekai/marubatsu1\n");
    printf("\n");


    system("pause");
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
        case RESULT_DRAW:
            printf("引き分けで終了しました。\n");
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
