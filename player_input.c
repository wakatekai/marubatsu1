/*****************************************************************************/
/* File Name : player_input.c                                                     */
/*****************************************************************************/
#include <stdio.h>
#include"common.h"
#include"player_input.h"
#include"main.h"

signed char input(PLAYER);

//プレイヤーの取得とマス目配列の書き換え
BOOL player_input(PLAYER player,signed char num_table[3][3])
{
    BOOL end_flg;
	//初期化
	end_flg = FALSE;
    //プレイヤーのマス目位置入力
    signed char position;
    scanf("%d",&position);
    //入力されたマス目位置によってマス目配列を書き換える
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
    		end_flg = TRUE;
            break;
        }
	return end_flg;
}

//入力したプレイヤーによってマス目配列に格納する数値を変える
signed char input(PLAYER player){
    signed char output;

    if(player == 0){
        output = 1;
        return output;
    }else if(player == 1){
        output = -1;
        return output;       
    }else{
        printf("正しく処理が実行されませんでした。\n");
        return 0;
    }
}