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
int x, y, counter=0, fm=0;                   //Coords of king, counter of steps king

int MoveCounter(int turn){
  printf("Move print %d/%d\n", fm, turn);
  if (y >= 2 && x >=2 && y<=7 && x <=7)
  {
      counter+=8;
  }
  if(x >=2 && x<=7 && y==1 || x >=2 && x<=7 && y==8|| y>=2 && y<=7 && x==1 ||y>=2 && y<=7 && x==8){
      counter +=5;
  }
  if (x == 1 && y == 1||x == 1 && y == 8||x ==8 && y == 1||x == 8 && y == 8){
      counter+=3;
  }
  printf("Couter = %d\n", counter);
  return counter;
}
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
  for(int j=1;j<cols;j++)
  {
    printf("%d ", j);
    for(int i=1;i<rows;i++)
    {
      if(board_color[i][j]=='k')
      {
        switch ((i+j)%2)
        {
        case 0: board_color[i][j] = '+';
          break;
        case 1: board_color[i][j] = '-';
          break;
        }
      }
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

//return 1 - correct; return 0 - error(unable to make move up)
int UpMove()
{
  if(y>1 && y!=0 && y <= 8){
  y = y-1;
  king[x][y]=board_coordinate[x][y];
  }
  else{
   return 0;
  }
  return 1;
}
int DownMove()
{
  if(y<=8 && y !=0 && y>0){
  y = y+1;
  king[x][y]=board_coordinate[x][y];
  }
  else {
   return 0;
  }
  return 1;
}
int RightMove(){
    if(x<=8 && x !=0 && x>0){
  x=x+1;
  king[x][y]=board_coordinate[x][y];
  }
  else{
   return 0;
  }
  return 1;
}
int LeftMove(){
    if(x>1 && x !=0 && x <=8){
  x=x-1;
  king[x][y]=board_coordinate[x][y];
  }
  else{
   return 0;
  }
  return 1;
}

int Left_UpMove(){
    if(x>1 && x !=0 && x <=8 && y>=1 && y <=8 && y!=0){
  x=x-1;
  y=y-1;
  king[x][y]=board_coordinate[x][y];
  }
  else{
   return 0;
  }
  return 1;
}
int Left_DownMove(){
    if(x>1 && x !=0 && x <=8){
  x=x-1;
  y=y+1;
  king[x][y]=board_coordinate[x][y];
  }
  else{
   return 0;
  }
  return 1;
}
int Right_UpMove(){
    if(x>1 && x !=0 && x <=8){
  y=y-1;
  x=x+1;
  king[x][y]=board_coordinate[x][y];
  }
  else{
   return 0;
  }
  return 1;
}
int Right_DownMove(){
    if(x>1 && x !=0 && x <=8){
  x=x+1;
  y=y+1;
  king[x][y]=board_coordinate[x][y];
  }
  else{
   return 0;
  }
  return 1;
}
void MoveSystemByTerminal(int turn){
  printf("--------\nMove setting:\nup\ndown\nright\nleft\nupleft\ndownleft\nupright\ndownright\n");
  display_board();
  for(int turnNow=0;turnNow<turn;){
      char AskMotion[ask];
      printf("~~~~~~\n");
      fixedFgets(AskMotion, 9);
      if (strncmp(AskMotion, "up", 3)==0)
      {
      fm=turnNow+=UpMove();
      display_board();
      MoveCounter(turn);
      }
      else if (strncmp(AskMotion, "down", 5)==0)
      {
      fm=turnNow+=DownMove();
      display_board();
      MoveCounter(turn);
      }
      else if (strncmp(AskMotion, "right", 6)==0)
      {
      fm=turnNow+=RightMove();
      display_board();
      MoveCounter(turn);
      }
      else if (strncmp(AskMotion, "left", 5)==0)
      {
      fm=turnNow+=LeftMove();
      display_board();
      MoveCounter(turn);
      }
      else if (strncmp(AskMotion, "upleft", 7)==0)
      {
      fm=turnNow+=Left_UpMove();
      display_board();
      MoveCounter(turn);
      }
        else if (strncmp(AskMotion, "downleft", 8)==0)
      {
      fm=turnNow+=Left_DownMove();
      display_board();
      MoveCounter(turn);
      }
        else if (strncmp(AskMotion, "upright", 8)==0)
      {
      fm=turnNow+=Right_UpMove();
      display_board();
      MoveCounter(turn);
      }
        else if (strncmp(AskMotion, "downright", 8)==0)
      {
      fm=turnNow+=Right_DownMove();
      display_board();
      MoveCounter(turn);
      }
    }
  }
