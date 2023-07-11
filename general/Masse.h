#pragma once
#include "Vecteur3D.h"
#include "constantes.h"
#include "Dessinable.h"
#include "SupportADessin.h"
#include <vector>
#include <iostream>

class Ressort;


class Masse : public Dessinable{
private:
    Vecteur3D position;
    Vecteur3D vitesse;
    double masse;
    double lambda;
    Vecteur3D force_subie;
    std::vector<Ressort*> ressorts;
    bool fixe; //Le seul moyen disponible pour fixer une masse en travaillant avec des integrateurs a plusieurs etapes comme Runge-Kutta
public:
    Masse(double masse, Vecteur3D const& position=Vecteur3D(0,0,0), Vecteur3D const& vitesse=Vecteur3D(0,0,0), double lambda=LAMBDA);
    Masse(Masse const&);
    Masse& operator=(Masse const&);

    //getters
    Vecteur3D getPos() const{return position;}
    Vecteur3D getVitesse() const{return vitesse;}
    double getMasse() const{return masse;}
    double getLambda() const{return lambda;}
    Vecteur3D getForce() const{return force_subie;}
    size_t getNbRessorts() const{return ressorts.size();}
    //setters
    void setPos(Vecteur3D const& p) {if(not fixe) position=p;}
    void setVitesse(Vecteur3D const& v) {if(not fixe) vitesse=v;}
    void setMasse(double m) {masse=m;}
    void setLambda(double lbda) {lambda=lbda;}

    //Methodes
    void mise_a_jour_force();
    void affiche(std::ostream&) const;
    void affiche_ressorts(std::ostream&) const;
    void ajouter_ressort(Ressort*);
    void enlever_ressort(Ressort*);
    void ajoute_force(Vecteur3D const&);
    Vecteur3D acceleration() const;
    Vecteur3D acceleration(Vecteur3D position, Vecteur3D vitesse); //On utilise ceci our Runge-Kutta
    void fixer();
    virtual void dessine_sur(SupportADessin& support) const override{support.dessine(*this);}
};

//Surcharge
std::ostream& operator<<(std::ostream&, Masse const&);


