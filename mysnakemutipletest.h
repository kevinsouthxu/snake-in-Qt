#ifndef MYSNAKEMUTIPLETEST_H
#define MYSNAKEMUTIPLETEST_H
#include "snake.h"
#include "snake1.h"
#include "food.h"
#include <QWidget>
#include <QWidget>
#include<QPainter>
#include<QKeyEvent>
#include<QString>
#include<QFont>
class mysnakemutipletest : public QWidget
{
    Q_OBJECT

public:
    explicit mysnakemutipletest(QWidget *parent = nullptr);
    ~mysnakemutipletest();
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *key);
    void eat();
    void eat1();
    void hit();
    bool overornot();
    void rebegin();
protected:
    Snake snake1;
    Snake1 snake2;
    food food1;
    QString display;
    QString scoreLabel;
    QString scoreLabel1;

};
#endif // MYSNAKEMUTIPLETEST_H
