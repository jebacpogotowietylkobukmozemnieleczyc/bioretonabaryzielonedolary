TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    maths.c \
    enemy.c \
    app.c \
    convexhull.c \
    triangles.c

INCLUDEPATH += "C:\allegro\include"
LIBS += "C:\allegro\lib\liballegro-4.4.2-md.a"

HEADERS += \
    enemy.h \
    maths.h \
    app.h \
    convexhull.h \
    triangle.h

