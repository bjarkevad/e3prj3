#include <QtGui/QApplication>
#include <QDebug>


#include "mainwindow.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

#ifdef TARGET
    QApplication::setOverrideCursor(Qt::BlankCursor);
#endif

    MainWindow w;
    /*qDebug() << QApplication::libraryPaths();
    qDebug() << QT_VERSION_STR;*/
    w.show();

    
    return a.exec();
}
