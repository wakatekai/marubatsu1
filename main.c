/*****************************************************************************/
/* File Name : main.c                                                        */
/*****************************************************************************/
/* �C���N���[�h */
#include <stdio.h>
#include "common.h"
#include "main.h"
#include "title.h"
#include "result_judge.h"

/* �萔��` */
#define TABLE_X_NUM     (3)
#define TABLE_Y_NUM     (3)

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

        while ((end_flg == FALSE) && (result == RESULT_CONTD)) {
            /* �I�������F���f�l�����͂��ꂽ or �Q�[���̌��� */

            /* �����ɉ�ʕ\���֐���ǉ� */

            /* �����Ƀ��[�U���͊֐���ǉ� */

            result = result_judge(num_table);   /* ���ʔ��� */

            player_change();
        }

        end_message(result);
    }

    printf("(�f�o�b�O)main�I��\n");
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
    /* ���[���Ƃ������H */
    printf("(�f�o�b�O)�J�n���b�Z�[�W\n");
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
        case RESULT_CONTD:
        default:
            /* ���f�����ꍇ�͉����\�����Ȃ� */
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
