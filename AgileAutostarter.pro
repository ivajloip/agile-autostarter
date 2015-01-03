TEMPLATE = app
Debug:TARGET = debug/agileAutostarter
Release:TARGET = release/agileAutostarter
DEPENDPATH += .
CONFIG += qt debug_and_release warn_on
INCLUDEPATH += . 
QT += widgets

# Input
HEADERS += ApplicationsList.hpp \
           AutostartableApplication.hpp \
           BatteryStatusReader.hpp \
           MainWindow.hpp \
           Settings.hpp 
SOURCES += ApplicationsList.cpp \
           AutostartableApplication.cpp \
           BatteryStatusReader.cpp \
           MainWindow.cpp \
           Settings.cpp \
           main.cpp
