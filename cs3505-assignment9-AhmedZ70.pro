QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    circuit.cpp \
    circuitLevel.cpp \
    events.cpp \
    gameModel.cpp \
    gate.cpp \
    levelEight.cpp \
    levelFive.cpp \
    levelFour.cpp \
    levelNine.cpp \
    levelSeven.cpp \
    levelSix.cpp \
    levelThree.cpp \
    levelTwo.cpp \
    levelone.cpp \
    levels.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    circuit.h \
    circuitLevel.h \
    events.h \
    gameModel.h \
    gate.h \
    levelEight.h \
    levelFive.h \
    levelFour.h \
    levelNine.h \
    levelSeven.h \
    levelSix.h \
    levelThree.h \
    levelTwo.h \
    levelone.h \
    levels.h \
    logicgate.h \
    mainwindow.h

FORMS += \
    levels.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
