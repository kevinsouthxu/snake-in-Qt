#ifndef SNAKEAI_H
#define SNAKEAI_H
#include <QQueue>
#include "snake1.h"
#include <qmath.h>
#include <QStack>
#include "mysnaketest.h"
#include <QWidget>
class snakeai:public mysnaketest
{
public:
    void keyPressEvent(QKeyEvent *key);
    void paintEvent(QPaintEvent *event);
    void eat();
    void eat1();
    void hit();
    bool foodcontain();
    bool overornot();
    void rebegin();
protected:
    bool canfindfood(Snake &snake1);
    bool canfindtail(int x,int y,Snake &snake1);
    void simpleai();
    void initbfs();
    void initvis();
    void calcbfs(Snake &snake);
    void calctailbfs(Snake &snake);
    void calcempty(Snake &snake);
    int calcdis(QPoint poin1,QPoint point2);
    void calcdirection(Snake &snake1,int x,int y);
    bool autoornot=true;
    bool visited[43][83];
    QPoint parent[43][83];
   QStack<QPoint> s;
   Snake1 snake2;
   QString scoreLabel1;
};

#endif // SNAKEAI_H
