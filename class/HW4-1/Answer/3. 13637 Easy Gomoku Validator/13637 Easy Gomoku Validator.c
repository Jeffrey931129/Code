#include <stdio.h>

#define first                1
#define second               2

#define direction_up         0
#define direction_down       1
#define direction_left       2
#define direction_right      3
#define direction_up_left    4
#define direction_down_right 5
#define direction_up_right   6
#define direction_down_left  7

int directiontable[8][2] = {{0,1},{0,-1},{-1,0},{1,0},{-1,1},{1,-1},{1,1},{-1,-1}};

//global variable: automatically initialized as default value 0
int board[16][16];

void Print_if_has_winner(int player, int round) {
    if (player == first) {
        printf("LSC wins at the %dth step.\n", round + 1);
    } else {
        printf("TSC wins at the %dth step.\n", round + 1);
    }
}

//return the number of consecutive stones in a direction starting from (x,y) for a player;
int NConsecutiveStones(int position_x, int position_y, int player, int direction) {
    int nCS = 0; //the number of consecutive stones
    while(position_x >= 1 && position_x < 16 && position_y >= 1 && position_y < 16 && board[position_x][position_y] == player) {
        nCS++;
        position_x += directiontable[direction][0];
        position_y += directiontable[direction][1];
    }
    return nCS;
}

//return 1 if a line of at least five stones, or 0 otherwise;
int Checker(int position_x, int position_y, int player, int round) {
    int found = 0;
    int direction_pair;

    for(direction_pair = 0; direction_pair < 4; direction_pair++) {
        int nCS_total = 0; //the total number of consecutive stones
        nCS_total = NConsecutiveStones(position_x, position_y, player, 2*direction_pair)
                + NConsecutiveStones(position_x, position_y, player, 2*direction_pair+1)-1;
        if(nCS_total >= 5) {
            Print_if_has_winner(player, round);
            found = 1; break;
        }
    }
    return found;
}

int main () {
    int N = 0;
    scanf("%d", &N);
    int winner = -1;
    int i, j;

    for (i = 0; i < N; i++) {// read stone place
        int player = -1;
        int place_x = -1, place_y = -1;
        scanf("%d%d", &place_x, &place_y);

        if (i % 2 == 0)//first
            board[place_x][place_y] = player = first;
        else//second
            board[place_x][place_y] = player = second;

        if(Checker(place_x, place_y, player, i)) {
            winner = player;
            break;
        }
    }

    if (winner == -1) {
        printf("There's no winner.\n");
    }

    return 0;
}
