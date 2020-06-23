#include "chess.c"

int main(void)
{
    int m;  
    printf("How many turn do you want to make: ");
    scanf("%d", &m);
    RandomPlaceKing();
    setup_board();
    MoveCounter(m);
    king[x][y]=board_coordinate[x][y];
    MoveSystemByTerminal(m);
    return 0;
}