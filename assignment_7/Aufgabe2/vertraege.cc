#include <vector>
#include <iostream>
#include <memory>
#include <cmath>
#include <limits>
#include <numbers>
#include <iomanip>
#include "vertraege.hh"


FlatrateVertrag::FlatrateVertrag(double p) : preis(p){}
double FlatrateVertrag::berechneKosten(){return preis;}
void FlatrateVertrag::verbraucheTelefonEinheiten(double x){tEinheiten+=x;}
void FlatrateVertrag::verbraucheSMSEinheit(){smsEinheiten++;}


GrundgebuehrVertrag::GrundgebuehrVertrag(){}
GrundgebuehrVertrag::GrundgebuehrVertrag(double ggb, double ppm, double sp) : grundGebuehr(ggb){preisProMin=ppm; smsPreis=sp;}
double GrundgebuehrVertrag::berechneKosten()
{
    return grundGebuehr + getTEinheiten()*preisProMin + smsEinheiten*smsPreis;
}
void GrundgebuehrVertrag::verbraucheTelefonEinheiten(double x){tEinheiten+=x;}
void GrundgebuehrVertrag::verbraucheSMSEinheit(){smsEinheiten++;}
double GrundgebuehrVertrag::getTEinheiten(){return std::ceil(tEinheiten);}


OhneGrundgebuehrVertrag::OhneGrundgebuehrVertrag(){}
OhneGrundgebuehrVertrag::OhneGrundgebuehrVertrag(double ppm, double sp){preisProMin=ppm; smsPreis=sp; grundGebuehr = 0;}


SekuendlicherVertrag::SekuendlicherVertrag(double ggb, double ppm, double sp){preisProMin=ppm; smsPreis=sp; grundGebuehr = ggb;}
double SekuendlicherVertrag::getTEinheiten(){return tEinheiten;}


GuthabenVertrag::GuthabenVertrag(double ppm, double sp, double betrag) : FixBetrag(betrag) {preisProMin=ppm; smsPreis=sp; guthaben = 0; abbuchungen = 0;}
double GuthabenVertrag::berechneKosten()
{
    return  FixBetrag*abbuchungen;
}
void GuthabenVertrag::verbraucheTelefonEinheiten(double x)
{
    guthaben = guthaben - x * preisProMin;
    while(guthaben < 0){guthaben+=FixBetrag;    abbuchungen++;}
}
void GuthabenVertrag::verbraucheSMSEinheit()
{
    guthaben-=smsPreis;
    while(guthaben < 0){guthaben+=FixBetrag;    abbuchungen++;}
}


VertragsBundle::VertragsBundle(std::shared_ptr<AbstrakterVertrag> HV){Hauptvertrag = HV;}
std::shared_ptr<AbstrakterVertrag> VertragsBundle::get(){return Hauptvertrag;}
std::shared_ptr<AbstrakterVertrag> VertragsBundle::get(int i){return vertraege[i];}
void VertragsBundle::vertragRegistrieren(std::shared_ptr<AbstrakterVertrag> vertrag){vertraege.push_back(vertrag);}
double VertragsBundle::berechneKosten()
{
    double temp = Hauptvertrag->berechneKosten();
    for(int i = 0; i < vertraege.size(); i++)
        temp += vertraege[i]->berechneKosten();
    return temp;
}
void VertragsBundle::verbraucheTelefonEinheiten(double x){}
void VertragsBundle::verbraucheSMSEinheit(){}


Rechnung::Rechnung(std::string n, std::string a, std::shared_ptr<AbstrakterVertrag> v) : name(n), adresse(a), vertrag(v) {}
std::shared_ptr<AbstrakterVertrag> Rechnung::getVertrag(){return vertrag;}
std::ostream& operator<<(std::ostream& os, const Rechnung a)
{
    os << a.name << "\n" << a.adresse << "\n" << std::fixed << std::setprecision(2) << a.vertrag->berechneKosten() << "€";
    return os;
}
