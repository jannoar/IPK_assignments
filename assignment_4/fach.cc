#include "fach.hh"
#include <string>

Fach::Fach(std::string name, std::string kuerzel, unsigned int ects)
    : _name(name), _kuerzel(kuerzel), _ects(ects), _note(0.0)
{}

bool Fach::noteEintragen(double note) {
    if (note >= 1.0 && note <= 5.0 && this->bestanden() == false) {
        this->_note = note;
        return true;
    }
    return false;
}

bool Fach::bestanden() const {
    return (this->_note <= 4.0 && this->_note > 0) ? true : false;
}

double Fach::gewerteteNote() const {
    return this->bestanden() ? this->_note * this->_ects : 0; 
}

unsigned int Fach::getECTS() const {
    return this->bestanden() ? this->_ects : 0;
}

std::string Fach::getName() const {
    return this->_name;
}

std::string Fach::getKuerzel() const {
    return this->_kuerzel;
}

std::string Fach::toString() const {
    return this->_kuerzel + " " + this->_name + " " + std::to_string(this->_ects) + " " + std::to_string(this->_note);
}

