#ifndef MYSNAKEFOODTEST_H
#define MYSNAKEFOODTEST_H
#include "snake.h"
#include "foodspecial.h"
#include <QWidget>
#include <QWidget>
#include<QPainter>
#include<QKeyEvent>
#include<QString>
#include<QFont>
namespace Ui {
class mysnakefoodtest;
}

class mysnakefoodtest : public QWidget
{
    Q_OBJECT

public:
    explicit mysnakefoodtest(QWidget *parent = nullptr);
    ~mysnakefoodtest();
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *key);
    void eat();
    bool overornot();
    void rebegin();
protected:
    Snake snake1;
    foodspecial food1;
    QString display;
    QString scoreLabel;
private:
    Ui::mysnakefoodtest *ui;
};
#endif // MYSNAKEFOODTEST_H
