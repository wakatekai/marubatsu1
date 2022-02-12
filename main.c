/*****************************************************************************/
/* File Name : main.c                                                        */
/*****************************************************************************/
/* �C���N���[�h */
#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "main.h"
#include "title.h"
#include "disp_table.h"
#include "player_input.h"
#include "result_judge.h"

/* �萔��` */
#define TABLE_INIT      (0)

/* �v���g�^�C�v�錾 */
void main_init(void);
void start_message(void);
void end_message(JUDGE_RESULT result);
void player_change(void);

/* �ϐ���` */
signed char num_table[TABLE_X_NUM][TABLE_Y_NUM];    /* �e�[�u�� */
BOOL end_flg;                                       /* �I���t���O */
JUDGE_RESULT result;                                /* ���茋�� */
PLAYER player;                                      /* �v���C���[ */

int main(void)
{
    /* �ϐ���` */

    /* �Ƃ肠��������͒P�� */
    end_flg = title();      /* �^�C�g���\���E�J�n/�I���I�� */

    if (end_flg == FALSE) {

        main_init();    /* ������ */

        start_message();    /* �J�n�����b�Z�[�W */

        disp_table(&num_table[0][0]);  /* �e�[�u���\��(����) */

        while ((end_flg == FALSE) && (result == RESULT_CONTD)) {
            /* �I�������F���f�l�����͂��ꂽ or �Q�[���̌��� */

            end_flg = player_input(player, num_table);    /* ���[�U���� */

            disp_table(&num_table[0][0]);  /* �e�[�u���\�� */

            result = result_judge(num_table);   /* ���ʔ��� */

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
    system("cls");  /* �R���\�[����ʂ��N���A���� */

    printf("�y���[�������z\n");
    printf("  ���~�Q�[���̓v���C���[2�l�ŗV�ׂ�Q�[���ł��B\n");
    printf("\n");
    printf("  3�~3��9�}�X���v���C���[1�A�v���C���[2�̏���1�}�X����荇���Ă����܂��B\n");
    printf("\n");
    printf("  �v���C���[1���I�������}�X�́u���v�ɁA�v���C���[2���I�������}�X�́u�~�v�ƂȂ�܂��B\n");
    printf("\n");
    printf("  ���݂Ƀ}�X����荇���A��ɁA�c�E���E�΂߂̂����ꂩ�����낦���v���C���[�̏����ł��B\n");
    printf("\n");
    printf("  9�}�X���ׂĂ���荇������Ԃł����s�����Ȃ��ꍇ�́A���������ƂȂ�܂��B\n");
    printf("\n");
    printf("\n");
    printf("�y��������z\n");
    printf("  �{�Q�[����0�`9�̔��p��������͂��čs���܂��B\n");
    printf("\n");
    printf("   �P�b�Q�b�R\n");
    printf("   �|�{�|�{�|\n");
    printf("   �S�b�T�b�U\n");
    printf("   �|�{�|�{�|\n");
    printf("   �V�b�W�b�X\n");
    printf("\n");
    printf("  ��L�̂悤�Ƀ}�X�͍��ォ��1�`9�̐���������U���Ă���A���̃}�X�̐������w�肷�邱�ƂőI������܂��B\n");
    printf("\n");
    printf("  �Q�[���𒆒f�������ꍇ��0����͂��Ă��������B\n");
    printf("\n");
    printf("�y�쐬�z\n");
    printf("  ����\n");
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
            printf("Player1�̏���\n");
        break;
        case RESULT_P2_WIN:
            printf("Player2�̏���\n");
        break;
        case RESULT_DRAW:
            printf("���������ŏI�����܂����B\n");
        break;
        case RESULT_CONTD:
        default:
            printf("���f���I������܂����B�Q�[�����I�����܂��B\n");
        break;
    }
    return;
}

void player_change(void)
{
    /* �v���C���[��؂�ւ��� */
    if (player == PLAYER1) {
        player = PLAYER2;
    } else {
        player = PLAYER1;
    }
    return;
}
