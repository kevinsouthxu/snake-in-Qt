#include "food.h"
QRect food::createRect()
{
    int t,q;
    QTime g;
    g=QTime::currentTime();
    qsrand(g.msec()+g.second()*1000);
    t=qrand()%42;
    q=qrand()%82;
    QRect rect(50+t*10,50+q*10,10,10);
    return rect;
}
void food::adjustfood()
{
    temp_SnakeRect=createRect();
}
