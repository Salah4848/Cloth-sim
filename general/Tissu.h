#pragma once
#include "Masse.h"
#include "Ressort.h"
#include "Integrateur.h"
#include "Dessinable.h"
#include "SupportADessin.h"
#include <vector>
#include <iostream>

class Tissu : public Dessinable{
protected:
    std::vector<Masse*> masses;
    std::vector<Ressort*> ressorts;
public:
    //Constructeur, destructeur...
    Tissu(std::vector<Masse> const& masses);
    Tissu(std::vector<Vecteur3D> const& positons, double masse, double lambda=LAMBDA);
    Tissu(Tissu const&);
    Tissu& operator=(Tissu);
    virtual ~Tissu();
    //Getters
    Vecteur3D getForce(size_t i) const{return masses[i]->getForce();}
    long int nb_masses() const{return masses.size();}
    long int nb_ressorts() const{return ressorts.size();}
    Vecteur3D getPos(size_t i) const{return masses[i]->getPos();}
    void getPosRessort(Vecteur3D& depart, Vecteur3D& arrivee, size_t index) const;
    //Methodes
    void connecte(int indice1, int indice2, double k, double l_0);
    bool check() const;
    void mise_a_jour_force();
    void evolue(Integrateur& integrateur, double pas);
    void ajoute_force(size_t index_masse, Vecteur3D const& force);
    void affiche(std::ostream& sortie) const;
    void affiche_positions(std::ostream& sortie) const;
    void fixer(size_t index);
    virtual void dessine_sur(SupportADessin& support) const override;
};