#include "Contrainte.h"

bool Contrainte::dans_champ(Vecteur3D const& pos) const{
    return (centre_-pos).norme()<=rayon_;
}