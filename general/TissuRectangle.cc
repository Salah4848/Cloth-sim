#include "TissuRectangle.h"
#include <iostream>
#include <vector>
using namespace std;

TissuRectangle::TissuRectangle(double masse, Vecteur3D largeur, Vecteur3D longueur, Vecteur3D position, double lambda, double densitee, double k, double l_0)
 : Tissu(traitement(largeur,longueur,position,densitee,nb_largeur_,nb_longueur_),masse,lambda){
    //On connecte les masses
    int total(nb_largeur_*nb_longueur_);
    int indice;
    for(size_t i(0); i<nb_largeur_; ++i){
        for(size_t j(0); j<nb_longueur_; ++j){
            indice = j*nb_largeur_+i;
            if(j+1<nb_longueur_)connecte(indice,(j+1)*nb_largeur_+i,k,l_0);
            if(i+1<nb_largeur_)connecte(indice,j*nb_largeur_+i+1,k,l_0);
        }
    }
 }

//Fonction de traitement
vector<Vecteur3D> TissuRectangle::traitement(Vecteur3D largeur, Vecteur3D longueur, Vecteur3D position, double densitee, int& nb_largeur, int& nb_longueur){
    if (largeur.norme()>ZERO) longueur = longueur - ((1/largeur.norme2())*(largeur*longueur))*largeur;
    densitee = abs(densitee);
    if (densitee <= ZERO) {densitee=1; cout<<"Densitee nulle, mise a 1";}

    nb_largeur = 1+largeur.norme()*densitee;
    nb_longueur = 1+longueur.norme()*densitee;
    Vecteur3D dL((1/densitee)*(~largeur));
    Vecteur3D dl((1/densitee)*(~longueur));
    vector<Vecteur3D> positions;
    
    for (int i(0); i<=nb_longueur; ++i){
        positions.push_back(position + i*dl);
        for (int j(1); j<nb_largeur; ++j){
            positions.push_back(position + i*dl + j*dL);
        }
    }
    return positions;
}

