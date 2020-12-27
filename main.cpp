// main.cpp

#include <QtGlobal>
#include <QString>
#include <QDebug>
#include <QCoreApplication>
#include <QStringView> //  Qt 5.10 or higher version

//----------------------
// #include <QtCore5Compat> // you may use this header.
#include <QtCore5Compat/QStringRef> // QStringRef : Qt4.3 ~ Qt5
//----------------------

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

#if QT_VERSION_MAJOR == 6
    // custom code for Qt 6 or higer version
   qDebug() << "Qt version is six.";
#endif

#if QT_VERSION_MAJOR == 5
    // custom code for Qt 5
   qDebug() << "Qt version is five.";
#endif

#if QT_VERSION_MAJOR == 4
   // ? Are you still in use?
#endif

    QString qstr("Hello, Qt5 in Qt6.");

    // Qt5 class ( QStringRef )
    QStringRef sref( &qstr );
    qDebug() << "QStringRef" << sref;

    // Qt6 class ( QStringView )
    QStringView sv( qstr );
    qDebug() << "QStringView" << sv;

    return 0; // return a.exec();
}
