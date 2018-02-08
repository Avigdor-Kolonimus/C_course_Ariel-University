/**
*hidden file for question 3 from assignment 4
*Author Alexey Titov
*Version 1.0
**/
//libraries
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#define MAXLENGTH 10                   //maximum string length
//my class for 3.a
typedef struct myClass{
    int m_x;
    //add y to m_x
    void (*add) (struct myClass*, int);
}myClass;
//derived class for 3.b.1 (overriding)
typedef struct Derived{
    myClass derived;
}Derived;
//derived clas for 3.b.2 (extending)
typedef struct Derived2{
    int m_y;
    myClass derived;
    //add y to m_x and m_y=y
    void (*addMY) (struct Derived2*, int);
}Derived2;

//add y to m_x
void add(myClass* this, int y);
//add y to m_x and m_y=y
void addMY(Derived2* this, int y);
//XOR y and m_x
void XOR(myClass* this, int y);
//create a myClass
myClass createmyClass();
//create a Derived
Derived createDerived();
//create a Derived2
Derived2 createDerived2();