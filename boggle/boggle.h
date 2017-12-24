/**
*hidden file for my library for boggle game   
*Author Alexey Titov
*Version 3.0
**/
//libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//default variables
#define MATRIX_SIZE 4       //the size of row and column array
#define VARIATION   4       //4 for '+' and 8 for 'x+'
//check that we have not leave the boundaries of the array
//true-leave,false-did not leave
bool isOut(int i,int j);
//check that the word is in our dictionary
//true-the word is in the dictionary,false-the word is not in the dictionary
bool isWord(char *s);
//the function goes through all the variations to find the word
int searchWords(char boggle[MATRIX_SIZE][MATRIX_SIZE],int visited[MATRIX_SIZE][MATRIX_SIZE],char str[MATRIX_SIZE*MATRIX_SIZE+1],int i,int j,int index);
//the function prints the words and returns the number of words found in A array 
int printWords(char A[MATRIX_SIZE][MATRIX_SIZE]);