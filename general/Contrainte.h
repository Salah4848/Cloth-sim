#pragma once
#include "Dessinable.h"
#include "SupportADessin.h"
#include "Tissu.h"

class Contrainte : public Dessinable{
protected:
    Vecteur3D centre_;
    double rayon_;
    double temps_; //Comme la fonctions appliquer prend un parametre temps il sera utile de l'avoir comme attribut
public:
    Contrainte(Vecteur3D centre, double rayon) : centre_(centre),rayon_(rayon){}
    virtual ~Contrainte()=default;

    //Getters
    Vecteur3D getCentre() const{return centre_;}
    double getRayon() const{return rayon_;}

    //Methodes
    virtual void appliquer(Tissu& tissu, double temps) = 0;
    bool dans_champ(Vecteur3D const& pos) const;
    virtual void dessine_sur(SupportADessin& support) const override{support.dessine(*this);}
    virtual void dessinable(bool& b, Vecteur3D& vect) const = 0; //cette fonction aide pour avoir un dessin plus dynamique qui depend du temps
};