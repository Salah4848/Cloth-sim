#pragma once
#include <vector>
#include "Tissu.h"

class TissuChaine : public Tissu {
public:
    TissuChaine(std::vector<Vecteur3D> const& positions, double masse, double lambda, double k, double l_0);
};