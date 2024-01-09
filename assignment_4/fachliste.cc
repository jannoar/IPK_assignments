#include "fachliste.hh"
#include <vector>

FachListe::FachListe() {};

FachListe::FachListe(std::vector<Fach> faecher) {
    for (Fach f : faecher)
        _faecher.push_back(f);
}

void FachListe::addFach(Fach fach) {
    this->_faecher.push_back(fach);
}

unsigned int FachListe::summeECTS() {
    unsigned int summe = 0;
    for (Fach f : this->_faecher)
        summe += f.getECTS();
    return summe;
}

double FachListe::durchschnitt() {
    double bestandeneFaecher = 0;
    double gewerteteNoten = 0;
    for (Fach f : this->_faecher) {
        if (f.bestanden()) {
            bestandeneFaecher++;
            gewerteteNoten += f.gewerteteNote();
        }
    }
    return gewerteteNoten / bestandeneFaecher;
}

std::vector<std::string> FachListe::list() {
    std::vector<std::string> faecherList = {};
    for (Fach f : this->_faecher)
        faecherList.push_back(f.toString());
    return faecherList;
}

bool FachListe::noteEintragen(std::string kuerzel, double note) {
    for (Fach &f : this->_faecher) {
        if (f.getKuerzel() == kuerzel) {
            if (f.noteEintragen(note))
                return true;
        }
    }
    return false;
}
