/**
*main for Connect Four game
*Author Alexey Titov
*Version 3.0
**/
//hidden of library
#include "ConnectFour.h"
/**
 * Connect Four is a two-player connection game in which the players first choose a symbol(first-X,second-O)
 * and then take turns dropping symbols from the top into a seven-column, six-row vertically suspended grid. 
 * The pieces fall straight down, occupying the next available space within the column.
 * The objective of the game is to be the first to form a horizontal, vertical, or diagonal 
 * line of four of one's own symbol.
 * */
int main()
{
    //variables
    char board[ROW*COLUMN];
    char win_player=' ',player;
    int status=0,column=0,flag_point=0,check_drop=0,check_int=0,turn_gamer=0;
    //initialization
    Stack_UNDO stack;
    stack.size = 0;
    StartGame(board);
    //game
    for(int turn=0;;turn++)
    {
        //check if board is full
        if (stack.size==ROW*COLUMN)
        {
            status=6;
            break;
        }
        //check whose turn choise
        if (turn%2==0)
        {
            player=symbolX;
            turn_gamer=1;
        }
        else
        {
            player=symbolO;
            turn_gamer=2;
        }
        //the player set a fractional number
        CheckPointInt(board,flag_point,check_int,turn_gamer);
        column=Turn(board,player,turn_gamer,&flag_point,&check_int);
        //check that the player entered a number
        CheckPointInt(board,flag_point,check_int,-1);
        //the player chose UNDO but the stack is empty
        while (column==0 && stack.size==0)
        {
            puts("Board is empty - can't undo!");
            //check that the player entered a number or set a fractional number
            CheckPointInt(board,flag_point,check_int,turn_gamer);
            column=Turn(board,player,turn_gamer,&flag_point,&check_int);
        }
        //invalid input 
        while(column<0 || column>COLUMN)
        {
            puts("Invalid input, the number must be between 1 to 7:");
            //check that the player entered a number or set a fractional number
            CheckPointInt(board,flag_point,check_int,turn_gamer);
            column=Turn(board,player,turn_gamer,&flag_point,&check_int);
            //the player chose UNDO but the stack is empty
            while (column==0 && stack.size==0)
            {
                puts("Board is empty - can't undo!");
                //check that the player entered a number or set a fractional number
                CheckPointInt(board,flag_point,check_int,turn_gamer);
                column=Turn(board,player,turn_gamer,&flag_point,&check_int);
            }
        }
        //the player chose UNDO and the stack is not empty
        if (column==0)
            check_drop=drop(pop(&stack),player,board,column);
        else    //the player chose to enter his own character
            check_drop=drop(column,player,board,turn_gamer);
         //push selection in the stack, since the player chose to enter his own character
        if (check_drop!=-2 && check_drop!=-1)
        {
            push(&stack,column);
            check_drop=-2;
        }
        //the selected column is already full
        while(check_drop==-1)
        {
            //check that the player entered a number or set a fractional number
            CheckPointInt(board,flag_point,check_int,turn_gamer);
            puts("Invalid input, this column is full. Please choose another one:");
            column=Turn(board,player,turn_gamer,&flag_point,&check_int);
            //the player chose UNDO but the stack is empty
            while (column==0 && stack.size==0)
            {
                puts("Board is empty - can't undo!");
                 //check that the player entered a number or set a fractional number
                CheckPointInt(board,flag_point,check_int,turn_gamer);
                column=Turn(board,player,turn_gamer,&flag_point,&check_int);
            }
            //invalid input 
            while(column<0 || column>COLUMN)
            {
                //check that the player entered a number or set a fractional number
                CheckPointInt(board,flag_point,check_int,1);
                puts("Invalid input, the number must be between 1 to 7:");
                column=Turn(board,player,1,&flag_point,&check_int);
                //the player chose UNDO but the stack is empty
                while (column==0 && stack.size==0)
                {
                    puts("Board is empty - can't undo!");
                     //check that the player entered a number or set a fractional number
                    CheckPointInt(board,flag_point,check_int,1);
                    column=Turn(board,player,turn_gamer,&flag_point,&check_int);
                }
            }
            //the player chose UNDO and the stack is not empty
            if (column==0)
                check_drop=drop(pop(&stack),player,board,column);
            else    //the player chose to enter his own character
                check_drop=drop(column,player,board,turn_gamer);
        }
        //push selection in the stack, since the player chose to enter his own character
        if (check_drop!=-2)
            push(&stack,column);
        //check that the first player has won
        if (checkWin(board))
        {
           win_player=player;
           status=5;
           break; 
        }
    }
    //game result
    PrintStatus(status,board,win_player);
    return 1;
}