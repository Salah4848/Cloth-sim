#include <vector>
#include "TissuChaine.h"
using namespace std;

TissuChaine::TissuChaine(std::vector<Vecteur3D> const& positions, double masse, double lambda, double k, double l_0)
 : Tissu(positions, masse, lambda){
    if (positions.size()>1){
        for(size_t i(0); i<positions.size()-1; ++i){
            connecte(i,i+1,k,l_0);
        }
    }
}

