/**
*main for question 2 from assignment 4
*Author Alexey Titov
*Version 1.0
**/
//library
#include "IsStringBalanced.h"

int main()
{
    char *wordsT[] = {"if(x[i]>x[j])", "{return true;}"};
    char *wordsF[] = {"if(x[i]>x[j)", "{return false;}"};
    printf("True: if(x[i]>x[j]){return true;}\n");
    if (isStringBalanced(wordsT, CNTWORDS))
        printf("true");
    else
        printf("false");
    printf("\nFalse: if(x[i]>x[j){return false;}\n");
    if (isStringBalanced(wordsF, CNTWORDS))
        printf("true");
    else
        printf("false");  
    return 0;
}