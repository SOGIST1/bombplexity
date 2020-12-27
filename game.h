#ifndef GAME_H_
#define GAME_H_

#define N 8
#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 1000
#define WINDOW_POSITION_X 60
#define WINDOW_POSITION_Y 60
#define CELL_WIDTH (WINDOW_WIDTH / N)
#define CELL_HEIGHT (WINDOW_HEIGHT / N)

#define EMPTY 0
#define PLAYER_1 1
#define PLAYER_2 2

#define RUNNING_STATE 0
#define PLAYER_1_WON_STATE 1
#define PLAYER_2_WON_STATE 2
#define TIE_STATE 3
#define QUIT_STATE 4

typedef struct{
    int board [N * N];
    int player;
    int state;
} game_t;

#endif // GAME_H_
