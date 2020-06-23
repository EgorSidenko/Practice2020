/*
@ Летняя практика
@ Файл main.c
@ Автор Сиденко Е.В.
@ Задание: подсчитать количество возможных ходов короля за m шахов 
@ Дата создания: 24.06.2020
*/
#include "chess.c" //inlcude funtion for game

int main(void)
{
    int m;  //turns
    printf("How many turn do you want to make: ");
    scanf("%d", &m);
    RandomPlaceKing();  //Holds the king on a chessboard
    setup_board();      //create the chessboard
    MoveCounter(m);     //count how many option king has
    king[x][y]=board_coordinate[x][y]; // place king 
    MoveSystemByTerminal(m); //control system
    return 0;
}