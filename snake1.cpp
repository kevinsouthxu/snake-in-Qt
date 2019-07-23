#include "snake1.h"
void Snake1::init_Snake()
{
    x=460;y=860;
    Snakelen=1;
    direction=3;notletthesnakegoback=3;
    isRun=true;
    isOver=false;
    score=0;
    QRect rect(x,y,10,10);
    SnakeHeard=rect;
    SnakeRect=new QRect[Snakelen];
    SnakeRect[0]=SnakeHeard;
    time=startTimer(70);
}
