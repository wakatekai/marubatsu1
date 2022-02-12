/*****************************************************************************/
/* File Name : title.c                                                       */
/*****************************************************************************/
#include <stdio.h>
#include "common.h"
#include "title.h"

/* �萔��` */
#define INP_START   (1)
#define INP_END     (2)

/* �v���g�^�C�v�錾 */
BOOL title_chk_input(unsigned char input_num);

BOOL title(void)
{
    /* �ϐ���` */
    BOOL end_flg;
    unsigned char input_num;

    printf("  ���b���b�~\n");
    printf("  �|�{�|�{�|\n");
    printf("  �~�b�~�b��\n");
    printf("  �|�{�|�{�|\n");
    printf("  ���b�~�b��\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                �u    ���~�Q�[��    �v\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                                          ���b���b��\n");
    printf("                                          �|�{�|�{�|\n");
    printf("                                          �~�b�~�b  \n");
    printf("                                          �|�{�|�{�|\n");
    printf("                                          ���b  �b�~\n");
    printf("\n");
    printf("\n");
    printf("                  1�F�J�n 2�F�I��\n");

    /* ���͒l�擾 */
    scanf("%d",&input_num);

    /* ���͒l���� */
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
        /* ����͑z��O�̓��͍͂l���Ȃ� */
        end_flg = TRUE;
        break;
    }
    return end_flg;
}