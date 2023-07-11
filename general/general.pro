TEMPLATE = lib

CONFIG = staticlib
QMAKE_CXXFLAGS += -std=c++11

SOURCES = constantes.cc \
          Integrateur.cc \
          IntegrateurEulerCromer.cc \
          Masse.cc \
          Ressort.cc \
          Systeme.cc \
          Tissu.cc \
          Vecteur3D.cc \
          Contrainte.cc \
          ContrainteCrochet.cc \
          ContrainteImpulsion.cc \
          ContrainteSin.cc \
          IntegrateurRungeKutta.cc \
          TissuChaine.cc \
          TissuCompose.cc \
          TissuDisque.cc \
          TissuRectangle.cc 



HEADERS += \
    Systeme.h \
    Dessinable.h \
    SupportADessin.h \
    constantes.h \
    Helper.h \
    Integrateur.h \
    IntegrateurEulerCromer.h \
    Masse.h \
    Tissu.h \
    Vecteur3D.h \
    Contrainte.h \
    ContrainteCrochet.h \
    ContrainteImpulsion.h \
    ContrainteSin.h \
    IntegrateurRungeKutta.h \
    TissuChaine.h \
    TissuCompose.h \
    TissuDisque.h \
    TissuRectangle.h 

