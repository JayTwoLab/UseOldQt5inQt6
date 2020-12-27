# UseOldQt5inQt6

## Use Old Qt5 in Qt6 
  
:one: Set qmake(.pro) or cmake(CMakeList.txt).

- For qmake(.pro)

```qmake
QT += core5compat
```

- For cmake(CMakeList.txt)

```cmake
PUBLIC_LIBRARIES
Qt::Core5Compat
```

:two: Check old Qt5 class.
 
| Qt 5 Class       | Qt 6 Replacement   |
| ---------------- | ------------------ |
| QLinkedList      | std::list *        |
| QRegExp          | QRegularExpression |
| QStringRef       | QStringView        |
| QXmlSimpleReader | QXmlStreamReader   |
| QTextCodec       | QStringConverter   |
| QTextEncoder     | QStringEncoder     |
| QTextDecoder     | QStringDecoder     | 

- If you are planning a long-term upgrade, Upgrade old class to a new version of new class.

## Code

- UseOldQt5inQt6.pro

```pro
# UseOldQt5inQt6.pro

message( 'Qt major version : ' $$QT_MAJOR_VERSION ) # test in Qt6.

##################################
# TODO: Append for old Qt5 code.
QT += core5compat
##################################

QT -= gui

CONFIG += c++11
CONFIG += console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
```

- main.cpp

```cpp
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
```
 
## :kr: Qt6에서 구형 Qt5 사용하기
 - (Korean Blog) https://j2doll.tistory.com/671

  
