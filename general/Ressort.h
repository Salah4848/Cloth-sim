#pragma once
#include "Vecteur3D.h"
#include "Dessinable.h"
#include "SupportADessin.h"
#include "Masse.h"
#include <iostream>

class Ressort : public Dessinable{
private:
    Masse* masseD;
    Masse* masseA;
    double k;
    double l_0;
    bool deleted = false; // ceci est necessaire pour garantir que la masse ne puisse se detacher du ressort que si il est detuit (voir destructeur)
public:
    Ressort(Masse* masseD, Masse* masseA, double k=1, double l_0=0);
    ~Ressort();
    Ressort(Ressort const&)           = delete;
    Ressort& operator=(Ressort const&)= delete;
    //getters
    void getPos(Vecteur3D& depart, Vecteur3D& arrivee) const;
    double getk() const{return k;}
    double getl_0() const{return l_0;}
    //Methodes
    Vecteur3D force_rappel(Masse* masse) const;
    Vecteur3D force_rappel(Masse* masse, Vecteur3D const& position) const; //On utulise ceci pour Runge-Kutta
    double distance() const;
    void affiche(std::ostream&) const;
    bool connecte_a(Masse* masse) const;
    virtual void dessine_sur(SupportADessin& support) const override{support.dessine(*this);}
    bool is_deleted() const {return deleted;}

};

//Surcharge externe
std::ostream& operator<<(std::ostream&, Ressort const&);