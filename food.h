#ifndef FOOD_H
#define FOOD_H
#include<QObject>
#include<QRect>
#include<QTime>
class food:public QObject
{Q_OBJECT
public:
    QRect createRect();
    void adjustfood();
    QRect returnfood(){return temp_SnakeRect;}
protected:
    QRect temp_SnakeRect;
};

#endif // FOOD_H
