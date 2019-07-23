#include "mysnaketest.h"
#include "ui_mysnaketest.h"

mysnaketest::mysnaketest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mysnaketest)
{
    ui->setupUi(this);
    resize(930,930);
    setWindowTitle(tr("我是蛇"));
}

mysnaketest::~mysnaketest()
{
    delete ui;
}
void mysnaketest::keyPressEvent(QKeyEvent *key)
{switch(key->key())
    {case Qt::Key_Up: snake1.direction=1;break;
    case Qt::Key_Down: snake1.direction=2;break;
    case Qt::Key_Left: snake1.direction=3;break;
    case Qt::Key_Right: snake1.direction=4;break;
    case Qt::Key_P: snake1.isPause=!snake1.isPause;break;
    case Qt::Key_R: if(snake1.isOver) snake1.reset();break;
    case Qt::Key_Escape: if(snake1.isOver) {snake1.istrulyover=true;}break;
    default:;
    }
}
void mysnaketest::paintEvent(QPaintEvent *)
{
    if(snake1.istrulyover) {this->hide();}
        QPainter painter(this);
        if(!snake1.isRun)
       {snake1.init_Snake();
        food1.adjustfood();
        display="play game now";
        scoreLabel="Score:";}
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
       painter.drawText(622,300,scoreLabel);
       painter.drawText(722,300,QString::number(snake1.returnscore()));
       painter.drawText(622,400,"press p to pause");
       //if(snake1.returnhead().contains(QPoint(snake1.returnhead().x(),snake1.returnhead().y()))) painter.drawText(722,600,"true"); 测试语句
       //画蛇头
       painter.setPen(Qt::black);
       painter.setBrush(Qt::yellow);
       painter.drawRect(snake1.returnhead());
       //画蛇
       painter.setPen(Qt::black);
       painter.setBrush(Qt::black);
       painter.drawRects(snake1.returnbody()+1,snake1.returnlens()-1);
       //画吃的
       painter.setPen(Qt::green);
       painter.setBrush(Qt::green);
       painter.drawRect(food1.returnfood());
       //更新蛇
       if(snake1.returnhead()==food1.returnfood()) eat();
       snake1.Snake_update();
       if(snake1.isOver) display="game over now!";
       update();
}
void mysnaketest::eat()
{
    food1.adjustfood();
    snake1.isEat();
}
bool mysnaketest::overornot()
{
    return snake1.returntrulyover();
}
void mysnaketest::rebegin()
{
    snake1.rebegin();
}
