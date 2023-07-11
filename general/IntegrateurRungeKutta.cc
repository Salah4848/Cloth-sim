#include "IntegrateurRungeKutta.h"
#include <iostream>

//Methodes
void IntegrateurRungeKutta::evolue(Masse& masse) const{
    Vecteur3D xn_1(masse.getPos()); //x_(n-1)

    
    Vecteur3D k1(masse.getVitesse());
    Vecteur3D k1prime(masse.acceleration());
    Vecteur3D k2(k1+(dt/2)*k1prime);
    Vecteur3D k2prime(masse.acceleration(xn_1+(dt/2)*k1,k2));
    Vecteur3D k3(k1+(dt/2)*k2prime);
    Vecteur3D k3prime(masse.acceleration(xn_1 + (dt/2)*k2,k3));
    Vecteur3D k4(k1 + dt*k3prime); 
    Vecteur3D k4prime(masse.acceleration(xn_1 + dt*k3,k4));


    masse.setPos(xn_1 + (dt/6)*(k1+2*k2+2*k3+k4));
    masse.setVitesse(k1 + (dt/6)*(k1prime+2*k2prime+2*k3prime+k4prime));
}

IntegrateurRungeKutta* IntegrateurRungeKutta::copie() const{
    return new IntegrateurRungeKutta(*this);
}
