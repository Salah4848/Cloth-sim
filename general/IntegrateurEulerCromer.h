#pragma once
#include "Integrateur.h"
#include "Masse.h"
#include "Ressort.h"

class IntegrateurEulerCromer : public Integrateur{
public:
	using Integrateur::Integrateur;

	void evolue(Masse& masse) const override;
	virtual IntegrateurEulerCromer* copie() const override;
};