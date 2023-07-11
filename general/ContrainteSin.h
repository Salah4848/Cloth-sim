#pragma once
#include "ContrainteImpulsion.h"

class ContrainteSin : public ContrainteImpulsion {
private:
    double frequence_;
public:
    ContrainteSin(Vecteur3D centre, double rayon, double td, double tf, Vecteur3D force_reference, std::vector<Tissu*> tissus, double frequence);
    Vecteur3D force() const override;
    void dessinable(bool& b, Vecteur3D& vect) const override;
};