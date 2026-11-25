QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# 源码目录，供 DatabaseManager 定位 hospital.db（Qt Creator 影子构建时也能找到）
DEFINES += LAB3_SOURCE_DIR=\\\"$$PWD\\\"

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    masterview.cpp \
    loginwidget.cpp \
    welcomewidget.cpp \
    patientwidget.cpp \
    patientdialog.cpp \
    databasemanager.cpp \
    sexdelegate.cpp

HEADERS += \
    masterview.h \
    loginwidget.h \
    welcomewidget.h \
    patientwidget.h \
    patientdialog.h \
    databasemanager.h \
    sexdelegate.h

FORMS += \
    loginwidget.ui \
    welcomewidget.ui \
    patientwidget.ui \
    patientdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
