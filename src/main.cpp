#include <iostream>
#include <QApplication>
#include <Window.h>

int main(int argumentCount, char ** argumentVector) {
    QApplication a (argumentCount, argumentVector);
    Window w;
    w.init();
    w.show();

    return QApplication::exec();
}
