/*****************************************************************************/
/* File Name : disp_table.c                                                  */
/*****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "main.h"
#include "disp_table.h"

#define LETTER_NUM (((TABLE_X_NUM * 2) - 1) * (TABLE_Y_NUM * 2))

const signed char str_init[] =  "  ";
const signed char str_maru[] =  "��";
const signed char str_batsu[] =  "�~";
const signed char str_vert[] = "�b";
const signed char str_hor[] = "�|";
const signed char str_cross[] = "�{";

typedef enum {
    v = 0,    /* �c(vect) */
    h,        /* ��(hor) */
    c,        /* �N���X(cross) */
    n,        /* ���s(new line) */
    t         /* �e�[�u�����e�̕\�� */
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

    system("cls");  /* �R���\�[����ʂ��N���A���� */

    for (loop = (unsigned char)0; loop < (unsigned char)LETTER_NUM; loop++)
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
                /* �e�[�u�����e��\������ */
                switch (*(num_table++)) {
                	case (signed char)TABLE_BATSU:
                        printf("%s", str_batsu);
                        break;
                    case (signed char)TABLE_INIT:
                        printf("%s", str_init);
                        break;
                    case (signed char)TABLE_MARU:
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