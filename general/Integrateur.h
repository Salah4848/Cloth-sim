#pragma once
#include "Masse.h"

class Integrateur{
protected:
	double dt;
public:
	//Constructeur
	Integrateur(double dt=0);
	virtual ~Integrateur() = default;

	//Getters
	double getPas() const{return dt;}
	//Setters
	void setPas(double pas){dt=pas;}

	//Methodes
	virtual void evolue(Masse& masse) const=0;
	virtual Integrateur* copie() const=0; //copie polymorphique
};