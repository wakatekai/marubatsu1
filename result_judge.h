/*****************************************************************************/
/* File Name : Result Judge.h                                                */
/*****************************************************************************/

typedef enum {
    RESULT_CONTD = 0,      /* 0:åpë± */
    RESULT_P1_WIN,         /* 1:Player1ÇÃèüóò */
    RESULT_P2_WIN          /* 2:Player2ÇÃèüóò */
} JUDGE_RESULT;


extern JUDGE_RESULT result_judge(signed char num_table[3][3]);