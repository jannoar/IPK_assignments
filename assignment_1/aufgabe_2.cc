#include <cmath>
#include <iostream>
#include <ostream>

// (b)
float discriminant(float p, float q) {
    return pow((p / 2), 2) - q;
}

int main() {
    // (a)
    float p;
    float q;

    std::cout << "pq-Formel Rechner: \n" << std::endl;
    std::cout << "Was soll p sein?" << std::endl;
    std::cin >> p;
    std::cout << "Was soll q sein?" << std::endl;
    std::cin >> q;
    float pqPartOne = -(p / 2);

    // (c)
    if (discriminant(p, q) < 0) {
        std::cerr << "Es gibt keine relle Lösung." << std::endl;
    } else if (discriminant(p, q) == 0) {
        std::cout << "Der Diskriminant ist 0, daher ist die einzige Lösung: " << pqPartOne << std::endl;
    } else {
    // (d)
    float xOne = pqPartOne + std::sqrt(discriminant(p, q));
    float xTwo = pqPartOne - std::sqrt(discriminant(p, q));

    std::cout << "x1: " << xOne << std::endl;
    std::cout << "x2: " << xTwo << std::endl;
    }

    return 0;
}
