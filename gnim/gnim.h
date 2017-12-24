/**
*Author Alexey Titov
*Version 2.0
**/
//libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//defines
#define Separative " "                      //separative character
#define SWAP(a,b)({a+=b; b=a-b; a-=b;})     //macro function of swap
 //the function of split. str-string for split, array- output array, length- number of output variables   
int dtmsplit(char *str , char ***array, int *length );
//the function check if output of atoi is more than 1; return true if less, and false if more
bool CheckNum(int num);
//the function sorts 3 numbers in ascending order
void Sort(int *A, int *B, int *C);
//The function receives and processes the entered data and assigns they to variables
void InPut(int *A, int *B, int *C);
//comp choose
int States(int *A, int *B, int *C);
//replacement of number by new number
void NumToNum(int *A,int *B,int *C,int place,int num);
//search what number the player wants to change
int Find(int *A, int *B, int *C,int num);
//the function check if output of atoi is more than 1; return true if less, and false if more
bool CheckNewNum(char *ch1,char *ch2);
//input and check the entered numbers for start the game
void InPutGame(int *A, int *B, int *C);
//the function check who start game. 1-comp, 0-player
int CheckFirstTurn(int A,int B,int C);