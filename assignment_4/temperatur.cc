#include "temperatur.hh"
//konstruktoren und der Destruktor
Temperatur::Temperatur(double k) : _ktemperatur(k) {}
Temperatur::Temperatur() : _ktemperatur(0.0) {}
Temperatur::~Temperatur(){}

//die ganzen getter
double Temperatur::getKelvin()
{
    return _ktemperatur;
}

double Temperatur::getCelsius()
{
    return _ktemperatur - 273.15; //Umrechnung in Grad Celcius 
}

double Temperatur::getFahrenheit()/
{
    return (_ktemperatur - 273.15) * 9 / 5 + 32; //Umrechnung in Grad Fahrenheit 
}

//die ganzen setter 
void Temperatur::setKelvin(double k)
{
    this->_ktemperatur = k;
}

void Temperatur::setCelsius(double gc)
{
    this->_ktemperatur = gc + 273.15; //in Kelvin umrechnen
}

void Temperatur::setFahrenheit(double f)
{
    this->_ktemperatur = (f - 32) * 5 / 9 + 273.15; //in Kelvin umrechnen
}

Temperatur Temperatur::add(Temperatur t1)
{
    return Temperatur(this->getKelvin() + t1.getKelvin()); //erstellt aus der summe der aufgerufenen Temperatur und einer Referenz eine neue Temperatur
}