/**
*hidden file for my library for Connect Four game  
*Author Alexey Titov
*Version 3.0
**/
//libraries
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//define variables
#define ROW     6
#define COLUMN  7
#define symbolX 'X'
#define symbolO 'O'
#define STACK_MAX_SIZE ROW*COLUMN
#define STACK_OVERFLOW  -100
#define STACK_UNDERFLOW -101
typedef struct Stack_tag {
    int data[STACK_MAX_SIZE];
    int size;
} Stack_UNDO;
void push(Stack_UNDO *stack, const int value);
int pop(Stack_UNDO *stack);
//the function prints the status of the board to the console
void PrintBoard(char *board);
//the function prints out whose turn
void PrintTurn(char symbol);
//the function displays the results of the game
void PrintStatus(int status,char *board,char win);
//the function checks for 4 characters
int checkFour(char *board, int a, int b, int c, int d);
//the function checks the horizontal for 4 matches
int horizontalCheck(char *board);
//the function checks the vertical for 4 matches
int verticalCheck(char *board);
//the function checks the diagonal for 4 matches
int diagonalCheck(char *board);
//the function displays the player's symbol on the board
int drop(int col,char player,char *board,int choice);
//the function checks whether a player has won
int checkWin(char *board);
//the function initializes the board
void InitializationBoard(char *board);
//the function prepares the beginning of the game
void StartGame(char *board);
//the function checks if the string is a number
int isNum(char *str,int gamer,int *flag_point);
//the function check input
int Turn(char *board,char player,int gamer,int *flag_point,int *check_int);
//check that there was an integer entered between 0 and 7
void CheckPointInt(char *board,int flag_point,int check_int,int gamer);