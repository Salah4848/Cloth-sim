#pragma once
#include "Contrainte.h"

class ContrainteCrochet : public Contrainte {
public:
    using Contrainte::Contrainte;
    void appliquer(Tissu& tissu, double temps) override;
    void dessinable(bool& b, Vecteur3D& vect) const override;
};