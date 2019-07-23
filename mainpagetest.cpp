#include "mainpagetest.h"
#include "ui_mainpagetest.h"
mainpagetest::mainpagetest(QWidget*parent):
   QWidget(parent)
{
    resize(930,930);
    setWindowTitle(tr("我是蛇"));
    tempflag=1;
    flag=0;
    this->grabKeyboard();
    x=290;
    time=startTimer(500);
}
void mainpagetest::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    if(!flag){
    //主页面的背景
    painter.setPen(Qt::black);
    painter.setBrush(Qt::black);
    painter.drawRect(0,0,930,930);
    //主页面的选项了啦
    QFont font1("微软雅黑",20);
    painter.setFont(font1);
    painter.setPen(Qt::white);
    painter.setBrush(Qt::white);
    painter.drawText(355,250,"经典单机");
    painter.drawText(355,350,"多人游戏");
    painter.drawText(355,450,"特殊食物");
    painter.drawText(355,550,"墙的随机产生");
    painter.drawText(355,650,"你想看AI？");
    //选项的图标
    painter.setPen(Qt::white);
    painter.setBrush(Qt::white);
    painter.drawEllipse(x,tempflag*100+120,20,20);
    update();

    }
    else{judge();
         }
}
void mainpagetest::timerEvent(QTimerEvent *event)
{
    if(event->timerId()==time&&flag!=0)
    {switch(flag){
    case 1:{if(snake1->overornot()) {snake1->close();this->show();flag=0;}break;}
    case 2:{if(snake2->overornot()) {snake2->close();this->show();flag=0;}break;}
    case 3:{if(snake3->overornot()) {snake3->close();this->show();flag=0;}break;}
    case 4:{if(snake4->overornot()) {snake4->close();this->show();flag=0;}break;}
    case 5:{if(snake5->overornot()) {snake5->close();this->show();flag=0;}break;}
    }}

}
void mainpagetest::keyPressEvent(QKeyEvent *key)
{
    if(flag==0)
    {switch(key->key())
    {
    case Qt::Key_Return: {flag=tempflag;update();break;}
    case Qt::Key_Up: {if(tempflag>1) tempflag--;break;}
    case Qt::Key_Down: {if(tempflag<5) tempflag++;break;}
    case Qt::Key_Escape: this->close();break;
    default:;
    }}
    else{if(tempflag==1)snake1->keyPressEvent(key);
         if(tempflag==2)snake2->keyPressEvent(key);
         if(tempflag==3)snake3->keyPressEvent(key);
         if(tempflag==4)snake4->keyPressEvent(key);
         if(tempflag==5)snake5->keyPressEvent(key);}


}
void mainpagetest::judge()
{
    switch (flag) {
    case 1:{this->hide();snake1->rebegin(); snake1->show();break;}
    case 2:{this->hide();snake2->rebegin(); snake2->show();break;}
    case 3:{this->hide();snake3->rebegin(); snake3->show();break;}
    case 4:{this->hide();snake4->rebegin(); snake4->show();break;}
    case 5:{this->hide();snake5->rebegin(); snake5->show();break;}
    default:;
    }
}
mainpagetest::~mainpagetest()
{this->close();
}
