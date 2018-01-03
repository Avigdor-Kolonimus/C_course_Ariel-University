/**
*c file for my library for Connect Four game   
*Author Alexey Titov
*Version 3.0
**/
//hidden library
#include "ConnectFour.h"
void push(Stack_UNDO *stack, const int value) {
    if (stack->size >= STACK_MAX_SIZE) {
        exit(STACK_OVERFLOW);
    }
    stack->data[stack->size] = value;
    stack->size++;
}
int pop(Stack_UNDO *stack) {
    if (stack->size == 0) {
        exit(STACK_UNDERFLOW);
    }
    stack->size--;
    return stack->data[stack->size];
}
//the function prints the status of the board to the console
void PrintBoard(char *board)
{
    for(int i=0;i<ROW;i++)
    {
        for(int j=0;j<COLUMN;j++)
            printf("|%c",board[COLUMN*i +j]);
        puts("|");
    }
    for(int i=1;i<=COLUMN;i++)
        printf(" %d",i);
    puts("");
}
//the function prints out whose turn
void PrintTurn(char symbol)
{
    printf("Player %c, please enter a column number (or 0 to undo):\n",symbol);
}
//the function displays the results of the game
void PrintStatus(int status,char *board,char win)
{
    //there is a winner
    if (status==5)
    {
        PrintBoard(board);
        printf("\nPlayer %c wins!\n\n",win);
        puts("      ☆ *  .   ☆ \n    ☆  . ∧＿∧  n  * ☆ \n  kt━━━( ・∀・)/ . ━━━!!\n     . ⊂     ノ* ☆ \n   ☆ * (つ ノ .☆ \n       (ノ\n     You WIN!!!!");
        return;
    }
    //the board filled up without a winner
    if (status==6)
    {
        PrintBoard(board);       
        puts("It's a tie!");
        puts("         nn\n      （´･ω･）\n    ＿|  ⊃／(＿＿_\n  ／  └-(＿＿＿_／\n  ￣￣￣￣￣￣￣");
        return;
    }
    //invalid input
    if (status==1)
    {
        puts("Invalid input, bye-bye!");
        puts("         nn\n      （´･ω･）\n    ＿|  ⊃／(＿＿_\n  ／  └-(＿＿＿_／\n  ￣￣￣￣￣￣￣");
        return;
    }
}
//the function checks for 4 characters
int checkFour(char *board, int a, int b, int c, int d){
    return (board[a] == board[b] && board[b] == board[c] && board[c] == board[d] && board[a] != ' ');
}
//the function checks the horizontal for 4 matches
int horizontalCheck(char *board){
    int row, col, idx;
    const int WIDTH = 1;
    for(row = 0; row < ROW; row++){
       for(col = 0; col < COLUMN - 3; col++){
          idx = COLUMN * row + col;
          if(checkFour(board, idx, idx + WIDTH, idx + WIDTH * 2, idx + WIDTH * 3)){
             return 1;
          }
       }
    }
    return 0;
}
//the function checks the vertical for 4 matches
int verticalCheck(char *board){
    int row, col, idx;
    const int HEIGHT = 7;
    for(row = 0; row < ROW - 3; row++){
       for(col = 0; col < COLUMN; col++){
          idx = COLUMN * row + col;
          if(checkFour(board, idx, idx + HEIGHT, idx + HEIGHT * 2, idx + HEIGHT * 3)){
              return 1;
          }
       }
    }
    return 0;

}
//the function checks the diagonal for 4 matches
int diagonalCheck(char *board){
   int row, col, idx, count = 0;
   const int DIAG_RGT = 6, DIAG_LFT = 8;
   for(row = 0; row < ROW - 3; row++){
      for(col = 0; col < COLUMN; col++)
      {
        idx = COLUMN*row+col;
        if((count<=3 && checkFour(board,idx,idx+DIAG_LFT, idx+DIAG_LFT*2, idx+DIAG_LFT*3)) || (count>=3 && checkFour(board, idx, idx+DIAG_RGT, idx+DIAG_RGT*2, idx+DIAG_RGT*3)))
            return 1;
        count++;
      }
      count = 0;
   }
   return 0;
}
//the function displays the player's symbol on the board
int drop(int col,char player,char *board,int choice)
{
	if (choice==0)
    {
        for(int i=0;i<ROW;i++)
            if (board[i*COLUMN+col-1]!=' ')
            {
                board[i*COLUMN+col-1]=' ';
			    return -2;
            }
         return -2;
    }
    for(int i=ROW-1;i>=0;i--)
        if (board[i*COLUMN+col-1]==' ')
        {
            board[i*COLUMN+col-1]=player;
			return i;
        }
    return -1;
}
//the function checks whether a player has won
int checkWin(char *board)
{
    return (horizontalCheck(board) || verticalCheck(board) || diagonalCheck(board));
}
//the function initializes the board
void InitializationBoard(char *board)
{
    memset(board, ' ',ROW*COLUMN);
}
//the function prepares the beginning of the game
void StartGame(char *board)
{
    InitializationBoard(board);
    printf("  Welcome!\n");
    printf("    ∧,,∧\n   ( 'ω' )つ Game Start!!!\n   （m9 ＼ \n     ＼   ＼\n        ) ) ＼\n      ／／ ＼ ＼\n     (＿）   (＿)\n"); 
}
//the function checks if the string is a number
int isNum(char *str,int gamer,int *flag_point) 
{
    int i = 0;
    int res = 1,store=*flag_point,flag=0;
    if (isdigit(*str) || *str == '+' || *str == '-') 
    {
        for (i = 1; i < strlen(str) && str[i] != '\n'; ++i) 
        {
            if (!isdigit(str[i]))
            {
                if (str[i]=='.')
                {    
                    if (flag!=0)
                    {
                        res = 0;
                        *flag_point=store; 
                        break;
                    }
                    if (store==0)
                        *flag_point=gamer;  
                    flag++;
                    continue;    
                }
                res = 0;
                break;
            }
        }
    } else
        res = 0;
    return res;
}
//the function check input
int Turn(char *board,char player,int gamer,int *flag_point,int *check_int)
{
    char number[10];
    int column=0;
    PrintBoard(board);
    PrintTurn(player);
    gets(number);
    column=atoi(number);
    if (!isNum(number,gamer,flag_point))
        *check_int=1;
    return column;
}
//check that there was an integer entered between 0 and 7
void CheckPointInt(char *board,int flag_point,int check_int,int gamer)
{
    if (flag_point==gamer || check_int)
    {
        PrintStatus(1,board,' ');
        exit(1);
    }
}