#include <iostream>

// (a)
unsigned int fib(unsigned int n) {
    if (n <= 1) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

// (b)
unsigned int fibIter(unsigned int n) {
    int prev = 1;
    int curr = 1;
    int next = 1;

    for (int i = 3; i <= n; ++i) {
        next = curr + prev;
        prev = curr;
        curr = next;
    }
    return next;
}

// (c)
int main () {
    int userInput;
    std::cout << "Die wie vielte Zahl in der Fibonacci-Folge möchtest du berechnen?" << std::endl;
    std::cin >> userInput;

    std::cout << "Die " << userInput << "te Fibonaccizahl wird berechnet: " << std::endl;
    std::cout << "Rekursiv: " << fib(userInput) << std::endl;
    std::cout << "Iterativ: " << fibIter(userInput) << std::endl;
    return 0;
}

