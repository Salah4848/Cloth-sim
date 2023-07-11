#include "ContrainteCrochet.h"

void ContrainteCrochet::appliquer(Tissu& tissu, double t) {
    for(size_t i(0); i<tissu.nb_masses(); ++i){
        if(dans_champ(tissu.getPos(i))) tissu.fixer(i);
    }
}
void ContrainteCrochet::dessinable(bool& b, Vecteur3D& vect) const{
    b=true;
    vect = Vecteur3D(1,0,0);
}