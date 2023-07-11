#include <iostream>
#include <cmath>
#include "Vecteur3D.h"
#include "constantes.h"
using namespace std;

//Constructeurs
Vecteur3D::Vecteur3D(double x, double y, double z)
: x_(x), y_(y), z_(z){}


//Methodes de calcul
void Vecteur3D::affiche(ostream& sortie) const{
    sortie<<x_<<" "<<y_<<" "<<z_;
}
bool Vecteur3D::compare(const Vecteur3D& v, double precision) const{
    return abs(v.x_-x_)<precision and abs(v.y_-y_)<precision and abs(v.z_-z_)<precision;
}
Vecteur3D Vecteur3D::addition(const Vecteur3D& v) const{
    return Vecteur3D(v.x_+x_, v.y_+y_, v.z_+z_);
}
Vecteur3D Vecteur3D::soustraction(const Vecteur3D& v) const{
    return addition(v.mult(-1));
}
Vecteur3D Vecteur3D::oppose() const{
    return mult(-1);
}
Vecteur3D Vecteur3D::mult(double a) const{
    return Vecteur3D(a*x_,a*y_,a*z_);
}
double Vecteur3D::prod_scal(const Vecteur3D& v) const{
    return x_*v.x_+y_*v.y_+z_*v.z_;
}
Vecteur3D Vecteur3D::prod_vect(const Vecteur3D& v) const{
    return Vecteur3D(v.z_*y_-v.y_*z_, -v.z_*x_+v.x_*z_, v.y_*x_-v.x_*y_);
}
double Vecteur3D::norme() const{
    return sqrt(x_*x_+y_*y_+z_*z_);
}
double Vecteur3D::norme2() const{
    return x_*x_+y_*y_+z_*z_;
}
Vecteur3D Vecteur3D::unitaire() const{
    if (norme()<=ZERO){
        return Vecteur3D(0,0,0);
    }
    return Vecteur3D(mult(1/norme()));
}


//Surcharge d'operateurs internes
bool Vecteur3D::operator==(Vecteur3D const& v){
    return compare(v);
}
bool Vecteur3D::operator!=(Vecteur3D const& v){
    return not compare(v);
}
Vecteur3D& Vecteur3D::operator+=(Vecteur3D const& v){
    *this = addition(v);
    return *this;
}
Vecteur3D& Vecteur3D::operator-=(Vecteur3D const& v){
    *this = soustraction(v);
    return *this;
}
Vecteur3D& Vecteur3D::operator^=(Vecteur3D const& v){
    *this = prod_vect(v);
    return *this;
}
Vecteur3D Vecteur3D::operator-(){
    return oppose();
}
Vecteur3D Vecteur3D::operator~(){
    return unitaire();
}


//Fonctions et surcharge d'operateurs externes
ostream& operator<<(ostream& sortie, Vecteur3D const& v){
    v.affiche(sortie);
    return sortie;
}
Vecteur3D operator+(Vecteur3D v1, Vecteur3D const& v2){
    v1+=v2;
    return v1;
}
Vecteur3D operator-(Vecteur3D v1, Vecteur3D const& v2){
    v1-=v2;
    return v1;
}
Vecteur3D operator^(Vecteur3D v1, Vecteur3D const& v2){
    v1^=v2;
    return v1;
}
double operator*(Vecteur3D const& v1, Vecteur3D const& v2){
    return v1.prod_scal(v2);
}
Vecteur3D operator*(double a, Vecteur3D const& v){
    return v.mult(a);
}
Vecteur3D operator*(Vecteur3D const& v, double a){
    return v.mult(a);
}