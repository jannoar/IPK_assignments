#include "fach.hh"
#include <string>

Fach::Fach(std::string name, std::string kuerzel, unsigned int ects)
    : _name(name), _kuerzel(kuerzel), _ects(ects)
{}

bool Fach::noteEintragen(double note) {
    if (note >= 1.0 && note <= 5.0 && bestanden() == false) {
        this->_note = note;
        return true;
    }
    return false;
    
}

bool Fach::bestanden() const {
    if (_note <= 4.0)
        return true;
    return false;
}

double Fach::gewerteteNote() const {
    if (bestanden())
        return _ects * _note;
    return 0;
}

unsigned int Fach::getECTS() const {
    if (bestanden())
       return _ects;
    return 0;
}

std::string Fach::getName() const {
    return _name;
}

std::string Fach::getKuerzel() const {
    return _kuerzel;
}

std::string Fach::toString() const {
    std::string str = this->_kuerzel + " " + this->_name + " " + std::to_string(this->_ects) + " " + std::to_string(this->_note);
    return str;
}

