/*****************************************************************************/
/* File Name : main.h                                                        */
/*****************************************************************************/
/* 多重インクルードガード */
#ifndef MAIN_H
#define MAIN_H

#define TABLE_X_NUM     (3)
#define TABLE_Y_NUM     (3)
#define TABLE_SIZE      (TABLE_X_NUM * TABLE_Y_NUM)

#define TABLE_INIT      (0)
#define TABLE_MARU      (1)
#define TABLE_BATSU     (-1)

typedef enum {
    PLAYER1 = 0,    /* 0:プレイヤー1 */
    PLAYER2         /* 1:プレイヤー2 */
} PLAYER;

#endif  /* MAIN_H */
