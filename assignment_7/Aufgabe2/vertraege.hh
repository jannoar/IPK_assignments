#pragma once
#include <vector>
#include <iostream>
#include <memory>
#include <cmath>
#include <limits>
#include <numbers>
#include <iomanip>

class AbstrakterVertrag
{
protected:
    double tEinheiten;
    int smsEinheiten;
    double preisProMin;
    double smsPreis;
public:
    virtual double berechneKosten() = 0;
    virtual void verbraucheTelefonEinheiten(double x) = 0;
    virtual void verbraucheSMSEinheit() = 0;
};

class FlatrateVertrag : public AbstrakterVertrag
{
private:
    double preis;
public:
    FlatrateVertrag(double p);
    double berechneKosten();
    void verbraucheTelefonEinheiten(double x);
    void verbraucheSMSEinheit();
};

class GrundgebuehrVertrag : public AbstrakterVertrag
{
protected:
    double grundGebuehr;
public:
    GrundgebuehrVertrag();
    GrundgebuehrVertrag(double ggb, double ppm, double sp);
    virtual double berechneKosten();
    virtual void verbraucheTelefonEinheiten(double x);
    virtual void verbraucheSMSEinheit();
    virtual double getTEinheiten();
};

class OhneGrundgebuehrVertrag : public GrundgebuehrVertrag
{
public:
    OhneGrundgebuehrVertrag();
    OhneGrundgebuehrVertrag(double ppm, double sp);
};

class SekuendlicherVertrag : public GrundgebuehrVertrag
{
public:
    SekuendlicherVertrag(double ggb, double ppm, double sp);
    double getTEinheiten();
};

class GuthabenVertrag : public OhneGrundgebuehrVertrag
{
private:
    double guthaben;
    double FixBetrag;
    int abbuchungen;
public:
    GuthabenVertrag(double ppm, double sp, double betrag);
    double berechneKosten();
    void verbraucheTelefonEinheiten(double x);
    void verbraucheSMSEinheit();
};

class VertragsBundle : public AbstrakterVertrag
{
private:
    std::shared_ptr<AbstrakterVertrag> Hauptvertrag;
    std::vector<std::shared_ptr<AbstrakterVertrag>> vertraege;
public:
    VertragsBundle(std::shared_ptr<AbstrakterVertrag> HV);
    std::shared_ptr<AbstrakterVertrag> get();
    std::shared_ptr<AbstrakterVertrag> get(int i);
    void vertragRegistrieren(std::shared_ptr<AbstrakterVertrag> vertrag);
    double berechneKosten();
    virtual void verbraucheTelefonEinheiten(double x);
    virtual void verbraucheSMSEinheit();
};

class Rechnung
{
private:
    std::string name;
    std::string adresse;
    std::shared_ptr<AbstrakterVertrag> vertrag;
public:
    Rechnung(std::string n, std::string a, std::shared_ptr<AbstrakterVertrag> v);
    std::shared_ptr<AbstrakterVertrag> getVertrag();
    friend std::ostream& operator<<(std::ostream& os, const Rechnung a);
};
