#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


#define rows 9
#define cols 9 
#define ask 10

int king[rows][cols];                  //king location
int board_coordinate[rows][cols];      //board coordinate
unsigned char board_color[rows][cols]; //board color(black, white)
int x, y;

//Create a board, make a color
void setup_board(){
  int k=1, counter=0;
  // color board
  for(int j=1;j<cols;j++)
  {
    for(int i=1;i<rows;i++)
    {
      //give each squere the number(from 1 to 64)
      board_coordinate[i][j] = ++counter;
      //"tick - tock" mechanic
      if (k == 1)
      board_color[i][j] = '+';  //white
      else if (k ==-1)
      board_color[i][j] = '-';  //black
      k *= -1;
    }
      k *= -1;
  }
}
void display_board(){
  char line ='a';
  printf(" ");
  while(line<='h'){
  printf(" %c", line);
  line++;
  }
  printf("\n");
  for(int i=1;i<cols;i++)
  {
    printf("%d ", i);
    for(int j=1;j<rows;j++)
    {
      if (king[x][y]==board_coordinate[i][j])
      board_color[i][j] = 'k';
      printf("%1c ",board_color[i][j]);
    }
    printf("\n");
  }
   printf("\n");
}
void RandomPlaceKing(){
    srand((unsigned)time(NULL));
    //X
    x = rand()%10;
    if(x>=9)
    x=x-2;
    else if (x==0)
    x++;
    //Y
    y = rand()%10;
    if(y>=9)
    y=y-2;
    else if (y==0)
    y++;
}
int fixedFgets(char str[], int n)
{
    int success = 1;

    // Check that fgets worked
    if (fgets(str, n, stdin) != NULL)
    {
         str[strcspn(str, "\n")] = 0;
    }
    else
    {
        success = 0;
    }

    return success;
}

void MoveSystemByTerminal(int turn){
  for(int turnNow=0;turnNow<turn;turnNow++){
      char AskMotion[ask];
      printf("--------\nMove setting:\nup\ndown\nright\nleft\n~~~~~~\n");
      fixedFgets(AskMotion, 9);
      //fgets(AskMotion, sizeof(AskMotion)+1, stdin);
      if (strncmp(AskMotion, "up", 3)==0)
      {
        printf("up done\n");
      }
      if (strncmp(AskMotion, "down", 5)==0)
      {
        printf("down done\n");
      }
      if (strncmp(AskMotion, "right", 6)==0)
      {
        printf("right done\n");
      }
      if (strncmp(AskMotion, "left", 5)==0)
      {
        printf("left done\n");
      }
    }
  }


int main(void)
{
    int m = 3;      //turn 
  //  printf("How many turn do you want to make");
  //  scanf("%d", &m);
    RandomPlaceKing();
    setup_board();
    king[x][y]=board_coordinate[x][y];
    display_board();
    MoveSystemByTerminal(m);
    //printf("x=%d\n", x);  //debager
    //printf("y=%d\n", y);  //debager
    //printf("KingPlace =%d\n", king[x][y]);//debager
  
    return 0;
}