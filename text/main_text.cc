#include <iostream>
#include "text_viewer.h"
#include "Systeme.h"
#include "IntegrateurEulerCromer.h"
using namespace std;

int main()
{
  TextViewer ecran(cout);
  IntegrateurEulerCromer integ(1);
  Tissu tissu({Masse(10)});
  Systeme systeme(integ,{&tissu});

  cout << "Au départ :" << endl;
  systeme.dessine_sur(ecran);

  systeme.evolue();
  cout << "Après un pas de calcul :" << endl;
  systeme.dessine_sur(ecran);

  systeme.evolue();
  cout << "Après deux pas de calcul :" << endl;
  systeme.dessine_sur(ecran);

  return 0;
}
