#include "mainpagetest.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainpagetest w;
    w.show();

    return a.exec();
}
