#include "IntegrateurEulerCromer.h"
#include "Masse.h"
#include "Ressort.h"

//Methodes

void IntegrateurEulerCromer::evolue(Masse& masse) const{
	masse.setVitesse(masse.getVitesse() + (dt*masse.acceleration()));
	masse.setPos(masse.getPos() + (dt*masse.getVitesse()));
}
IntegrateurEulerCromer* IntegrateurEulerCromer::copie() const{
	return new IntegrateurEulerCromer(*this);
}