#include "TissuDisque.h"
#include <vector>
#include <cmath>
using namespace std;

TissuDisque::TissuDisque(double masse, Vecteur3D centre, Vecteur3D rayon, double pas_radial, double lambda, double k, double pas_angulaire)
 : Tissu(traitement(centre,rayon,pas_radial,pas_angulaire,nb_radial_,nb_angulaire_),masse,lambda){
    int total(nb_angulaire_*nb_radial_+1);
    int indice;
    for(int j(0); j<nb_angulaire_; ++j){
        connecte(0,1+j*nb_radial_,k,pas_radial);
        for(int i(0); i<nb_radial_; ++i){
            indice = 1+j*nb_radial_+i;
            connecte(indice,1+((j+1)%nb_angulaire_)*nb_radial_+i,k,(i+1)*pas_radial*pas_angulaire*M_PI/180);
            if(i+1<nb_radial_) connecte(indice,1+j*nb_radial_+i+1,k,pas_radial);
        }
    }
 }



vector<Vecteur3D> TissuDisque::traitement(Vecteur3D centre, Vecteur3D rayon, double pas_radial, double pas_angulaire, int& nb_radial, int& nb_angulaire){
    //On construit une vecteur normal au rayon
    Vecteur3D u(~Vecteur3D(rayon.y(),-rayon.x(),0));
    Vecteur3D n(~rayon);

    pas_angulaire = abs(pas_angulaire);
    pas_radial = abs(pas_radial);
    if(pas_angulaire<ZERO) pas_angulaire=20;
    if(pas_radial<ZERO) pas_radial=1;

    nb_radial = rayon.norme()/pas_radial;
    nb_angulaire = 360/pas_angulaire;
    double theta = pas_angulaire* M_PI/180.0 ; //* M_PI/180
    vector<Vecteur3D> positions({centre});
    
    for(int i(0); i<nb_angulaire; ++i){
        u = cos(theta)*u + ((1-cos(theta))*(u*n))*n + sin(theta)*(n^u);
        for(int j(1); j<=nb_radial; ++j){
            positions.push_back(centre + j*pas_radial*u);
        }
    }
    return positions;
}