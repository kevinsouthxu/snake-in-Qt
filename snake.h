#ifndef SNAKE_H
#define SNAKE_H
#include<QRect>
#include<QTimer>
#include<QTime>
#include<QTimerEvent>
#include<QObject>
class Snake:public QObject
{
    Q_OBJECT
public:
    Snake();
    ~Snake();
    int snaketime(){return time;}
    void init_Snake();
    void isHit();
    void isEat();
    int returnscore(){return score;}
    QRect returnhead(){return SnakeRect[0];}
    QRect* returnbody(){return SnakeRect;}
    QRect returntail(){return SnakeRect[Snakelen-1];}
    int returnlens(){return Snakelen;}
    int direction;
    int notletthesnakegoback;
    void rebegin();
    void reset();
    bool returntrulyover(){return istrulyover;}
    bool isRun;
    bool isOver;
    bool isPause;
    bool istrulyover;
    Snake &operator=(const Snake &snake);
public slots:
    void Snake_update();
protected:
void timerEvent(QTimerEvent *event);
int x;
int y;
int x1;
int x2;
int y1;
int y2;
int time;
int count;
QRect *SnakeRect;
QRect SnakeHeard;
int Snakelen;
int score;
QTimer *timer;
};

#endif // SNAKE_H
