QT       +=\
    core gui
    widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    choosingthememenu.cpp \
    doublespinboxdelegate.cpp \
    matrixoperator.cpp \
    onematrixoperator.cpp \
    resultview.cpp

HEADERS += \
    inversamatriz.h \
    mainwindow.h \
    choosingthememenu.h \
    doublespinboxdelegate.h \
    matrixoperator.h \
    onematrixoperator.h \
    resultview.h

FORMS += \
    mainwindow.ui \
    choosingthememenu.ui \
    matrixoperator.ui \
    onematrixoperator.ui \
    resultview.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
