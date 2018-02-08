/**
*c file for hidden of question 3 from assignment 4
*Author Alexey Titov
*Version 1.0
**/
//library
#include "myclass.h"

//add y to m_x
void add(myClass* this, int y) 
{
    this->m_x+=y;
}
//add y to m_x and m_y=y
void addMY(Derived2* this, int y) 
{
    this->m_y=y;
    this->derived.add(&this->derived,y);
}
//XOR y and m_x
void XOR(myClass* this, int y)
{
    this->m_x=this->m_x^y;
}
//create a myClass
myClass createmyClass() 
{
    myClass my_class;
    my_class.m_x=0;
    my_class.add = &add;
    return my_class;
}
//create a Derived
Derived createDerived() 
{
    Derived d;
    d.derived=createmyClass();
    d.derived.add=&XOR;
    return d;
}
//create a Derived2
Derived2 createDerived2() 
{
    Derived2 d;
    d.m_y=0;
    d.derived=createmyClass();
    d.addMY=&addMY;
    return d;
}