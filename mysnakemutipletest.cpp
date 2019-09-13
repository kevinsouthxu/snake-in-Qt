#include "mysnakemutipletest.h"
mysnakemutipletest::mysnakemutipletest(QWidget *parent) :
    QWidget(parent)
{
    resize(930,930);
    setWindowTitle(tr("我是蛇"));
}

mysnakemutipletest::~mysnakemutipletest()
{
}
void mysnakemutipletest::keyPressEvent(QKeyEvent *key)
{switch(key->key())
    {case Qt::Key_Up: snake1.direction=1;break;
    case Qt::Key_Down: snake1.direction=2;break;
    case Qt::Key_Left: snake1.direction=3;break;
    case Qt::Key_Right: snake1.direction=4;break;
    case Qt::Key_W:snake2.direction=1;break;
    case Qt::Key_S:snake2.direction=2;break;
    case Qt::Key_A:snake2.direction=3;break;
    case Qt::Key_D:snake2.direction=4;break;
    case Qt::Key_P: snake1.isPause=!snake1.isPause;snake2.isPause=!snake2.isPause;break;
    case Qt::Key_R: if(snake1.isOver&&snake2.isOver) {snake1.reset();snake2.reset();}break;
    case Qt::Key_Escape: if(snake1.isOver&&snake2.isOver) {snake1.istrulyover=true;snake2.istrulyover=true;}break;
    default:;
    }
}
void mysnakemutipletest::paintEvent(QPaintEvent *event)
{
    if(snake1.istrulyover) {this->hide();}
        QPainter painter(this);
        if(!snake1.isRun)
       {snake1.init_Snake();
        snake2.init_Snake();
        food1.adjustfood();
        display="play game now";
        scoreLabel="Snake1,Score:";
        scoreLabel1="snake2,Score:";}
       //playarea
       //把背景换了
       QPixmap image1;
       image1.load("../mysnaketest/4.jpg");
       painter.drawPixmap(0,0,930,930,image1);
       //wall
       painter.setPen(Qt::black);
       painter.setBrush(Qt::black);
       painter.drawRect(30,30,470,15);
       painter.drawRect(30,30,15,870);
       painter.drawRect(485,30,15,870);
       painter.drawRect(30,885,470,15);
       painter.setBrush(Qt::white);
       painter.drawRect(530,100,920,400);
       //显示开始、结束
       QFont font1("Microsoft YaHei",12);
       painter.setFont(font1);
       painter.setPen(Qt::red);
       painter.setBrush(Qt::red);
       painter.drawText(622,200,display);
       //计分
       QFont font2("Microsoft YaHei",12);
       painter.setFont(font2);
       painter.setPen(Qt::black);
       painter.setBrush(Qt::black);
       painter.drawText(542,300,scoreLabel);
       painter.drawText(542,400,scoreLabel1);
       painter.drawText(762,300,QString::number(snake1.returnscore()));
       painter.drawText(762,400,QString::number(snake2.returnscore()));
       painter.drawText(622,500,"press p to pause");
       //画蛇头
       painter.setPen(Qt::black);
       painter.setBrush(Qt::yellow);
       painter.drawRect(snake1.returnhead());
       painter.setPen(Qt::black);
       painter.setBrush(Qt::red);
       painter.drawRect(snake2.returnhead());
       //画蛇
       painter.setPen(Qt::black);
       painter.setBrush(Qt::black);
       painter.drawRects(snake1.returnbody()+1,snake1.returnlens()-1);
       painter.drawRects(snake2.returnbody()+1,snake2.returnlens()-1);
       //画吃的
       painter.setPen(Qt::green);
       painter.setBrush(Qt::green);
       painter.drawRect(food1.returnfood());
       //更新蛇
       if(snake1.returnhead()==food1.returnfood()) eat();
       if(snake2.returnhead()==food1.returnfood()) eat1();
       snake1.Snake_update();
       snake2.Snake_update();
       hit();
       if(snake1.isOver&&snake2.isOver) display="game over now!";
       update();
}
void mysnakemutipletest::hit()
{int len1=snake1.returnlens();int len2=snake2.returnlens();int max=0;
    if(len1>len2)max=len1; else max=len2;
    if(snake2.returnbody()[0]==snake1.returnbody()[0]) {display="game over now!";snake1.isOver=true;snake2.isOver=true;update();}
    for(int t=1;t<max;t++)
    {
        if(t<len1)
            if(snake2.returnbody()[0]==snake1.returnbody()[t])
        {
        display="snake2 dead!";
        snake2.isOver=true;
        }
        if(t<len2)
            if(snake1.returnbody()[0]==snake2.returnbody()[t])
        {
        display="snake1 dead!";
        snake1.isOver=true;
        }
    }
}
void mysnakemutipletest::eat()
{
    food1.adjustfood();
    snake1.isEat();
}
void mysnakemutipletest::eat1()
{
    food1.adjustfood();
    snake2.isEat();
}
bool mysnakemutipletest::overornot()
{
    return snake1.returntrulyover()&&snake2.returntrulyover();
}
void mysnakemutipletest::rebegin()
{
    snake1.rebegin();
    snake2.rebegin();
}
