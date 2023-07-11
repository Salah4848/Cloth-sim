#pragma once
#include "Tissu.h"
#include <vector>

class TissuCompose : public Tissu{
private:
    double epsilon_;
    double k_;
    double l_0_;
public:
    TissuCompose(std::vector<Tissu*> const& tissus, double epsilon, double k, double l_0);//On a pas besoin de polymorphisme pusique nos attributs des nouveaux tissus rectangle et disque n'auront plus de sens
    TissuCompose(Tissu const& tissu, double epsilon, double k, double l_0); //si on veut initialiser avec un unique tissu
    Tissu& operator+=(Tissu const&); 
};