#ifndef MYSNAKEWALLTEST_H
#define MYSNAKEWALLTEST_H
#include "mysnaketest.h"
class mysnakewalltest:public mysnaketest
{
public:
    void paintEvent(QPaintEvent *event);
    void eat();
protected:
    QRect createwall();
    int a;int b;
    QRect wall;
    bool whetherthewall=true;
};

#endif // MYSNAKEWALLTEST_H
