#include "ContrainteSin.h"
#include <cmath>

ContrainteSin::ContrainteSin(Vecteur3D centre, double rayon, double td, double tf, Vecteur3D force, std::vector<Tissu*> tissus, double frequence)
 : ContrainteImpulsion(centre,rayon,td,tf,force,tissus), frequence_(frequence){}

Vecteur3D ContrainteSin::force() const{
    return sin(2*M_PI*frequence_*(temps_-td_))*force_;
}

void ContrainteSin::dessinable(bool& b, Vecteur3D& vect) const{
    b = (temps_>=td_ and temps_<=tf_);
    double couleur((1/force_.norme())*force().norme());
    vect = Vecteur3D(0, 1-couleur,couleur);
}
