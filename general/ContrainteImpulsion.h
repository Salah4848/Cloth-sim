#pragma once
#include "Contrainte.h"
#include <vector>
#include <map> //nous utilisons des maps pour les masses a memoriser

class ContrainteImpulsion : public Contrainte {
protected:
    double td_;
    double tf_;
    Vecteur3D force_;
    std::map<Tissu*,std::vector<size_t>> memoire_;
public:
    ContrainteImpulsion(Vecteur3D centre, double rayon, double td, double tf, Vecteur3D force, std::vector<Tissu*> tissus);
    virtual Vecteur3D force() const{return force_;} 
    bool dans_memoire(Tissu& tissu, size_t index) const;                   
    void appliquer(Tissu& tissu, double temps) override;
    void dessinable(bool& b, Vecteur3D& vect) const override;
};