#pragma once
#include "Integrateur.h"

class IntegrateurRungeKutta : public Integrateur{
public:
    using Integrateur::Integrateur;

    void evolue(Masse& masse) const override;
    virtual IntegrateurRungeKutta* copie() const override;
};