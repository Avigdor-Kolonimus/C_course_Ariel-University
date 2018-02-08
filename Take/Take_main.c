/**
*main file for question 1.a from assignment 4
*Author Alexey Titov
*Version 1.0
**/
//library
#include "Take.h"
int main () 
{
    char number[MAXLENGTH];
    char buffer [MAXLENGTH];
    int num_int;
    printf("enter the whole number if you want to check the take(), if not then enter otherwise:\n");
    gets(number);
    num_int=atoi(number);
    sprintf(buffer, "%d", num_int);
    while(!strcmp (buffer,number))
    {
        printf("middle= %d\n",take(num_int));
        printf("enter the whole number if you want to check the take(), if not then enter otherwise\n");
        gets(number);
        num_int=atoi(number);
        sprintf(buffer, "%d", num_int);
    }
}