/**
*Author Alexey Titov
*Version 2.0
**/
//hidden of library
 #include "gnim.h"
 //the function of split. str-string for split, array- output array, length- number of output variables   
int dtmsplit(char *str , char ***array, int *length ) 
{
    int i=0;
    char *token;
    char **res = (char **) malloc(0 * sizeof(char *));
    //get the first token
    token = strtok(str, Separative);
    //get the following token
    while( token != NULL ) 
    {
        res = (char **) realloc(res, (i + 1) * sizeof(char *));
        res[i] = token;
        i++;
        token = strtok(NULL, Separative);
    }
    *array = res;
    *length = i;
    return 1;
}
//the function check if output of atoi is more than 1; return true if less, and false if more
bool CheckNum(int num)
{
    if (num<1)
        return true;
    return false;           
}
//the function sorts 3 numbers in ascending order
void Sort(int *A, int *B, int *C)
{
    if (*A>*B)
        SWAP(*A,*B);
    if (*B>*C)
        SWAP(*B,*C);
    if (*A>*B)
        SWAP(*A,*B);
}  
//The function receives and processes the entered data and assigns they to variables
void InPut(int *A, int *B, int *C)
{
    char **arr = NULL;
    int count =0; 
    char str[80];
    //input 3 numbers
    gets(str);
    dtmsplit(str, &arr, &count);
    //check if the player inputed 3 values
    while (count!=3)
    {
        printf ("input is not correct, enter 3 positive number\n");
        gets(str);
        dtmsplit(str, &arr, &count); 
    }
    //check if the entered data are numbers and positive
    while (CheckNum(atoi(arr[0])) || CheckNum(atoi(arr[1])) || CheckNum(atoi(arr[2])) )
    {
        printf ("input is not correct, enter 3 positive number\n");
        gets(str);
        dtmsplit(str, &arr, &count); 
    }
    //input is correct
    *A=atoi(arr[0]);
    *B=atoi(arr[1]);
    *C=atoi(arr[2]);
    Sort(A,B,C);
}
//comp choose
int States(int *A, int *B, int *C)
{
    if (*C>1 && *B==0 && *A==0)                         //first case
    {
        printf("I turned %d to 1\n",*C);
        *C=1;
        return 1;
    }
    if (*C>=1 && *B==1 && *A==0)                         //second case
    {
        printf("I turned %d to 0\n",*C);
        *C=0;
        return 1;
    }
    if (*C>=1 && *B==1 && *A==1)                         //third case
    {
        printf("I turned %d to 1\n",*C);
        *C=1;
        return 2;
    }
    //comp choose number for her turn
    int tmp;
    if ((*B+*A)<*C)
        tmp=*B+*A;
    else
        if (*C==*B && *A==1)
            tmp=0;
        else
            tmp=*B-*A;    
    printf("I turned %d to %d\n",*C,tmp);
    *C=tmp;
    Sort(A,B,C);                                        //sorting input
    return 2;
}
//replacement of number by new number
void NumToNum(int *A,int *B,int *C,int place,int num)
{
    if (place==1)                       //choose change first number
        *A=num;
    else
        if (place==2)                   //choose change second number
            *B=num;
        else
            *C=num;                     //choose change third number
}
//search what number the player wants to change
int Find(int *A, int *B, int *C,int num)
{
    if (*A==num)                        //*A-first heap
        return 1;                       
    if (*B==num)                        //*B-second heap
        return 2;
    if (*C==num)                        //*C-third heap
        return 3;
    return 0;                           //heap is not with that size.
}
//the function check if output of atoi is more than 1; return true if less, and false if more
bool CheckNewNum(char *ch1,char *ch2)
{
    if (atoi(ch2)>=atoi(ch1) || atoi(ch2)<0)    //the new number is less than zero or greater than the old number
        return true;
    return false;           
}
//input and check the entered numbers for start the game
void InPutGame(int *A, int *B, int *C)
{
    char **arr = NULL;
    int count =0; 
    char str[80];
    char *ch1, *ch2;
    //input 3 numbers
    gets(str);
    dtmsplit(str, &arr, &count);
    //check if the player inputed 3 values
    while (count!=3)
    {
        printf ("input is not correct, enter 'number' to 'number'\n");
        gets(str);
        dtmsplit(str, &arr, &count); 
    }
    //check if the entered data are positive numbers and "to"
    ch2=arr[2];
    ch1=arr[0];
    while (atoi(arr[0])==0 || Find(A,B,C,atoi(arr[0]))==0 || strcmp (arr[1], "to")!=0 || CheckNewNum(ch1,ch2))
    {
        printf ("input is not correct, enter 'number' to 'number'\n");
        gets(str);
        dtmsplit(str, &arr, &count); 
    }
    //input is correct
    NumToNum(A,B,C,Find(A,B,C,atoi(arr[0])),atoi(arr[2]));
    Sort(A,B,C);
}
//the function check who start game. 1-comp, 0-player
int CheckFirstTurn(int A,int B,int C)
{
    if ((C==(A+B)) || (A==1 && B==1 && C==1))
        return 0;
    return 1;    
}