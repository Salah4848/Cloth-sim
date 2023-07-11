#pragma once

#include <iostream>
#include "SupportADessin.h"

class TextViewer : public SupportADessin {
public:
 TextViewer(std::ostream& flot)
    : flot(flot)
  {}
  virtual ~TextViewer() = default;
  // on ne copie pas les TextViewer
  TextViewer(TextViewer const&)            = delete; 
  TextViewer& operator=(TextViewer const&) = delete;
   // mais on peut les déplacer
  TextViewer(TextViewer&&)            = default; 
  TextViewer& operator=(TextViewer&&) = default;

  virtual void dessine(Masse const& a_dessiner) override;
  virtual void dessine(Ressort const& a_dessiner) override;
  virtual void dessine(Tissu const& a_dessiner) override;
  virtual void dessine(Contrainte const& a_dessiner) override;
  virtual void dessine(Systeme const& a_dessiner) override;

private:
  std::ostream& flot;
};
