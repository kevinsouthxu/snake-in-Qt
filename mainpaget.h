#ifndef MAINPAGET_H
#define MAINPAGET_H
#include "mysnaketest.h"
#include <QWidget>

namespace Ui {
class mainpaget;
}

class mainpaget : public QWidget
{
    Q_OBJECT

public:
    explicit mainpaget(QWidget *parent = nullptr);
    ~mainpaget();
    void judge();
    void paintEvent(QPaintEvent*event);
  private slots:
  private:
    void keyPressEvent(QKeyEvent *key);
    Ui::mainpaget*ui;
    int flag;
    int tempflag;
    int x;
    mysnaketest *snake1=new mysnaketest;
    int time;
    void timerEvent(QTimerEvent *event);

private:
    Ui::mainpaget *ui;
};

#endif // MAINPAGET_H
