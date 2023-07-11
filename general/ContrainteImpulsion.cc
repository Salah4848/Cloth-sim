#include "ContrainteImpulsion.h"
#include "Helper.h"
using namespace std;

ContrainteImpulsion::ContrainteImpulsion(Vecteur3D centre, double rayon, double td, double tf, Vecteur3D force, vector<Tissu*> tissus)
 : Contrainte(centre,rayon), td_(td), tf_(tf), force_(force){
    deleteDuplicatesFromVector(tissus);
    for(auto& t : tissus){
        memoire_[t]={};
        for(size_t i(0); i<t->nb_masses(); ++i){
            if (dans_champ(t->getPos(i))) memoire_[t].push_back(i);
        }
    }
 }

bool ContrainteImpulsion::dans_memoire(Tissu& tissu, size_t index) const{
    if(memoire_.count(&tissu)>0){
        for(auto i : memoire_.at(&tissu)){
            if(i==index) return true;
        }
    }
    return false;
}

void ContrainteImpulsion::appliquer(Tissu& tissu, double temps) {
    temps_=temps; //on met a jour le temps ici
    if(temps>=td_ and temps<=tf_){
        for(size_t i(0); i<tissu.nb_masses(); ++i){
            if(dans_memoire(tissu,i)) tissu.ajoute_force(i,force()-g);
        }
    }
}

void ContrainteImpulsion::dessinable(bool& b, Vecteur3D& vect) const{
    b = (temps_>=td_ and temps_<=tf_);
    vect=Vecteur3D(1,1,0);
}