#pragma once
#include "Tissu.h"

class TissuRectangle : public Tissu{
private:
    int nb_largeur_; //nb de masselotes sur la largeur
    int nb_longueur_; //nb de masselotes sur la longeur
    static std::vector<Vecteur3D> traitement(Vecteur3D largeur, Vecteur3D longueur, Vecteur3D position, double densitee, int& nb_largeur, int& nb_longueur);
public:
    TissuRectangle(double masse, Vecteur3D largeur, Vecteur3D longueur, Vecteur3D position, double lambda, double densitee, double k, double l_0);
};