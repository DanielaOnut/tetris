#include <iostream>
#include <QApplication>
#include <Window.h>

#include <CurrentSettings.h>

int main(int argumentCount, char ** argumentVector) {
    CurrentSettings::instance().load();

    QApplication a (argumentCount, argumentVector);
    Window w;
    w.init();
    w.show();

    return QApplication::exec();
}
