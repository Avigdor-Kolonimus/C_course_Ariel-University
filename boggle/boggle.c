/**
*c file for my library for boggle game  
*Author Alexey Titov
*Version 3.0
**/
//hidden library
#include "boggle.h"
//global variables
int x[]={1,0,0,-1};         //'+' or 'x+' int x[]={1,1,1,0,0,-1,-1,-1};
int y[]={0,-1,1,0};         //'+' or 'x+' int y[]={1,0,-1,-1,1,0,-1,1};
//check that we have not leave the boundaries of the array
//true-leave,false-did not leave
bool isOut(int i,int j)
{
    if(i>=MATRIX_SIZE || i<0 || j>=MATRIX_SIZE || j<0)
        return true;
    return false;
}
//check that the word is in our dictionary
//true-the word is in the dictionary,false-the word is not in the dictionary
bool isWord(char *s)
{
    return (!strcmp(s,"CAT")   |
			!strcmp(s,"CATS")  |
			!strcmp(s,"TRAM")  |
			!strcmp(s,"TRAMS") |
			!strcmp(s,"TAME")  |
			!strcmp(s,"CAR")   |
			!strcmp(s,"CARS")  |
			!strcmp(s,"RAT")   |
			!strcmp(s,"RATS")  |
			!strcmp(s,"RAMP")  |
			!strcmp(s,"ART")   |
			!strcmp(s,"CART")  |
			!strcmp(s,"STAMP") |
			!strcmp(s,"TAKEN") |
			!strcmp(s,"MEN")   |
			!strcmp(s,"MAKE")  |
			!strcmp(s,"TAKE")  |
			!strcmp(s,"ATE")   |
			!strcmp(s,"SELL")  |
			!strcmp(s,"STEEL") |
			!strcmp(s,"RAKE") );
}
//the function goes through all the variations to find the word
int searchWords(char boggle[MATRIX_SIZE][MATRIX_SIZE],int visited[MATRIX_SIZE][MATRIX_SIZE],char str[MATRIX_SIZE*MATRIX_SIZE+1],int i,int j,int index)
{
    static int count = 0;           //counter for found words
    //check that we are within the borders and did not visit this place
    if(isOut(i,j) || visited[i][j])
        return count;
    //entering a letter to the string
    str[index++]=boggle[i][j];
    str[index]='\0';                    //end string
    visited[i][j]=1;                    //visited the place
    if(isWord(str))
    {
        puts(str);
        count++;
    }
    //variation
    for(int k=0;k<VARIATION;k++)
    {
        searchWords(boggle,visited,str,i+x[k],j+y[k],index);
    }
    str[strlen(str)-1]='\0';
    visited[i][j]=0;
    return count;
}
//the function prints the words and returns the number of words found in A array 
int printWords(char A[MATRIX_SIZE][MATRIX_SIZE])
{
    int cnt=0;                                      //counter for found words
    int visited[MATRIX_SIZE][MATRIX_SIZE]={0};      //initialization of the array of visited places
    //run on the array
    for(int i=0;i<MATRIX_SIZE;i++)
    {
        for(int j=0;j<MATRIX_SIZE;j++)
        {
            //initialization of the array of word
            char str[MATRIX_SIZE*MATRIX_SIZE+1];
            memset(str,'\0',MATRIX_SIZE*MATRIX_SIZE+1);
            cnt=searchWords(A,visited,str,i,j,0);
        }
    }
    return cnt;
}