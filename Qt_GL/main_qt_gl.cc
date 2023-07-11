#include <QApplication>
#include <iostream>
#include "glwidget.h"
#include "IntegrateurRungeKutta.h"
#include "IntegrateurEulerCromer.h"
#include "Tissu.h"
#include "TissuChaine.h"
#include "TissuRectangle.h"
#include "TissuDisque.h"
#include "TissuCompose.h"
#include "constantes.h"
#include "ContrainteCrochet.h"
#include "ContrainteImpulsion.h"
#include "ContrainteSin.h"

int main(int argc, char* argv[])
{
  QApplication a(argc, argv);

  //parametres tissus rectangles
  double masse(0.05); //0.05
  Vecteur3D largeur(10,0,0); //10,0,0
  Vecteur3D longueur(0,0,10); //0,0,10
  Vecteur3D position(0,0,0); //0,0,0
  double lambda(LAMBDA); //LAMBDA
  double densitee(2); //2
  double k(100); //100
  double l_0(0.5); //0.5

  //parametres tissus disques
  Vecteur3D centre(position); //position
  Vecteur3D rayon(0,2.5,0); //0,2.5,0
  double pas_radial(0.25); //0.25
  double pas_angulair(20); //20

  //Parametre tissus compose
  double epsilon(0.01); //0.01

  //Parametre contraintes
  double rayonCrochet(0.1);
  Vecteur3D centreImpulsion(0.5*largeur);
  double rayonImpulsion(1);
  double td(0); //depart
  double tf(5); //fin
  Vecteur3D force(0,10,0);
  double frequence(0.5);


  //Creation de tissus
  TissuRectangle tissurect1(masse,largeur,longueur,position,lambda,densitee,k,l_0);
  TissuDisque tissudisc1(masse,centre,rayon,pas_radial,lambda,k,pas_angulair);
  TissuDisque tissudisc2(masse,centre+largeur,rayon,pas_radial,lambda,k,pas_angulair);
  TissuDisque tissudisc3(masse,centre+longueur,rayon,pas_radial,lambda,k,pas_angulair);
  TissuDisque tissudisc4(masse,centre+largeur+longueur,rayon,pas_radial,lambda,k,pas_angulair);
  
  TissuCompose tissucomp1(tissurect1,epsilon,k,l_0);
  tissucomp1+=tissudisc1; tissucomp1+=tissudisc2; tissucomp1+=tissudisc3; tissucomp1+=tissudisc4;

  //Creation des contraintes
  ContrainteCrochet crochet1(position +longueur, rayonCrochet);
  ContrainteCrochet crochet2(position + largeur + longueur , rayonCrochet);
  ContrainteSin contrsin1(centreImpulsion,rayonImpulsion,td,tf,force,{&tissucomp1},frequence);

  //integrateur
  IntegrateurRungeKutta integ(0.01); //Vous pouvez changer a EulerCromer en appuyant sur la touche 1

  //Systeme
  Systeme s(integ);
  //Ajout des tissus
  s.ajoute_tissu(tissucomp1);
  //Ajout des contraintes
  s.ajoute_contrainte(crochet1);
  s.ajoute_contrainte(crochet2);
  s.ajoute_contrainte(contrsin1);

  //La fenetre d'affichage (On peut en creer plusieurs avec differends systemes)
  GLWidget w(s);
  w.show();

  return a.exec();
}
