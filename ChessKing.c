#include <stdio.h>
#include <string.h>
#define rows 8
#define cols 8 
int OutputBoard()
{
    int board[rows][cols], i, j, k, count=1;
    k = 1;

    for(i=1; i<=rows; i++)
    {
        for(j=1; j<=cols; j++)
        {
            if(k == 1)
            {
                printf("▒");
            }
            else
            {
                 printf("▓");
            }

            // If k = 1  then k *= -1 => -1
            // If k = -1 then k *= -1 =>  1
            k *= -1;
            board[i][j] = 1 * count++;  
        }
        if(cols % 2 == 0)
        {
            k *= -1;
        }
        printf("\n");
    }
}

void KingSet (){

}

int main()
{
    int board[rows][cols];
    int king[rows][cols];
    OutputBoard(); //♕
    KingSet();
 for (;;) {

 }
 
    return 0;
}