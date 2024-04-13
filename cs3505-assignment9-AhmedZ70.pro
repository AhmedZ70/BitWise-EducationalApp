QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    circuit.cpp \
    gameModel.cpp \
    levelonewidget.cpp \
    levels.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    circuit.h \
    gameModel.h \
    levelonewidget.h \
    levels.h \
    mainwindow.h

FORMS += \
    levels.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
