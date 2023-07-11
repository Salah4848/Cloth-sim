#include "Ressort.h"
#include "Vecteur3D.h"
#include "Masse.h"
#include <iostream>
using namespace std;


//Constructeur...
Ressort::Ressort(Masse* masseD, Masse* masseA, double k, double l_0)
 : masseD(masseD), masseA(masseA), k(k), l_0(l_0)
{
    if (masseA==nullptr or masseD==nullptr) throw invalid_argument("Masses invalides!");
    masseA->ajouter_ressort(this);
    masseD->ajouter_ressort(this);
}
Ressort::~Ressort(){
    deleted = true;
    masseA->enlever_ressort(this);
    masseD->enlever_ressort(this);
}

//Methodes
double Ressort::distance() const{
    return (masseA->getPos()-masseD->getPos()).norme();
}
Vecteur3D Ressort::force_rappel(Masse* masse) const{
    Vecteur3D F;
    if(masseA==masse){
        F = ((k)*(distance()-l_0))*(~(masseD->getPos()-masseA->getPos()));
    }
    else if(masseD==masse) {
        F = ((k)*(distance()-l_0))*(~(masseA->getPos()-masseD->getPos()));
    }
    return F;
}
Vecteur3D Ressort::force_rappel(Masse* masse, Vecteur3D const& position) const{
    Vecteur3D F;
    Vecteur3D difference;
    if(masseA==masse){
        difference = masseD->getPos()-position;
        F = ((k)*(difference.norme()-l_0))*(~difference);
    }
    else if(masseD==masse) {
        difference = masseA->getPos()-position;
        F = ((k)*(difference.norme()-l_0))*(~difference);
    }
    return F;
}
void Ressort::affiche(ostream& sortie) const{
    sortie<<"Ressort "<<this<<" :"<<endl;
    sortie<<k<<" # cste raideur"<<endl;
    sortie<<l_0<<" # longueur a vide"<<endl;
    sortie<<"Masse de depart : ";
    sortie<<*masseD<<endl;
    sortie<<"Masse d'arrivee : ";
    sortie<<*masseA;

}
void Ressort::getPos(Vecteur3D& i, Vecteur3D& f) const{
    i=masseD->getPos();
    f=masseA->getPos();
}
bool Ressort::connecte_a(Masse* m) const{
    return (masseA==m or masseD==m);
}
//Surcharge externe
ostream& operator<<(ostream& sortie, Ressort const& r){
    r.affiche(sortie);
    return sortie;
}