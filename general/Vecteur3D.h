#pragma once
#include<iostream>

class Vecteur3D
{
private:
    double x_;
    double y_;
    double z_;
public:
    //Constructeurs
    explicit Vecteur3D(double x=0.0, double y=0.0, double z=0.0);
    
    //Getters and setters
    double x() const{return x_;}
    double y() const{return y_;}
    double z() const{return z_;}
    void x(double x){x_=x;}
    void y(double y){y_=y;}
    void z(double z){z_=z;}

    //methodes de calcul
    void affiche(std::ostream& sortie=std::cout) const;
    bool compare(const Vecteur3D&, double precision=1e-10) const;
    Vecteur3D addition(const Vecteur3D& ) const;
    Vecteur3D soustraction(const Vecteur3D&) const;
    Vecteur3D oppose() const;
    Vecteur3D mult(double ) const;
    double prod_scal(const Vecteur3D&) const;
    Vecteur3D prod_vect(const Vecteur3D&) const;
    double norme() const;
    double norme2() const;
    Vecteur3D unitaire() const;
 
    //Surcharge d'operateurs internes
    bool operator==(Vecteur3D const& );
    bool operator!=(Vecteur3D const&);
    Vecteur3D& operator+=(Vecteur3D const&);
    Vecteur3D& operator-=(Vecteur3D const&);
    Vecteur3D& operator^=(Vecteur3D const&);
    Vecteur3D operator-();
    Vecteur3D operator~();


};


//Surcharge d'operateurs externes
std::ostream& operator<<(std::ostream& sortie, Vecteur3D const& );
Vecteur3D operator+(Vecteur3D, Vecteur3D const&);
Vecteur3D operator-(Vecteur3D, Vecteur3D const&);
Vecteur3D operator^(Vecteur3D, Vecteur3D const&);
double operator*(Vecteur3D const&, Vecteur3D const&);//produit scalaire
Vecteur3D operator*(double, Vecteur3D const&);//produit par un scalaire a*v
Vecteur3D operator*(Vecteur3D const&, double);//produit par un scalaire v*a
