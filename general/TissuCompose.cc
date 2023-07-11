#include "TissuCompose.h"
#include <vector>
#include <iostream>
using namespace std;

//Constructeurs
TissuCompose::TissuCompose(std::vector<Tissu*> const& tissus, double epsilon, double k, double l_0)
 : Tissu({}), epsilon_(abs(epsilon)), k_(k), l_0_(l_0){
    for(size_t i(0); i<tissus.size(); ++i){
        *this += *tissus[i];
    }
}
TissuCompose::TissuCompose(Tissu const& tissu, double epsilon, double k, double l_0)
 : Tissu(tissu), epsilon_(abs(epsilon)), k_(k), l_0_(l_0){}

//Surcharge d'operateur
Tissu& TissuCompose::operator+=(Tissu const& t){
    TissuCompose tissu(t,0,0,0);//On cree une copie de type tissu compose pour avoir acces au listes des ressorts et masses, les arguments epsilon,k et l_0 ne sont pas important
    for(size_t i1(0); i1<masses.size(); ++i1){
        for(size_t i2(0); i2<tissu.masses.size(); ++i2){
            if(abs((masses[i1]->getPos()-tissu.masses[i2]->getPos()).norme())<=epsilon_){
                ressorts.push_back(new Ressort(masses[i1],tissu.masses[i2],k_,l_0_));
            }
        }
    }
    if(ressorts.size()==0) throw invalid_argument("Tissu trop distant ou vide!"); //Un throw devrait arreter la construction
    masses.insert(masses.end(),tissu.masses.begin(),tissu.masses.end());
    ressorts.insert(ressorts.end(),tissu.ressorts.begin(),tissu.ressorts.end());
    tissu.ressorts={};//tissu n'est plus le proprietaire des masses et ressorts
    tissu.masses={};
    return *this;
}