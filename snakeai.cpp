#include "snakeai.h"
void snakeai::keyPressEvent(QKeyEvent *key)
{switch(key->key())
    {case Qt::Key_Up:  if(!autoornot)snake1.direction=1;break;
    case Qt::Key_Down: if(!autoornot)snake1.direction=2;break;
    case Qt::Key_Left: if(!autoornot)snake1.direction=3;break;
    case Qt::Key_Right: if(!autoornot)snake1.direction=4;break;
    case Qt::Key_W:snake2.direction=1;break;
    case Qt::Key_S:snake2.direction=2;break;
    case Qt::Key_A:snake2.direction=3;break;
    case Qt::Key_D:snake2.direction=4;break;
    case Qt::Key_P: {snake1.isPause=!snake1.isPause;snake2.isPause=!snake2.isPause;break;}
    case Qt::Key_R: if(snake1.isOver) snake1.reset();break;
    case Qt::Key_O:  autoornot=!autoornot;break;
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
void snakeai::initvis()
{
    for(int i=0;i<43;i++)
      for(int j=0;j<83;j++)
      {visited[i][j]=false;
      }
    while(!s.isEmpty()) s.pop();
}
int snakeai::calcdis(QPoint point1, QPoint point2)
{
    int x;int y;
    x=point1.x()-point2.x();
    if(x<0) x-=(x*2);
    y=point1.y()-point2.y();
    if(y<0) y-=(y*2);
    return (x+y);
}
bool snakeai::canfindtail(int x,int y,Snake &snake1)
{   if(snake1.returnlens()==1) return true;
    if(snake1.returnhead()==food1.returnfood()) return true;
    initvis();
    QQueue<QPoint> tempque;
    QPoint temp(x,y);
    bool flag[4];
    for(int i=0;i<4;i++) flag[i]=true;
    visited[(x-50)/10][(y-50)/10]=true;
    tempque.enqueue(temp);
    for(int i=0;i<(snake1.returnlens()-1);i++) {
     visited[(snake1.returnbody()[i].x()-50)/10][(snake1.returnbody()[i].y()-50)/10]=true;}
    while(!tempque.isEmpty())
    {
        temp=tempque.dequeue();
        if(temp.x()==snake1.returntail().x()&&temp.y()==snake1.returntail().y()) return true;
        if((temp.y()-10)<50) flag[0]=false;
        if((temp.y()+10)>870) flag[1]=false;
        if((temp.x()-10)<50) flag[2]=false;
        if((temp.x()+10)>470) flag[3]=false;
        if(flag[0]&&!visited[(temp.x()-50)/10][(temp.y()-50-10)/10]&&(temp.y()-10)>=50){
            visited[(temp.x()-50)/10][(temp.y()-50-10)/10]=true;
            tempque.enqueue(QPoint(temp.x(),temp.y()-10));
        }
        if(flag[1]&&!visited[(temp.x()-50)/10][(temp.y()-50+10)/10]&&(temp.y()+10)<=870){
             visited[(temp.x()-50)/10][(temp.y()-50+10)/10]=true;
            tempque.enqueue(QPoint(temp.x(),temp.y()+10));
        }
        if(flag[2]&&!visited[(temp.x()-50-10)/10][(temp.y()-50)/10]&&(temp.x()-10)>=50){
            visited[(temp.x()-50-10)/10][(temp.y()-50)/10]=true;
            tempque.enqueue(QPoint(temp.x()-10,temp.y()));
        }
        if(flag[3]&&!visited[(temp.x()-50+10)/10][(temp.y()-50)/10]&&(temp.x()+10)<=470){
            visited[(temp.x()-50+10)/10][(temp.y()-50)/10]=true;
            tempque.enqueue(QPoint(temp.x()+10,temp.y()));
        }
        for(int i=0;i<4;i++) flag[i]=true;
    }
       return false;
}
bool snakeai::canfindfood(Snake &snake1)
{
    if(snake1.returnhead()==food1.returnfood()){ return true;}
    initbfs();
    QQueue<QPoint> tempque;
    QPoint temp(snake1.returnhead().x(),snake1.returnhead().y());
    bool flag[4];
    for(int i=0;i<4;i++) flag[i]=true;
    visited[(snake1.returnhead().x()-50)/10][(snake1.returnhead().y()-50)/10]=true;
    tempque.enqueue(temp);
    for(int i=1;i<snake1.returnlens();i++) {if(i>=snake1.returnlens()) break;
    visited[(snake1.returnbody()[i].x()-50)/10][(snake1.returnbody()[i].y()-50)/10]=true;}
    while(!tempque.isEmpty())
    {
        temp=tempque.dequeue();
        if(temp.x()==food1.returnfood().x()&&temp.y()==food1.returnfood().y())
            return true;
        if((temp.y()-10)<50) flag[0]=false;
        if((temp.y()+10)>870) flag[1]=false;
        if((temp.x()-10)<50) flag[2]=false;
        if((temp.x()+10)>470) flag[3]=false;
        if(flag[0]&&!visited[(temp.x()-50)/10][(temp.y()-50-10)/10]&&(temp.y()-10)>=50){
            parent[(temp.x()-50)/10][(temp.y()-50-10)/10].setX(temp.x());
            parent[(temp.x()-50)/10][(temp.y()-50-10)/10].setY(temp.y());
            visited[(temp.x()-50)/10][(temp.y()-50-10)/10]=true;
            tempque.enqueue(QPoint(temp.x(),temp.y()-10));
        }
        if(flag[1]&&!visited[(temp.x()-50)/10][(temp.y()-50+10)/10]&&(temp.y()+10)<=870){
            parent[(temp.x()-50)/10][(temp.y()-50+10)/10].setX(temp.x());
            parent[(temp.x()-50)/10][(temp.y()-50+10)/10].setY(temp.y());
            visited[(temp.x()-50)/10][(temp.y()-50+10)/10]=true;
            tempque.enqueue(QPoint(temp.x(),temp.y()+10));
        }
        if(flag[2]&&!visited[(temp.x()-50-10)/10][(temp.y()-50)/10]&&(temp.x()-10)>=50){
            parent[(temp.x()-50-10)/10][(temp.y()-50)/10].setX(temp.x());
            parent[(temp.x()-50-10)/10][(temp.y()-50)/10].setY(temp.y());
            visited[(temp.x()-50-10)/10][(temp.y()-50)/10]=true;
            tempque.enqueue(QPoint(temp.x()-10,temp.y()));
        }
        if(flag[3]&&!visited[(temp.x()-50+10)/10][(temp.y()-50)/10]&&(temp.x()+10)<=470){
            parent[(temp.x()-50+10)/10][(temp.y()-50)/10].setX(temp.x());
            parent[(temp.x()-50+10)/10][(temp.y()-50)/10].setY(temp.y());
            visited[(temp.x()-50+10)/10][(temp.y()-50)/10]=true;
            tempque.enqueue(QPoint(temp.x()+10,temp.y()));
        }
        for(int i=0;i<4;i++) flag[i]=true;}
       return false;
}
void snakeai::calcbfs(Snake &snake1) //广度优先遍历，得到的结果存储在parent中
{
    if(snake1.returnhead()==food1.returnfood()) return;
    QQueue<QPoint> tempque;
    QPoint temp(snake1.returnhead().x(),snake1.returnhead().y());
    bool flag[4];
    for(int i=0;i<4;i++) flag[i]=true;
    visited[(snake1.returnhead().x()-50)/10][(snake1.returnhead().y()-50)/10]=true;
    tempque.enqueue(temp);
    for(int i=1;i<snake1.returnlens();i++) {if(i>=snake1.returnlens()) break;
    visited[(snake1.returnbody()[i].x()-50)/10][(snake1.returnbody()[i].y()-50)/10]=true;
    }
    while(!tempque.isEmpty())
    {
        temp=tempque.dequeue();
        if(temp.x()==food1.returnfood().x()&&temp.y()==food1.returnfood().y()) return;
        if((temp.y()-10)<50) flag[0]=false;
        if((temp.y()+10)>870) flag[1]=false;
        if((temp.x()-10)<50) flag[2]=false;
        if((temp.x()+10)>470) flag[3]=false;
        if(flag[0]&&!visited[(temp.x()-50)/10][(temp.y()-50-10)/10]&&(temp.y()-10)>=50){
            parent[(temp.x()-50)/10][(temp.y()-50-10)/10].setX(temp.x());
            parent[(temp.x()-50)/10][(temp.y()-50-10)/10].setY(temp.y());
            visited[(temp.x()-50)/10][(temp.y()-50-10)/10]=true;
            tempque.enqueue(QPoint(temp.x(),temp.y()-10));
        }    
        if(flag[1]&&!visited[(temp.x()-50)/10][(temp.y()-50+10)/10]&&(temp.y()+10)<=870){
            parent[(temp.x()-50)/10][(temp.y()-50+10)/10].setX(temp.x());
            parent[(temp.x()-50)/10][(temp.y()-50+10)/10].setY(temp.y());
             visited[(temp.x()-50)/10][(temp.y()-50+10)/10]=true;
            tempque.enqueue(QPoint(temp.x(),temp.y()+10));
        }       
        if(flag[2]&&!visited[(temp.x()-50-10)/10][(temp.y()-50)/10]&&(temp.x()-10)>=50){
            parent[(temp.x()-50-10)/10][(temp.y()-50)/10].setX(temp.x());
            parent[(temp.x()-50-10)/10][(temp.y()-50)/10].setY(temp.y());
            visited[(temp.x()-50-10)/10][(temp.y()-50)/10]=true;
            tempque.enqueue(QPoint(temp.x()-10,temp.y()));
        }        
        if(flag[3]&&!visited[(temp.x()-50+10)/10][(temp.y()-50)/10]&&(temp.x()+10)<=470){
            parent[(temp.x()-50+10)/10][(temp.y()-50)/10].setX(temp.x());
            parent[(temp.x()-50+10)/10][(temp.y()-50)/10].setY(temp.y());
            visited[(temp.x()-50+10)/10][(temp.y()-50)/10]=true;
            tempque.enqueue(QPoint(temp.x()+10,temp.y()));
        }
        for(int i=0;i<4;i++) flag[i]=true;}
}
void snakeai::calctailbfs(Snake &snake1) //广度优先遍历，得到的结果存储在parent中
{
    if(snake1.returnhead()==food1.returnfood()) return;
    QQueue<QPoint> tempque;
    QPoint temp(snake1.returnhead().x(),snake1.returnhead().y());
    bool flag[4];
    for(int i=0;i<4;i++) flag[i]=true;
    visited[(snake1.returnhead().x()-50)/10][(snake1.returnhead().y()-50)/10]=true;
    tempque.enqueue(temp);
    for(int i=1;i<snake1.returnlens()-1;i++) {if(i>=snake1.returnlens()-1) break;
    visited[(snake1.returnbody()[i].x()-50)/10][(snake1.returnbody()[i].y()-50)/10]=true;
    }
    while(!tempque.isEmpty())
    {
        temp=tempque.dequeue();
        if(temp.x()==snake1.returntail().x()&&temp.y()==snake1.returntail().y()) return;
        if((temp.y()-10)<50) flag[0]=false;
        if((temp.y()+10)>870) flag[1]=false;
        if((temp.x()-10)<50) flag[2]=false;
        if((temp.x()+10)>470) flag[3]=false;
        if(flag[0]&&!visited[(temp.x()-50)/10][(temp.y()-50-10)/10]&&(temp.y()-10)>=50){
            parent[(temp.x()-50)/10][(temp.y()-50-10)/10].setX(temp.x());
            parent[(temp.x()-50)/10][(temp.y()-50-10)/10].setY(temp.y());
            visited[(temp.x()-50)/10][(temp.y()-50-10)/10]=true;
            tempque.enqueue(QPoint(temp.x(),temp.y()-10));
        }
        if(flag[1]&&!visited[(temp.x()-50)/10][(temp.y()-50+10)/10]&&(temp.y()+10)<=870){
            parent[(temp.x()-50)/10][(temp.y()-50+10)/10].setX(temp.x());
            parent[(temp.x()-50)/10][(temp.y()-50+10)/10].setY(temp.y());
             visited[(temp.x()-50)/10][(temp.y()-50+10)/10]=true;
            tempque.enqueue(QPoint(temp.x(),temp.y()+10));
        }
        if(flag[2]&&!visited[(temp.x()-50-10)/10][(temp.y()-50)/10]&&(temp.x()-10)>=50){
            parent[(temp.x()-50-10)/10][(temp.y()-50)/10].setX(temp.x());
            parent[(temp.x()-50-10)/10][(temp.y()-50)/10].setY(temp.y());
            visited[(temp.x()-50-10)/10][(temp.y()-50)/10]=true;
            tempque.enqueue(QPoint(temp.x()-10,temp.y()));
        }
        if(flag[3]&&!visited[(temp.x()-50+10)/10][(temp.y()-50)/10]&&(temp.x()+10)<=470){
            parent[(temp.x()-50+10)/10][(temp.y()-50)/10].setX(temp.x());
            parent[(temp.x()-50+10)/10][(temp.y()-50)/10].setY(temp.y());
            visited[(temp.x()-50+10)/10][(temp.y()-50)/10]=true;
            tempque.enqueue(QPoint(temp.x()+10,temp.y()));
        }
        for(int i=0;i<4;i++) flag[i]=true;}
}
void snakeai::calcempty(Snake &snake1) //广度优先遍历，得到的结果存储在parent中
{
    if(snake1.returnhead()==food1.returnfood()) return;
    QPoint temp(snake1.returnhead().x(),snake1.returnhead().y());
    bool flag[4];
    for(int i=0;i<4;i++) flag[i]=true;
    for(int i=1;i<snake1.returnlens();i++) {if(i>=snake1.returnlens()) break;
        visited[(snake1.returnbody()[i].x()-50)/10][(snake1.returnbody()[i].y()-50)/10]=true;
    }
        if((temp.y()-10)<50) flag[0]=false;
        if((temp.y()+10)>870) flag[1]=false;
        if((temp.x()-10)<50) flag[2]=false;
        if((temp.x()+10)>470) flag[3]=false;
    switch(snake1.direction)
    {
    case 1:{if(flag[0]&&!visited[(temp.x()-50)/10][(temp.y()-50-10)/10]) {snake1.direction=1;break;}
            if(flag[2]&&!visited[(temp.x()-50-10)/10][(temp.y()-50)/10]) {snake1.direction=3;break;}
            if(flag[3]&&!visited[(temp.x()-50+10)/10][(temp.y()-50)/10]) {snake1.direction=4;break;} break;}
    case 2:{if(flag[1]&&!visited[(temp.x()-50)/10][(temp.y()-50+10)/10]) {snake1.direction=2;break;}
            if(flag[2]&&!visited[(temp.x()-50-10)/10][(temp.y()-50)/10]) {snake1.direction=3;break;}
            if(flag[3]&&!visited[(temp.x()-50+10)/10][(temp.y()-50)/10]) {snake1.direction=4;break;} break;}
    case 3:{if(flag[2]&&!visited[(temp.x()-50-10)/10][(temp.y()-50)/10]) {snake1.direction=3;break;}
            if(flag[0]&&!visited[(temp.x()-50)/10][(temp.y()-50-10)/10]) {snake1.direction=1;break;}
            if(flag[1]&&!visited[(temp.x()-50)/10][(temp.y()-50+10)/10]) {snake1.direction=2;break;} break;}
    case 4:{if(flag[3]&&!visited[(temp.x()-50+10)/10][(temp.y()-50)/10]) {snake1.direction=4;break;}
            if(flag[0]&&!visited[(temp.x()-50)/10][(temp.y()-50-10)/10]) {snake1.direction=1;break;}
            if(flag[1]&&!visited[(temp.x()-50)/10][(temp.y()-50+10)/10]) {snake1.direction=2;break;} break;}
    default:;
    }

}
void snakeai::calcdirection(Snake &snake,int x,int y)
{
    QPoint p(x,y);
    QPoint temp;
    if(p.x()==snake.returnhead().x()&&p.y()==snake.returnhead().y()) return;
    s.push(p);
    while(!(p.x()==snake.returnhead().x()&&p.y()==snake.returnhead().y()))
    {
        temp=p;
        p.setX(parent[(temp.x()-50)/10][(temp.y()-50)/10].x());
        p.setY(parent[(temp.x()-50)/10][(temp.y()-50)/10].y());
        s.push(p);
    }
    s.pop();
    p=s.top();
    if(p.x()<snake.returnhead().x()) {if(snake.direction!=4)snake.direction=3;else
            { if(snake.returnhead().y()>=460) snake.direction=1;else  snake.direction=2;
            }return;}
    if(p.x()>snake.returnhead().x()) {if(snake.direction!=3)snake.direction=4;else
            {  if(snake.returnhead().y()>=460) snake.direction=1;else  snake.direction=2;
            }return;}
    if(p.y()<snake.returnhead().y()) {if(snake.direction!=2)snake.direction=1;else
            {  if(snake.returnhead().x()>=260) snake.direction=3;else  snake.direction=4;
            }return;}
    if(p.y()>snake.returnhead().y()) {if(snake.direction!=1)snake.direction=2;else
            {  if(snake.returnhead().x()>=460) snake.direction=3;else  snake.direction=4;
           }return;}
}
void snakeai::paintEvent(QPaintEvent *) //上下左右的方块分别为y-10，y+10，x-10，x+10,食物为50，50到470，870
{
    if(snake1.istrulyover) {this->hide();}
        QPainter painter(this);
        if(!snake1.isRun)
       {snake1.init_Snake();
        snake2.init_Snake();
        food1.adjustfood();
        display="play game now";
        scoreLabel="snakeai,score:";
        scoreLabel1="snake2,Score:";
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
       //ai
       simpleai();
        //更新蛇
       if(snake1.returnhead()==food1.returnfood()) {eat();}
       if(snake2.returnhead()==food1.returnfood()) eat1();
       snake1.Snake_update();
       snake2.Snake_update();
       hit();
       if(snake1.isOver&&snake2.isOver) display="game over now!";
       update();
}
void snakeai::simpleai()
{
    if(autoornot&&!snake1.isOver) {

        if(canfindfood(snake1))
                {
                calcdirection(snake1,food1.returnfood().x(),food1.returnfood().y());
                }
       else if(canfindtail(snake1.returnhead().x(),snake1.returnhead().y(),snake1))
          {
            initbfs();
            calctailbfs(snake1);
            calcdirection(snake1,snake1.returntail().x(),snake1.returntail().y());
          }
          else{initbfs();
               calcempty(snake1);
          }
    }
}
void snakeai::eat()
{
    food1.adjustfood();
    snake1.isEat();
    while(foodcontain())
        food1.adjustfood();
}
void snakeai::eat1()
{
    food1.adjustfood();
    snake2.isEat();
    while(foodcontain())
        food1.adjustfood();
}
bool snakeai::foodcontain()
{
    for(int i=1;i<snake1.returnlens();i++) if(snake1.returnbody()[i].contains(food1.returnfood())) return true;
    for(int i=1;i<snake2.returnlens();i++) if(snake1.returnbody()[i].contains(food1.returnfood())) return true;
    return false;
}
void snakeai::hit()
{int len1=snake1.returnlens();int len2=snake2.returnlens();int max=0;
    if(len1>len2)max=len1; else max=len2;
    if(snake2.returnbody()[0]==snake1.returnbody()[0]) {display="game over now!";snake1.isOver=true;snake2.isOver=true;update();}
    for(int t=1;t<max;t++)
    {
        if(t<len1)
            if(snake2.returnbody()[0]==snake1.returnbody()[t])
        {
        display="snakehuman dead!";
        snake2.isOver=true;
        }
        if(t<len2)
            if(snake1.returnbody()[0]==snake2.returnbody()[t])
        {
        display="snakeai dead!";
        snake1.isOver=true;
        }
    }
}
bool snakeai::overornot()
{
    return snake1.returntrulyover();
}
void snakeai::rebegin()
{
    snake1.rebegin();
    snake2.rebegin();
}

