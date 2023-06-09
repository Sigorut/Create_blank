QT       += core gui webenginewidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    add_ex.cpp \
    edit_ex.cpp \
    main.cpp \
    mainwindow.cpp \
    view_28line.cpp

HEADERS += \
    add_ex.h \
    edit_ex.h \
    mainwindow.h \
    view_28line.h

FORMS += \
    add_ex.ui \
    edit_ex.ui \
    mainwindow.ui \
    view_28line.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    html/html.qrc \
    icons/qrc.qrc \
    js/jsfile.qrc
