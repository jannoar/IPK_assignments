#pragma once

class Temperatur
{
private:
    double _ktemperatur;
public:
    //standard Konstruktor 
    Temperatur();
    //Konstruktor der _ktemperatur einen Startwert gibt
    Temperatur(double k);
    //destructor 
    ~Temperatur();
    //holt die Temperatur in Kelvin 
    double getKelvin();
    //holt die Temperatur in Grad Celsius
    double getCelsius();
    //holt die Temperatur in Grad Fahrenheit 
    double getFahrenheit();
    //setzt die Temperatur in Kelvin 
    void setKelvin(double k);
    //setzt die Temperatur in Grad Celsius
    void setCelsius(double gc);
    //setzt die Temperatur in Grad Fahrenheit
    void setFahrenheit(double f);
    //erstellt eine neue Temperatur aus der Summe der aktuellen Temperatur und einer Referenz 
    Temperatur add(Temperatur t1);
};