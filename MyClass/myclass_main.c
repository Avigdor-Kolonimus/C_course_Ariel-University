/**
*main file for question 3 from assignment 4
*Author Alexey Titov
*Version 1.0
**/
//library
#include "myclass.h"
int main()
{
    char number[MAXLENGTH];
    char buffer [MAXLENGTH];
    int y;
    myClass  my_class = createmyClass();
    Derived  derived  = createDerived();
    Derived2 derived2 = createDerived2();
    //----------------------------------------------INITIALIZATION-------------------------------------
    printf("Initialization, m_x=%d\n",my_class.m_x);
    //-------------------------------------------------------------------------------------------------
    printf("enter y for add:\n");
    gets(number);
    y=atoi(number);
    sprintf(buffer, "%d", y);
    if (strcmp (buffer,number))     //y is incorrecr
        return 0;
    my_class.add(&my_class,y);
    printf("add(y), m_x=%d\n",my_class.m_x);
    //----------------------------------------------DERIVED--------------------------------------------
    derived.derived.m_x=12;
    derived.derived.add(&derived.derived,y);
    printf("12 XOR(y), m_x=%d\n",derived.derived.m_x);
    //----------------------------------------------DERIVED2-------------------------------------------
    derived2.addMY(&derived2,y);
    printf("add(y), m_x=%d   m_y=%d\n",derived2.derived.m_x,derived2.m_y);
    return 1;
}