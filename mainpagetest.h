#ifndef MAINPAGETEST_H
#define MAINPAGETEST_H
#include "mysnaketest.h"
#include "mysnakefoodtest.h"
#include "mysnakewalltest.h"
#include "mysnakemutipletest.h"
#include "snakeai.h"
#include <QWidget>
#include <QDialog>
namespace Ui{
class mainpagetest;
}
class mainpagetest:public QWidget
{
Q_OBJECT
public:
  explicit mainpagetest(QWidget*parent=nullptr);
  ~mainpagetest();
  void judge();
  void paintEvent(QPaintEvent*event);
private slots:
private:
  void keyPressEvent(QKeyEvent *key);
  Ui::mainpagetest*ui;
  int flag;
  int tempflag;
  int x;
  mysnaketest *snake1=new mysnaketest;
  mysnakemutipletest *snake2=new mysnakemutipletest;
  mysnakefoodtest *snake3=new mysnakefoodtest;
  mysnakewalltest *snake4=new mysnakewalltest;
  snakeai *snake5=new snakeai;
  int time;
  void timerEvent(QTimerEvent *event);
};


#endif // MAINPAGETEST_H
