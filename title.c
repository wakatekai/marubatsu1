/*****************************************************************************/
/* File Name : title.c                                                       */
/*****************************************************************************/
#include <stdio.h>
#include "common.h"
#include "title.h"

/* ’è”’è‹` */
#define INP_START   (1)
#define INP_END     (2)

/* ƒvƒƒgƒ^ƒCƒvéŒ¾ */
BOOL title_chk_input(unsigned char input_num);

BOOL title(void)
{
    /* •Ï”’è‹` */
    BOOL end_flg;
    unsigned char input_num;

    printf("  ›b›b~\n");
    printf("  |{|{|\n");
    printf("  ~b~b›\n");
    printf("  |{|{|\n");
    printf("  ›b~b›\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                u    ›~ƒQ[ƒ€    v\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                                          ›b›b›\n");
    printf("                                          |{|{|\n");
    printf("                                          ~b~b  \n");
    printf("                                          |{|{|\n");
    printf("                                          ›b  b~\n");
    printf("\n");
    printf("\n");
    printf("                  1FŠJn 2FI—¹\n");

    /* “ü—Í’læ“¾ */
    scanf("%d",&input_num);

    /* “ü—Í’l”»’è */
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
        /* ¡‰ñ‚Í‘z’èŠO‚Ì“ü—Í‚Íl‚¦‚È‚¢ */
        end_flg = TRUE;
        break;
    }
    return end_flg;
}