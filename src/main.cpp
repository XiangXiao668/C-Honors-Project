#include "../include/mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    //instantiates Qt GUI System
    QApplication a(argc, argv);
    //instantiates MainWindow and w allocates the main window to the stack
    MainWindow w;
    //makes window appear on the screen
    w.show();
    //runs the main event loop keeping everything working for thne GUI and allowing the window to stay open
    return a.exec();
}
