#pragma once

class Masse;
class Ressort;
class Tissu;
class Contrainte;
class Systeme;

class SupportADessin{
public:
    virtual ~SupportADessin() = default;
    SupportADessin(SupportADessin const&)            = delete;
    SupportADessin& operator=(SupportADessin const&) = delete;
    SupportADessin(SupportADessin&&)            = default;
    SupportADessin& operator=(SupportADessin&&) = default;

    SupportADessin() = default;
    
    virtual void dessine(Tissu const&) = 0;
    virtual void dessine(Systeme const&) = 0;
    virtual void dessine(Masse const&) = 0;
    virtual void dessine(Ressort const&) =0;
    virtual void dessine(Contrainte const&) =0;
};