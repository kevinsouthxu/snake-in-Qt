#include "mysnakewalltest.h"
QRect mysnakewalltest::createwall()
{
    QTime g;
    g=QTime::currentTime();
    qsrand(g.msec()+g.second()*1000);
    a=qrand()%35;
    b=qrand()%75;
    int c;int d;
    qsrand(g.msec()+g.second()*1012);
    c=qrand()%(480-50-10-10*a);
    d=qrand()%(880-50-10-10*b);
    QRect rect(50+a*10,50+b*10,c+10,d+10);
    return rect;
}
void mysnakewalltest::paintEvent(QPaintEvent *)
{
    if(snake1.istrulyover) {this->hide();}
        QPainter painter(this);
        if(!snake1.isRun)
       {snake1.init_Snake();
        food1.adjustfood();
        wall=createwall();
        display="play game now";
        scoreLabel="Score:";}
        if(snake1.returnscore()%10==5&&whetherthewall) {wall=createwall();whetherthewall=false;}
        while(wall.contains(food1.returnfood())) food1.adjustfood();
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
       //画墙
       painter.setPen(Qt::black);
       painter.setBrush(Qt::black);
       painter.drawRect(wall);
       //更新蛇
       if(snake1.returnhead()==food1.returnfood()) eat();
       if(wall.contains(snake1.returnhead())) snake1.isOver=true;
       snake1.Snake_update();
       if(snake1.isOver) display="game over now!";
       update();
}
void mysnakewalltest::eat()
{
    food1.adjustfood();
    while(wall.contains(food1.returnfood())) food1.adjustfood();
    snake1.isEat();
    whetherthewall=true;
}
