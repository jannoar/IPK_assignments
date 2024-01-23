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
    FlatrateVertrag(double p) : preis(p){}
    double berechneKosten(){return preis;}
    void verbraucheTelefonEinheiten(double x){tEinheiten+=x;}
    void verbraucheSMSEinheit(){smsEinheiten++;}
};

class GrundgebuehrVertrag : public AbstrakterVertrag
{
protected:
    double grundGebuehr;
public:
    GrundgebuehrVertrag(){}
    GrundgebuehrVertrag(double ggb, double ppm, double sp) : grundGebuehr(ggb){preisProMin=ppm; smsPreis=sp;}
    virtual double berechneKosten()
    {
        return grundGebuehr + getTEinheiten()*preisProMin + smsEinheiten*smsPreis;
    }
    virtual void verbraucheTelefonEinheiten(double x){tEinheiten+=x;}
    virtual void verbraucheSMSEinheit(){smsEinheiten++;}
    virtual double getTEinheiten(){return std::ceil(tEinheiten);}
};

class OhneGrundgebuehrVertrag : public GrundgebuehrVertrag
{
public:
    OhneGrundgebuehrVertrag(){}
    OhneGrundgebuehrVertrag(double ppm, double sp){preisProMin=ppm; smsPreis=sp; grundGebuehr = 0;}
};

class SekuendlicherVertrag : public GrundgebuehrVertrag
{
public:
    SekuendlicherVertrag(double ggb, double ppm, double sp){preisProMin=ppm; smsPreis=sp; grundGebuehr = ggb;}
    double getTEinheiten(){return tEinheiten;}
};

class GuthabenVertrag : public OhneGrundgebuehrVertrag
{
private:
    double guthaben;
    double FixBetrag;
    int abbuchungen;
public:
    GuthabenVertrag(double ppm, double sp, double betrag) : FixBetrag(betrag) {preisProMin=ppm; smsPreis=sp; guthaben = 0; abbuchungen = 0;}
    double berechneKosten()
    {
        return  FixBetrag * abbuchungen;
    }
    void verbraucheTelefonEinheiten(double x)
    {
        guthaben = guthaben - x * preisProMin;
        while(guthaben < 0){guthaben+=FixBetrag;    abbuchungen++;}
    }
    void verbraucheSMSEinheit()
    {
        guthaben-=smsPreis;
        while(guthaben < 0){guthaben+=FixBetrag;    abbuchungen++;}
    }
};

class VertragsBundle : public AbstrakterVertrag
{
private:
    std::shared_ptr<AbstrakterVertrag> Hauptvertrag;
    std::vector<std::shared_ptr<AbstrakterVertrag>> vertraege;
public:
    VertragsBundle(std::shared_ptr<AbstrakterVertrag> HV){Hauptvertrag = HV;}
    std::shared_ptr<AbstrakterVertrag> get(){return Hauptvertrag;}
    std::shared_ptr<AbstrakterVertrag> get(int i){return vertraege[i];}
    void vertragRegistrieren(std::shared_ptr<AbstrakterVertrag> vertrag){vertraege.push_back(vertrag);}
    double berechneKosten()
    {
        double temp = Hauptvertrag->berechneKosten();
        for(int i = 0; i < vertraege.size(); i++)
            temp += vertraege[i]->berechneKosten();
        return temp;
    }
    virtual void verbraucheTelefonEinheiten(double x){}
    virtual void verbraucheSMSEinheit(){}
};

class Rechnung
{
private:
    std::string name;
    std::string adresse;
    std::shared_ptr<AbstrakterVertrag> vertrag;
public:
    Rechnung(std::string n, std::string a, std::shared_ptr<AbstrakterVertrag> v) : name(n), adresse(a), vertrag(v) {}
    std::shared_ptr<AbstrakterVertrag> getVertrag(){return vertrag;}
    friend std::ostream& operator<<(std::ostream& os, const Rechnung a)
    {
        os << a.name << "\n" << a.adresse << "\n" << std::fixed << std::setprecision(2) << a.vertrag->berechneKosten() << "€";
        return os;
    }
};
