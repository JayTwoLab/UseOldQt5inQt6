// main.cpp

#include <QtGlobal>
#include <QString>
#include <QDebug>
#include <QCoreApplication>

/////////////////////////
#include <QtCore5Compat> /// TODO: append this header for old Qt5 code.
/////////////////////////

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString qstr("Hello, Qt5! int Qt6.");

    // Old Qt5 code.
    QStringRef sref( &qstr );
    qDebug() << sref;

#if QT_VERSION_MAJOR == 6
    // custom code for Qt 6 or higer version
   qDebug() << "six";
#endif

#if QT_VERSION_MAJOR == 5
    // custom code for Qt 5
   qDebug() << "five";
#endif

#if QT_VERSION_MAJOR == 4
   // ? Are you still in use?
#endif

    return 0; // return a.exec();
}
