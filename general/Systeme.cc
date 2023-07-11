#include "Systeme.h"
#include "Tissu.h"
#include "Helper.h"
#include "IntegrateurEulerCromer.h"
#include "IntegrateurRungeKutta.h"
#include <vector>
#include <iostream>
using namespace std;


Systeme::Systeme(Integrateur& integrateur, vector<Tissu*> tissus, std::vector<Contrainte*> contraintes) : tissus(tissus), contraintes(contraintes),integrateur(integrateur.copie()){
    deleteDuplicatesFromVector(tissus);
    deleteDuplicatesFromVector(contraintes);
}
Systeme::~Systeme(){
    delete integrateur;
}

//getters
void Systeme::getPosRessort(Vecteur3D& d, Vecteur3D& a, size_t i1, size_t i2) const{
    tissus[i1]->getPosRessort(d,a,i2);
}
//Methodes
void Systeme::affiche(ostream& sortie) const{
    sortie<<"Le system est constitué de "<<tissus.size()<<" tissus."<<endl;
    for(size_t i(0); i<tissus.size(); ++i){
        sortie<<"Le tissu "<<tissus[i]<<" est constitué de "<<tissus[i]->nb_masses()<<" masses et "<<tissus[i]->nb_ressorts()<<" ressorts :"<<endl;
        tissus[i]->affiche(sortie);
    }
}
void Systeme::evolue(){
    for(size_t i(0); i<tissus.size(); ++i){
        tissus[i]->mise_a_jour_force();
        for(auto& c : contraintes){
            c->appliquer(*tissus[i], temps_);
        }
        tissus[i]->evolue(*integrateur, integrateur->getPas());
    }
    temps_+=integrateur->getPas();
}
void Systeme::affiche_positions(ostream& sortie) const{
    for(size_t i(0); i<tissus.size(); ++i){
        sortie<<"Tissu "<<tissus[i]<<" :"<<endl;
        tissus[i]->affiche_positions(sortie);
    }
}
void Systeme::ajoute_force(size_t i1, size_t i2, Vecteur3D force){
    tissus[i1]->ajoute_force(i2, force);
}
void Systeme::ajoute_contrainte(Contrainte& contrainte){
    if(not isElementInVector(contraintes,&contrainte)) contraintes.push_back(&contrainte);
}
void Systeme::ajoute_tissu(Tissu& tissu){
    if(not isElementInVector(tissus,&tissu)) tissus.push_back(&tissu);
}
void Systeme::dessine_sur(SupportADessin& support) const{
    support.dessine(*this);
    for(auto& t : tissus){
        t->dessine_sur(support);
    }
    for(auto& c : contraintes){
        c->dessine_sur(support);
    }
}
void Systeme::switchToEC(){
    Integrateur* integ(new IntegrateurEulerCromer(integrateur->getPas()));
    delete integrateur;
    integrateur=integ;
}
void Systeme::switchToRG(){
    Integrateur* integ(new IntegrateurRungeKutta(integrateur->getPas()));
    delete integrateur;
    integrateur=integ;
}
//surcharge d'operateur externe
ostream& operator<<(ostream& sortie, Systeme const& systeme){
    systeme.affiche(sortie);
    return sortie;
}