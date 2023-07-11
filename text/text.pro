QMAKE_CXXFLAGS += -std=c++11

TARGET = ex_05_text

LIBS += -L../general -lgeneral
PRE_TARGETDEPS += ../general/libgeneral.a

INCLUDEPATH = ../general

SOURCES += \
    main_text.cc \
    text_viewer.cc

HEADERS += \
    text_viewer.h \
    ../general/Dessinable.h \
    ../general/SupportADessin.h \
    ../general/Systeme.h \
    ../general/IntegrateurEulerCromer.h \
    ../general/IntegrateurRungeKutta.h \
    ../general/TissuRectangle.h \
    ../general/TissuDisque.h \
    ../general/TissuCompose.h \
    ../general/Contrainte.h \
    ../general/ContrainteCrochet.h \
    ../general/ContrainteImpulsion.h \
    ../general/ContrainteSin.h \
    ../general/constantes.h \
    ../general/Helper.h
