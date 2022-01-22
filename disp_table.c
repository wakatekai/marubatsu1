/*****************************************************************************/
/* File Name : disp_table.c                                                  */
/*****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "disp_table.h"

#define LETTER_NUM (((TABLE_X_NUM * 2) - 1) * (TABLE_Y_NUM * 2))

const signed char str_init[] =  "  ";
const signed char str_maru[] =  "○";
const signed char str_batsu[] =  "×";
const signed char str_vert[] = "｜";
const signed char str_hor[] = "－";
const signed char str_cross[] = "＋";

typedef enum {
    v = 0,    /* 縦(vect) */
    h,        /* 横(hor) */
    c,        /* クロス(cross) */
    n,        /* 改行(new line) */
    t         /* テーブル内容の表示 */
} LETTER;

const LETTER disp_letter[LETTER_NUM] = {
    t, v, t, v, t, n,
    h, c, h, c, h, n,
    t, v, t, v, t, n,
    h, c, h, c, h, n,
    t, v, t, v, t, n
};

void disp_table(signed char *num_table)
{
    unsigned char loop;

    system("cls");  /* コンソール画面をクリアする */

    for (loop = 0; loop < (unsigned char)LETTER_NUM; loop++)
    {
        switch (disp_letter[loop]) {
            case v:
                printf("%s", str_vert);
                break;
            case h:
                printf("%s", str_hor);
                break;
            case c:
                printf("%s", str_cross);
                break;
            case n:
                printf("\n");
                break;
            case t:
                /* テーブル内容を表示する */
                switch (*(num_table++)) {
                    case -1:
                        printf("%s", str_batsu);
                        break;
                    case 0:
                        printf("%s", str_init);
                        break;
                    case 1:
                        printf("%s", str_maru);
                        break;
                    default:
                        printf("<<ERROR>>\n");
                        break;
                }
                break;
            default:
                printf("<<ERROR>>\n");
                break;
        }
    }

    return;
}