#include <iostream>

// (a)
bool isEven(unsigned int number) {
    if (number % 2 == 0) {
        return true;
    } else {
        return false;
    }
}

// (b)
// Die Collatz-Funktion, wie sie in der Aufgabenstellung verlangt wurde:
void collatz(unsigned int number) {
    std::cout << "Nummer: " << number << std::endl;

    while (number != 1 || 0) {
        if (isEven(number)) {
            number /= 2;
        } else {
            number *= 3;
            number++;
        }
    std::cout << number << std::endl;
    }
    std::cout << "Nachher: " << number << std::endl; 
}

// Die Collatz-Funktion, wie sie die gesamte Folge ausgeben würde.
void collatz2(unsigned int number) {
    std::cout << "Folge: \n" << number << std::endl;

    while (number != 1 || 0) {
        if (isEven(number)) {
            number /= 2;
        } else {
            number *= 3;
            number++;
        }
    std::cout << number << std::endl;
    }
}

// (c)
int main() {
    int userInput;
    std::cout << "Für welchen Wert möchtest du die Collatz-Folge ausgeben?" << std::endl;
    std::cin >> userInput;

    collatz(userInput);
    return 0;
}
