#include "mainwindow.h"

#include <QApplication>
#include <QSplashScreen>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSplashScreen *loadingScreen = new QSplashScreen;
    loadingScreen->setPixmap(QPixmap(":/icons/icon/loadScreen.png"));
    loadingScreen->show();

    MainWindow w;
    w.show();

    loadingScreen->finish(&w);
    delete loadingScreen;

    return a.exec();
}
