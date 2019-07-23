#include "snakeai.h"
void snakeai::keyPressEvent(QKeyEvent *key)
{switch(key->key())
    {case Qt::Key_Up:  if(!autoornot)snake1.direction=1;break;
    case Qt::Key_Down: if(!autoornot)snake1.direction=2;break;
    case Qt::Key_Left: if(!autoornot)snake1.direction=3;break;
    case Qt::Key_Right: if(!autoornot)snake1.direction=4;break;
    case Qt::Key_P: snake1.isPause=!snake1.isPause;break;
    case Qt::Key_R: if(snake1.isOver) snake1.reset();break;
    case Qt::Key_A:  autoornot=!autoornot;break;
    case Qt::Key_Escape: if(snake1.isOver) {snake1.istrulyover=true;}break;
    default:;
    }
}
void snakeai::initbfs()
{
    for(int i=0;i<43;i++)
      for(int j=0;j<83;j++)
      {visited[i][j]=false;
       parent[i][j].setX(-1);
       parent[i][j].setY(-1);
      }
    while(!s.isEmpty()) s.pop();
}

void snakeai::calcbfs() //广度优先遍历，得到的结果存储在parent中
{
    if(snake1.returnhead()==food1.returnfood()) return;
    QQueue<QPoint> tempque;
    QPoint temp(snake1.returnhead().x(),snake1.returnhead().y());
    bool flag;
    flag=true;
    visited[(snake1.returnhead().x()-50)/10][(snake1.returnhead().y()-50)/10]=true;
    tempque.enqueue(temp);

    while(!tempque.isEmpty())
    {
        temp=tempque.dequeue();
        if(temp.x()==food1.returnfood().x()&&temp.y()==food1.returnfood().y()) return;
        if((temp.y()-10)<50) flag=false;
        for(int i=1;i<snake1.returnlens();i++) {if(i>=snake1.returnlens()) break;
            if(snake1.returnbody()[i].contains(QPoint(temp.x(),temp.y()-10))&&flag) visited[(temp.x()-50)/10][(temp.y()-50-10)/10]=true;}
        if(flag&&!visited[(temp.x()-50)/10][(temp.y()-50-10)/10]&&(temp.y()-10)>=50){
            parent[(temp.x()-50)/10][(temp.y()-50-10)/10].setX(temp.x());
            parent[(temp.x()-50)/10][(temp.y()-50-10)/10].setY(temp.y());
            visited[(temp.x()-50)/10][(temp.y()-50-10)/10]=true;
            tempque.enqueue(QPoint(temp.x(),temp.y()-10));
        }
        flag=true;
        if((temp.y()+10)>870) flag=false;
        for(int i=1;i<snake1.returnlens();i++) {if(i>=snake1.returnlens()) break;
            if(snake1.returnbody()[i].contains(QPoint(temp.x(),temp.y()+10))&&flag) visited[(temp.x()-50)/10][(temp.y()-50+10)/10]=true;}
        if(flag&&!visited[(temp.x()-50)/10][(temp.y()-50+10)/10]&&(temp.y()+10)<=870){
            parent[(temp.x()-50)/10][(temp.y()-50+10)/10].setX(temp.x());
            parent[(temp.x()-50)/10][(temp.y()-50+10)/10].setY(temp.y());
             visited[(temp.x()-50)/10][(temp.y()-50+10)/10]=true;
            tempque.enqueue(QPoint(temp.x(),temp.y()+10));
        }
        flag=true;
        if((temp.x()-10)<50) flag=false;
        for(int i=1;i<snake1.returnlens();i++) {if(i>=snake1.returnlens()) break;
            if(snake1.returnbody()[i].contains(QPoint(temp.x()-10,temp.y()))&&flag) visited[(temp.x()-50-10)/10][(temp.y()-50)/10]=true;}
        if(flag&&!visited[(temp.x()-50-10)/10][(temp.y()-50)/10]&&(temp.x()-10)>=50){
            parent[(temp.x()-50-10)/10][(temp.y()-50)/10].setX(temp.x());
            parent[(temp.x()-50-10)/10][(temp.y()-50)/10].setY(temp.y());
            visited[(temp.x()-50-10)/10][(temp.y()-50)/10]=true;
            tempque.enqueue(QPoint(temp.x()-10,temp.y()));
        }
        flag=true;
        if((temp.x()+10)>470) flag=false;
        for(int i=1;i<snake1.returnlens();i++) {if(i>=snake1.returnlens()) break;
            if(snake1.returnbody()[i].contains(QPoint(temp.x()+10,temp.y()))&&flag) visited[(temp.x()-50+10)/10][(temp.y()-50)/10]=true;}
        if(flag&&!visited[(temp.x()-50+10)/10][(temp.y()-50)/10]&&(temp.x()+10)<=470){
            parent[(temp.x()-50+10)/10][(temp.y()-50)/10].setX(temp.x());
            parent[(temp.x()-50+10)/10][(temp.y()-50)/10].setY(temp.y());
            visited[(temp.x()-50+10)/10][(temp.y()-50)/10]=true;
            tempque.enqueue(QPoint(temp.x()+10,temp.y()));
        }
        flag=true;}
        autoornot=false;
        snake1.isOver=true;
}
void snakeai::calcdirection()
{
    QPoint p(food1.returnfood().x(),food1.returnfood().y());
    QPoint temp;
    if(p.x()==snake1.returnhead().x()&&p.y()==snake1.returnhead().y()) return;
    if(snake1.isOver) return;
    s.push(p);
    while(!(p.x()==snake1.returnhead().x()&&p.y()==snake1.returnhead().y()))
    {
        temp=p;
        p.setX(parent[(temp.x()-50)/10][(temp.y()-50)/10].x());
        p.setY(parent[(temp.x()-50)/10][(temp.y()-50)/10].y());
        s.push(p);
    }
    s.pop();
    p=s.top();
    if(p.x()<snake1.returnhead().x()) {if(snake1.direction!=4)snake1.direction=3;else
            { if(snake1.returnhead().y()>=460) snake1.direction=1;else  snake1.direction=2;
            }return;}
    if(p.x()>snake1.returnhead().x()) {if(snake1.direction!=3)snake1.direction=4;else
            {  if(snake1.returnhead().y()>=460) snake1.direction=1;else  snake1.direction=2;
            }return;}
    if(p.y()<snake1.returnhead().y()) {if(snake1.direction!=2)snake1.direction=1;else
            {  if(snake1.returnhead().x()>=260) snake1.direction=3;else  snake1.direction=4;
            }return;}
    if(p.y()>snake1.returnhead().y()) {if(snake1.direction!=1)snake1.direction=2;else
            {  if(snake1.returnhead().x()>=460) snake1.direction=3;else  snake1.direction=4;
           }return;}
}
void snakeai::paintEvent(QPaintEvent *) //上下左右的方块分别为y-10，y+10，x-10，x+10,食物为50，50到470，870
{
    if(snake1.istrulyover) {this->hide();}
        QPainter painter(this);
        if(!snake1.isRun)
       {snake1.init_Snake();
        food1.adjustfood();
        display="play game now";
        scoreLabel="Score:";
        autoornot=true;
        }
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
       //更新蛇
       if(autoornot&&!snake1.isOver) {
           initbfs();
           calcbfs();
           calcdirection();
       }
       if(snake1.returnhead()==food1.returnfood()) eat();
       snake1.Snake_update();
       if(snake1.isOver) display="game over now!";
       update();
}
void snakeai::eat()
{
    food1.adjustfood();
    snake1.isEat();
    while(foodcontain())
        food1.adjustfood();
}
bool snakeai::foodcontain()
{
    for(int i=1;i<snake1.returnlens();i++) if(snake1.returnbody()[i].contains(food1.returnfood())) return true;
    return false;
}
