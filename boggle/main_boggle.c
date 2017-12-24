/**
*main for boggle game 
*Author Alexey Titov
*Version 3.0
**/
//labraries
#include <stdio.h>
#include "boggle.h"
int main()
{
    //шnitialize the letter array
    char boggle[MATRIX_SIZE][MATRIX_SIZE] = {{'C','A','R','T'},
                                             {'E','T','A','K'},
                                             {'E','S','M','E'},
                                             {'L','L','P','N'}};
    printf("Following words of dictionary are present:\n");
    printf("TOTAL: %d (may be dubliacates)", printWords(boggle));
    return 0;
}
