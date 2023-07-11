#include <iostream> // pour endl
#include "text_viewer.h"
#include "Systeme.h"
using namespace std;

void TextViewer::dessine(Masse const& a_dessiner){
  cout<<a_dessiner.getPos()<<endl;
}
void TextViewer::dessine(Ressort const& a_dessiner){
  cout<<a_dessiner<<endl;
}
void TextViewer::dessine(Tissu const& a_dessiner){
  a_dessiner.dessine_sur(*this);
}
void TextViewer::dessine(Contrainte const& a_dessiner){
  cout<<a_dessiner.getCentre()<<"\n";
  cout<<a_dessiner.getRayon()<<"\n";
}
void TextViewer::dessine(Systeme const& a_dessiner){
  a_dessiner.dessine_sur(*this);
}
