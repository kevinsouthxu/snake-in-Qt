#include "foodspecial.h"
QRect foodspecial::createRectspecial()
{
    int t,q;
        QTime g;
        g=QTime::currentTime();
        qsrand(g.msec()+g.second()*1000);
        t=qrand()%39;
        q=qrand()%79;
        QRect rect(50+t*10,50+q*10,40,40);
        return rect;
}
void foodspecial::adjustfood()
{
    QTime g;
        g=QTime::currentTime();
        qsrand(g.msec()+g.second()*1000);
        currentfoodtype=qrand()%2;
        switch(currentfoodtype)
        {
        case 0:{temp_SnakeRect=createRect();break;}
        case 1:{temp_SnakeRect=createRectspecial();break;}
        default:;}
}
