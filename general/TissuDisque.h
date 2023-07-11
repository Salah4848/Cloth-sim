#pragma once
#include "Tissu.h"

class TissuDisque : public Tissu {
private:
    int nb_radial_; //nb de masselotes sur le rayon
    int nb_angulaire_; //nb de "lignes" de masselotes autour du centre, on prend 9 a partir des 20 degres de l'enoncee 
    static std::vector<Vecteur3D> traitement(Vecteur3D centre, Vecteur3D rayon, double pas_radial, double pas_angulaire, int& nb_radial, int& nb_angulaire);
public:
    TissuDisque(double masse, Vecteur3D centre, Vecteur3D rayon, double pas_radial, double lambda, double k, double pas_angulaire=20);
};