QT += core gui opengl widgets
QMAKE_CXXFLAGS += -std=c++11

win32:LIBS += -lopengl32


TARGET = ex_05_gl

LIBS += -L../general -lgeneral
PRE_TARGETDEPS += ../general/libgeneral.a
INCLUDEPATH = ../general

SOURCES += \
    main_qt_gl.cc \
    glwidget.cc \
    glsphere.cc \
    vue_opengl.cc

HEADERS += \
    glwidget.h \
    vertex_shader.h \
    vue_opengl.h \
    glsphere.h \
    ../general/Dessinable.h \
    ../general/SupportADessin.h \
    ../general/Systeme.h \
    ../general/IntegrateurEulerCromer.h \
    ../general/IntegrateurRungeKutta.h \
    ../general/Tissu.h \
    ../general/TissuRectangle.h \
    ../general/TissuDisque.h \
    ../general/TissuCompose.h \
    ../general/TissuChaine.h \
    ../general/Contrainte.h \
    ../general/ContrainteCrochet.h \
    ../general/ContrainteImpulsion.h \
    ../general/ContrainteSin.h \
    ../general/constantes.h \
    ../general/Helper.h \

RESOURCES += \
    resource.qrc
