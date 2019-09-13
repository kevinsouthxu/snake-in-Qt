#include "snake.h"
Snake::Snake()
{
isRun=false;
isOver=false;
isPause=false;
}
Snake::~Snake()
{
    delete[]SnakeRect;
}
void Snake::timerEvent(QTimerEvent *event)
{
    if(event->timerId()==time&&!isOver&&!isPause)
    {for(int i=Snakelen-1;i>0;i--)
        SnakeRect[i]=SnakeRect[i-1];
        x+=x1*10;y+=y1*10;
   }
}
void Snake::init_Snake()
{
    x=50;y=50;
    Snakelen=1;
    direction=4;notletthesnakegoback=4;
    isRun=true;
    isOver=false;
    score=0;
    QRect rect(x,y,10,10);
    SnakeHeard=rect;
    SnakeRect=new QRect[Snakelen];
    SnakeRect[0]=SnakeHeard;
    time=startTimer(70);
}
void Snake::Snake_update()
{
    bool flag;
    flag=false;
    if(SnakeHeard.left()<50||SnakeHeard.right()>480||SnakeHeard.top()>870||SnakeHeard.bottom()<50)
    {
        isOver=true;
    }
    switch (direction)
    {case 1:if(notletthesnakegoback!=2) {y2=-1;x2=0;flag=true;}
        else {y2=1;x2=0;}
        break;
     case 2:if(notletthesnakegoback!=1) {y2=1;x2=0;flag=true;}
        else {y2=-1;x2=0;}
        break;
     case 3:if(notletthesnakegoback!=4) {x2=-1;y2=0;flag=true;}
        else {x2=1;y2=0;}
        break;
     case 4:if(notletthesnakegoback!=3) {x2=1;y2=0;flag=true;}
        else {x2=-1;y2=0;}
        break;
     default: ;
    }
        if(flag)
        notletthesnakegoback=direction;
        if(isPause)
        {x1=0;y1=0;}
        else {x1=x2;y1=y2;}
        QRect rect(x,y,10,10);
        SnakeHeard=rect;
        SnakeRect[0]=SnakeHeard;
        isHit();
}
void Snake::isEat()
{
        Snakelen++;
        QRect *tmp=new QRect[Snakelen-1];
        for(int i=0;i<Snakelen-1;++i)
            tmp[i]=SnakeRect[i];
        delete[] SnakeRect;
        SnakeRect= new QRect[Snakelen];
        for(int i=0;i<Snakelen-1;++i)
            SnakeRect[i]=tmp[i];
        score++;
        if(score<6)
            time=startTimer(70-score*5);
        else time=startTimer(40);
}
void Snake::isHit()
{
    for(int i=1;i<Snakelen;i++)
    {
        if(SnakeRect[0]==SnakeRect[i])
        {
            isOver=true;
        }
    }
}
void Snake::reset()
{
    isRun=false;
    isOver=!isOver;
}
void Snake::rebegin()
{
    istrulyover=false;
    isRun=false;
}
Snake &Snake::operator=(const Snake &snaketemp)
{
    if(this!=&snaketemp)
    {
        this->isRun=snaketemp.isRun;this->isOver=snaketemp.isOver;
        this->isPause=snaketemp.isPause;this->istrulyover=snaketemp.istrulyover;
        this->direction=snaketemp.direction;this->notletthesnakegoback=snaketemp.notletthesnakegoback;
        this->x=snaketemp.x;this->y=snaketemp.y;
        this->x1=snaketemp.x1;this->x2=snaketemp.x2;
        this->y1=snaketemp.y1;this->y2=snaketemp.y2;
        this->time=snaketemp.time;this->score=snaketemp.score;this->Snakelen=snaketemp.Snakelen;
        this->SnakeRect=new QRect[this->Snakelen];
        for(int i=0;i<snaketemp.Snakelen;i++)
            this->SnakeRect[i]=snaketemp.SnakeRect[i];
        this->SnakeHeard=snaketemp.SnakeHeard;
        return *this;
    }
    return *this;
}
