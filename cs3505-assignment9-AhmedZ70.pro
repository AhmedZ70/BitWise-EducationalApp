QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    LevelsView.cpp \
    circuitLevel.cpp \
    customlineedit.cpp \
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
    main.cpp \
    mainwindow.cpp

HEADERS += \
    LevelsView.h \
    circuitLevel.h \
    customlineedit.h \
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
    mainwindow.h

FORMS += \
    LevelsView.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
