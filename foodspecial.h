#ifndef FOODSPECIAL_H
#define FOODSPECIAL_H
#include "food.h"
class foodspecial:public food
{
public:void adjustfood();
       QRect createRectspecial();
       int returnfoodtype(){return currentfoodtype;}
protected:
       int currentfoodtype;
};

#endif // FOODSPECIAL_H
