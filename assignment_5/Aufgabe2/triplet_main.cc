#include "triplet.hh"
#include <iostream>

int main()
{
    std::cout << "Erstellen eines triplets bestehend aus int, float und string..." << std::endl;
    Triplet<int, float, std::string> int_float_string(3, 0.14159, "PI");
    std::cout << "erster Wert: " << int_float_string.first() << std::endl;
    std::cout << "zweiter Wert: " << int_float_string.second() << std::endl;
    std::cout << "dritter Wert: " << int_float_string.third() << std::endl;
    std::cout << "Aendern der Werte..." << std::endl;
    int_float_string.setFirst(5);
    int_float_string.setSecond(7.525);
    int_float_string.setThird("nicht PI");
    std::cout << "Werte nach der aenderung:" << std::endl;
    std::cout << "erster Wert: " << int_float_string.first() << std::endl;
    std::cout << "zweiter Wert: " << int_float_string.second() << std::endl;
    std::cout << "dritter Wert: " << int_float_string.third() << std::endl;
    int_float_string.~Triplet();
    return 0;
}