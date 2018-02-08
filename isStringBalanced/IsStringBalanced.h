/**
*hidden file for question 2 from assignment 4
*Author Alexey Titov
*Version 1.0
**/
//libraries
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#define MAXLENGTH 256                   //maximum string length
#define CNTWORDS  2                     //number of words in array
// A structure to represent a stack
struct StackNode
{
    char data;
    struct StackNode* next;
};
//the function create new node 
struct StackNode* newNode(char data);
//the function check if stack is empty
int isEmpty(struct StackNode *root);
//the function enters a new character to stack
void push(struct StackNode** root, char data);
//the function returns from stack the character that is the first to exit.
char pop(struct StackNode** root);
//the function returns the character that is the first to exit
char peek(struct StackNode* root);
//the function checks if the correct placement of the brackets
bool isStringBalanced(char** sentence, int size);