TARGET = lbdatabase
TEMPLATE = lib
CONFIG += staticlib
QT += sql
DEFINES *= QT_USE_QSTRINGBUILDER

HEADERS += \
    Core/taskscheduler.h \
    Core/table.h \
    Core/row.h \
    Core/mappingattribute.h \
    Core/listattribute.h \
    Core/databaseattribute.h \
    Core/database.h \
    Core/attributevariant.h \
    Core/attribute.h \
    Core/singleton.h \
    Gui/connectabletablewidgetitem.h \
    Models/tablemodel.h \
    LBDatabase.h

SOURCES += \
    Core/taskscheduler.cpp \
    Core/table.cpp \
    Core/row.cpp \
    Core/mappingattribute.cpp \
    Core/listattribute.cpp \
    Core/databaseattribute.cpp \
    Core/database.cpp \
    Core/attributevariant.cpp \
    Core/attribute.cpp \
    Core/singleton.cpp \
    Gui/connectabletablewidgetitem.cpp \
    Models/tablemodel.cpp

DESTDIR = ../lib
