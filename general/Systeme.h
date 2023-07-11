#pragma once
#include "Dessinable.h"
#include "SupportADessin.h"
#include "Tissu.h"
#include "Contrainte.h"
#include <vector>
#include <iostream>

class Systeme : public Dessinable {
private:
    std::vector<Tissu*> tissus;
    std::vector<Contrainte*> contraintes;
    Integrateur* integrateur;
    double temps_=0;
public:
    Systeme(Integrateur& integrateur, std::vector<Tissu*> tissus={}, std::vector<Contrainte*> contraintes={});
    ~Systeme();
    Systeme(Systeme const&)            = delete;
    Systeme& operator=(Systeme const&) = delete;

    //getters et setters
    Vecteur3D getPos(size_t index_tissu, size_t index_masse) const{return tissus[index_tissu]->getPos(index_masse);}
    void getPosRessort(Vecteur3D& depart, Vecteur3D& arrivee, size_t index_tissu, size_t index_masse) const;
    int nb_tissus() const{return tissus.size();}
    void setPas(double dt){integrateur->setPas(dt);}
    //methodes
    virtual void dessine_sur(SupportADessin& support) const override;
    void affiche(std::ostream& sortie) const;
    void evolue();
    void affiche_positions(std::ostream& sortie) const;
    void ajoute_force(size_t index_tissu, size_t index_masse, Vecteur3D force);
    void ajoute_contrainte(Contrainte& contrainte);
    void ajoute_tissu(Tissu& tissu);
    void switchToEC();
    void switchToRG();
};
//Surcharge d'operateur externe
std::ostream& operator<<(std::ostream& sortie, Systeme const& systeme);