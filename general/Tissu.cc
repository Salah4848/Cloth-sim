#include "Tissu.h"
#include <vector>
#include <iostream>
using namespace std;

//Constructeur, destructeur...
Tissu::Tissu(vector<Masse> const& liste_masses){
    for (size_t i(0); i<liste_masses.size(); ++i){
        masses.push_back(new Masse(liste_masses[i]));
    }
}
Tissu::Tissu(vector<Vecteur3D> const& positons, double masse, double lambda){
    for(auto& pos : positons){
        masses.push_back(new Masse(masse,pos,Vecteur3D(0,0,0),lambda));
    }
}
Tissu::Tissu(Tissu const& t){
    for(size_t i(0); i<t.masses.size(); ++i){
        masses.push_back(new Masse(*t.masses[i]));
    }
    int d;
    int a;
    int counter;
    for(size_t i(0); i<t.ressorts.size(); ++i){
        d=-1;
        a=-1;
        counter=0;
        for(size_t j(0); counter<2 and j<t.masses.size(); ++j ){
            if(t.ressorts[i]->connecte_a(t.masses[j])){
                counter +=1;
                if(counter==1) d=j;
                if(counter==2) a=j;
            }
        connecte(d,a,t.ressorts[i]->getk(),t.ressorts[i]->getl_0());
        }
    }
}
Tissu& Tissu::operator=(Tissu t){
    swap(masses,t.masses);
    swap(ressorts,t.ressorts);
    return *this;
}
Tissu::~Tissu(){
    for(auto& r : ressorts){
        delete r;
    }
    for(auto& m : masses){
        delete m;
    }
}

//Methodes
void Tissu::connecte(int i1, int i2, double k, double l_0){
    if(i1!=i2 and i1>=0 and i2>=0 and i1<nb_masses() and i2<nb_masses()){
        ressorts.push_back(new Ressort(masses[i1],masses[i2],k,l_0));
    }
    //else cout<<"Indices des masses invalides, pas de masses connectees"<<endl;
}
bool Tissu::check() const{
    for(size_t i(0); i<masses.size(); ++i){
        //Avec ca on check pour la contrainte 1 (voir serie d'exercie du projet).
        if(masses[i]->getNbRessorts()==0) return false;
        //Pour le premier point de la contrainte 2, c'est assure par notre conception : un ressort pend si un de ses pointeur de masses est nulleptr
        //mais on ne peut pas avoir de pointeur de masses nullptr dans notre tissu puisque le contructeur prend un vector de masses (et non de pointeurs) qui sont ensuite copiees.
        //Le deuxieme point de la contrainte 2 est assure dans la methode connect.
        //La contrainte 3 est aussi assuree aussi par notre conception (le ressort est ajoute au listes de ses masses dans son contructeur).
        //On evite de vraiment faire les check puisque ajouter des getter dans Masse et Ressort qu'on utilisera que pour cette fonction semble contre-productif, alors qu'on connait le rendu.
    }
    return true;
}
void Tissu::mise_a_jour_force(){
    for(size_t i(0); i<masses.size(); ++i){
        masses[i]->mise_a_jour_force();
    }
}
void Tissu::evolue(Integrateur& integrateur, double pas){
    integrateur.setPas(pas);
    for(size_t i(0); i<masses.size(); ++i){
        integrateur.evolue(*masses[i]);
    }
}
void Tissu::ajoute_force(size_t i, Vecteur3D const& force){
    masses[i]->ajoute_force(force);
}
void Tissu::affiche(ostream& sortie) const{
    for(size_t i(0); i<masses.size(); ++i){
        sortie<<"Masse "<<i<<" :"<<endl;
        sortie<<*masses[i]<<endl<<endl;
    }
    for(size_t i(0); i<ressorts.size(); ++i){
        sortie<<"Ressort "<<i<<" :"<<endl;
        cout<<*ressorts[i]<<endl<<endl;
    }
}
void Tissu::affiche_positions(ostream& sortie) const{
    for(size_t i(0); i<masses.size(); ++i){
        cout<<masses[i]->getPos()<<" # masse "<<i<<endl;
    }
}
void Tissu::fixer(size_t i){
    masses[i]->fixer();
}
void Tissu::getPosRessort(Vecteur3D& d, Vecteur3D& a, size_t i) const{
    ressorts[i]->getPos(d,a);
}
void Tissu::dessine_sur(SupportADessin& support) const{
    for(auto& r : ressorts) r->dessine_sur(support);
    //for(auto& m : masses) m->dessine_sur(support); //si on veut dessiner les masses
}
