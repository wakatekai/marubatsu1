/*****************************************************************************/
/* File Name : disp_table.c                                                  */
/*****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "disp_table.h"

const signed char str_init[] =  "  ";
const signed char str_maru[] =  "›";
const signed char str_batsu[] =  "~";

void disp_table(signed char num_table[TABLE_X_NUM][TABLE_Y_NUM])
{
    system("cls");  /* ƒRƒ“ƒ\[ƒ‹‰æ–Ê‚ğƒNƒŠƒA‚·‚é */
    printf("›b›b›\n");
    printf("|{|{|\n");
    printf("›b  b›\n");
    printf("|{|{|\n");
    printf("›b›b›\n");

    system("pause");
    return;
}