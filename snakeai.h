#ifndef SNAKEAI_H
#define SNAKEAI_H
#include <QQueue>
#include <QStack>
#include "mysnaketest.h"
#include <QWidget>
class snakeai:public mysnaketest
{
public:
    void keyPressEvent(QKeyEvent *key);
    void paintEvent(QPaintEvent *event);
    void eat();
    bool foodcontain();
protected:
    void initbfs();
    void calcbfs();
    void calcdirection();
    bool autoornot=true;
    bool visited[43][83];
    QPoint parent[43][83];
   QStack<QPoint> s;
   Snake snake2;
};

#endif // SNAKEAI_H
