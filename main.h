/*****************************************************************************/
/* File Name : main.h                                                        */
/*****************************************************************************/
/* ���d�C���N���[�h�K�[�h */
#ifndef MAIN_H
#define MAIN_H

#define TABLE_X_NUM     (3)
#define TABLE_Y_NUM     (3)
#define TABLE_SIZE      (TABLE_X_NUM * TABLE_Y_NUM)

#define TABLE_INIT      (0)
#define TABLE_MARU      (1)
#define TABLE_BATSU     (-1)

typedef enum {
    PLAYER1 = 0,    /* 0:�v���C���[1 */
    PLAYER2         /* 1:�v���C���[2 */
} PLAYER;

#endif  /* MAIN_H */
