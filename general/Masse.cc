#include <iostream>
#include "Vecteur3D.h"
#include "Ressort.h"
#include "Masse.h"
#include "constantes.h"
#include "Helper.h"
using namespace std;

//Constructeur,destructeurs...
Masse::Masse(double m, Vecteur3D const& position, Vecteur3D const& vitesse, double lambda)
 : position(position), vitesse(vitesse), masse(m), lambda(lambda), ressorts({}), fixe(false)
{
    if (masse<0) {
        cout<<"Masse negetive --> mise a zero"<<endl;
        masse=0.0;
    }
    force_subie = masse*g;
}
Masse::Masse(Masse const& m){
    masse=m.masse;
    position=m.position;
    vitesse=m.vitesse;
    lambda=m.lambda;
    ressorts={};// On n'attache pas notre masse copiee aux memes ressorts
                // Quand on copie une masse on copie juste ses "propritees"
}
Masse& Masse::operator=(Masse const& m){
    masse=m.masse;
    position=m.position;
    vitesse=m.vitesse;
    lambda=m.lambda;
    ressorts={};
    return *this;
}

//Methodes
void Masse::ajoute_force(Vecteur3D const& df){
    force_subie+=df;
}
Vecteur3D Masse::acceleration() const{
    if (masse<=ZERO) {
        return Vecteur3D(0,0,0);
    }
    return (1/masse)*force_subie;

}
void Masse::mise_a_jour_force(){
    fixe=false;
    force_subie = Vecteur3D(0,0,0);
    for(size_t i(0); i<ressorts.size(); ++i){
        force_subie += ressorts[i]->force_rappel(this);
    }
    force_subie -= lambda*vitesse;
    force_subie += masse*g;
}
void Masse::affiche_ressorts (ostream& sortie) const{
    size_t size(ressorts.size());
    sortie << size << " # nb ressorts";
    if (size!=0) sortie<<endl;
    for(size_t i(0); i<ressorts.size(); ++i){
        sortie<< ressorts[i];
        if (i!=ressorts.size()-1) sortie<<endl; //Ceci permet d'enlever l'endl du dernier element pour un affichage plus uniforme
    }
}
void Masse::affiche(ostream& sortie) const{
    sortie <<"Masse "<<this<<" :"<<endl;
    sortie << masse << " # masse"<<endl;
    sortie << lambda << " # lambda"<<endl;
    sortie << position << " # position"<<endl;
    sortie << vitesse << " # vitesse"<<endl;
    sortie << force_subie <<  " # force"<<endl;
    affiche_ressorts( sortie );
}
void Masse::ajouter_ressort(Ressort* r){
    if(r->connecte_a(this) and (not isElementInVector(ressorts, r))) ressorts.push_back(r);
}
void Masse::enlever_ressort(Ressort* r){
    if(r->is_deleted()) deleteElementFromVector(ressorts, r);
}
Vecteur3D Masse::acceleration(Vecteur3D position_, Vecteur3D vitesse_){
    Vecteur3D force;
    for(size_t i(0); i<ressorts.size(); ++i){
        force += ressorts[i]->force_rappel(this,position_);
    }
    force -= lambda*vitesse_;
    force += masse*g;
    if (masse<=ZERO) {
        return Vecteur3D(0,0,0);
    }
    return (1/masse)*force;
}
void Masse::fixer(){
    fixe=true;
    vitesse=Vecteur3D(0,0,0);
    force_subie=Vecteur3D(0,0,0);
}
//Surchage externe

ostream& operator<<(ostream& sortie, Masse const& m){
    m.affiche(sortie);
    return sortie;
}