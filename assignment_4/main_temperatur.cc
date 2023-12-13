#include "temperatur.hh"
#include "temperatur.cc"
#include <iostream>

int main()
{
    //Erstelen von zwei Temperaturen 
    Temperatur temperatur1(12.0);
    Temperatur temperatur2(300.0);
    //Ausgeben von beiden Temperaturen in K, °C und °F
    std::cout << "Temperatur 1:\n";
    std::cout << "Kelvin: " << temperatur1.getKelvin() << " K\n";
    std::cout << "Celsius: " << temperatur1.getCelsius() << " °C\n";
    std::cout << "Fahrenheit: " << temperatur1.getFahrenheit() << " °F\n";
    std::cout << "\n";
    std::cout << "Temperatur 2:\n";
    std::cout << "Kelvin: " << temperatur2.getKelvin() << " K\n";
    std::cout << "Celsius: " << temperatur2.getCelsius() << " °C\n";
    std::cout << "Fahrenheit: " << temperatur2.getFahrenheit() << " °F\n";
    std::cout << "\n";
    //erstellt eine neue Temperatur aus der summe von temperatur1 und temperatur2
    Temperatur temperatur3 = temperatur1.add(temperatur2);
    std::cout << "Temperatur 3:\n";
    std::cout << "Kelvin: " << temperatur3.getKelvin() << " K\n";
    std::cout << "Kelvin: " << temperatur3.getKelvin() << " K\n";
    std::cout << "Celsius: " << temperatur3.getCelsius() << " °C\n";
    std::cout << "Fahrenheit: " << temperatur3.getFahrenheit() << " °F\n";
    return 1;
}