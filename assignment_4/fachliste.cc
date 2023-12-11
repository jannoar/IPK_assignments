#include "fachliste.hh"

FachListe::FachListe(){}

void FachListe::addFach(Fach fach) {
    this->_faecher.push_back(fach);
}

unsigned int FachListe::summeECTS() {
    unsigned int summe = 0;
    for (Fach i : this->_faecher)
        summe += i.getECTS();
    return summe;
}


