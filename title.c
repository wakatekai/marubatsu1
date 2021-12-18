/*****************************************************************************/
/* File Name : title.c                                                       */
/*****************************************************************************/
#include <stdio.h>
#include "common.h"
#include "title.h"

/* 定数定義 */
#define INP_START   (1)
#define INP_END     (2)

/* プロトタイプ宣言 */
BOOL title_chk_input(unsigned char input_num);

BOOL title(void)
{
    /* 変数定義 */
    BOOL end_flg;
    unsigned char input_num;

    printf("○×ゲーム\n");
    printf("1:開始\n2：終了\n");

    /* 入力値取得 */
    scanf("%d",&input_num);

    /* 入力値判定 */
    end_flg = title_chk_input(input_num);


    return end_flg;
}

BOOL title_chk_input(unsigned char input_num)
{
    BOOL end_flg;

    switch (input_num)
    {
    case (unsigned char)INP_START:
        end_flg = FALSE;
        break;
    case (unsigned char)INP_END:
        end_flg = TRUE;
        break;
    default:
        /* 今回は想定外の入力は考えない */
        end_flg = TRUE;
        break;
    }
    return end_flg;
}