/**
*maiin file for question 1.b from assignment 4
*Author Alexey Titov
*Version 3.0
**/
//library
#include "Take2.h"
int main()
{ 
    char number[MAXLENGTH];
    char buffer[MAXLENGTH];
    int num_int;
    printf("enter the integer number if you want to check the take2(), if not then enter otherwise:\n");
    gets(number);
    num_int=atoi(number);
    sprintf(buffer, "%d", num_int);
    while(!strcmp (buffer,number))
    {
        printf("median= %d\n",take2(num_int));
        printf("enter the integer number if you want to check the take2(), if not then enter otherwise\n");
        gets(number);
        num_int=atoi(number);
        sprintf(buffer, "%d", num_int);
    }
  return 0;
}