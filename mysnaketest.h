#ifndef MYSNAKETEST_H
#define MYSNAKETEST_H
#include "snake.h"
#include "food.h"
#include <QWidget>
#include<QPainter>
#include<QKeyEvent>
#include<QString>
#include<QFont>
namespace Ui {
class mysnaketest;
}

class mysnaketest : public QWidget
{
    Q_OBJECT

public:
    explicit mysnaketest(QWidget *parent = nullptr);
    ~mysnaketest();
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *key);
    void eat();
    bool overornot();
    void rebegin();
protected:
    Snake snake1;
    food food1;
    QString display;
    QString scoreLabel;
private:
    Ui::mysnaketest *ui;
};

#endif // MYSNAKETEST_H
