#include <stdio.h>

void player_input(int player,int num_table[3][3]);
int input(int);

//プレイヤーの取得とマス目配列の書き換え
void player_input(int player,int num_table[3][3])
{
    //プレイヤーのマス目位置入力
    int position;
    scanf("%d",&position);
    //入力されたマス目位置によってマス目配列を書き換える
    switch (position){
        case 0:
            printf("ゲームを終了します。\n");
            break;
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
            printf("正しく処理が実行されませんでした。\n");
            break;
        }
}

//入力したプレイヤーによってマス目配列に格納する数値を変える
int input(int player){
    int output;

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