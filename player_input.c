/*****************************************************************************/
/* File Name : player_input.c                                                     */
/*****************************************************************************/
#include <stdio.h>
#include"common.h"
#include"player_input.h"
#include"main.h"

signed char input(PLAYER);

//�v���C���[�̎擾�ƃ}�X�ڔz��̏�������
BOOL player_input(PLAYER player,signed char num_table[3][3])
{
    BOOL end_flg;
	//������
	end_flg = FALSE;
    //�v���C���[�̃}�X�ڈʒu����
    if (player == PLAYER1){
        printf("Player1 1�`9����͂��Ă�������\n");
    }
    else if(player == PLAYER2){
        printf("Player2 1�`9����͂��Ă�������\n");
    }
    signed char position;
    scanf("%d",&position);
    //���͂��ꂽ�}�X�ڈʒu�ɂ���ă}�X�ڔz�������������
    switch (position){
        case 1:
            num_table[0][0] = input(player);
            break;
        case 2:
            num_table[0][1] = input(player);
            break;
        case 3:
            num_table[0][2] = input(player);
            break;
        case 4:
            num_table[1][0] = input(player);
            break;
        case 5:
            num_table[1][1] = input(player);
            break;
        case 6:
            num_table[1][2] = input(player);
            break;
        case 7:
            num_table[2][0] = input(player);
            break;
        case 8:
            num_table[2][1] = input(player);
            break;
        case 9:
            num_table[2][2] = input(player);
            break;
        default:
            printf("1�`9����͂��Ă�������\n");
    		end_flg = TRUE;
            break;
        }
	return end_flg;
}

//���͂����v���C���[�ɂ���ă}�X�ڔz��Ɋi�[���鐔�l��ς���
signed char input(PLAYER player){
    signed char output;

    if(player == 0){
        output = 1;
        return output;
    }else if(player == 1){
        output = -1;
        return output;       
    }else{
        printf("���������������s����܂���ł����B\n");
        return 0;
    }
}