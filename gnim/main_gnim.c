/**
*Author Alexey Titov
*Version 2.0
**/
//libraries
#include <stdio.h>
#include "gnim.h"
//main
int main ()
{
    int X,Y,Z,flag=2;                              //X-first heap, Y-second heap, Z-third heap, flag-variables for definition win, game over and continue game
    printf("please enter 3 numbers\n");
    InPut(&X, &Y, &Z);   
    if (CheckFirstTurn(X,Y,Z))                                    //check if comp will start game
    {
        printf("packet sizes are\n%d %d %d\n",X,Y,Z);
        flag=States(&X, &Y, &Z);
    }
    else                                           //player will start game
        printf("You first\n");    
    while ((X!=0 || Y!=0 || Z!=0) && flag==2)
    {
        printf("packet sizes are\n%d %d %d\n",X,Y,Z);
        InPutGame(&X,&Y,&Z);                                //player choose number
        printf("packet sizes are\n%d %d %d\n",X,Y,Z);
        flag=States(&X, &Y, &Z);                            //comp choose number
    }
    printf("Game Over-You Lost!!");
    return 0;
}