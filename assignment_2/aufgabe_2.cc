#include <numeric>
#include <algorithm>
#include <iostream>
#include <ostream>
#include <vector>
#include <string>
#include <cmath>

// (a)
void print(std::vector<double> vec) {
    if (vec.empty())
        return;; 
    std::string output = "[";
    std::vector<double>::iterator itend = vec.end() - 1;

    for (std::vector<double>::iterator it = vec.begin(); it!=itend; ++it) {
        // Cuts out the extra .000 digits, without rounding 
        std::string element = std::to_string(*it);
        element.erase(element.find_last_not_of('0') + 1, std::string::npos);
        element.erase(element.find_last_not_of('.') + 1, std::string::npos);

        // Adds the element to the output string
        output += (element);
        output += ", ";
    }

    // Cuts out the extra .000 digits, without rounding 
    std::string lastElement = std::to_string(vec.back());
    lastElement.erase(lastElement.find_last_not_of('0') + 1, std::string::npos);
    lastElement.erase(lastElement.find_last_not_of('.') + 1, std::string::npos);

    // Adds the last element to the output string seperate, in order to cut the last ","
    output += lastElement;;
    output += "]";

    // Prints out the vector 
    std::cout << output << std::endl;
}

// (b)
double median(std::vector<double> vec) {
    if (vec.empty())
        return 0;
    std::sort(vec.begin(), vec.end());
    return vec[vec.size() / 2];
}

// (c)
void sin(std::vector<double> &vec) {
    for (double &element : vec)
       element = std::sin(element); 
}

// (d)
std::vector<double> sums(std::vector<std::vector<double>> vec) {
    std::vector<double> sumsOfVectors;
    for (int i = 0; i < vec.size(); ++i) 
        sumsOfVectors.push_back(std::accumulate(vec[i].begin(), vec[i].end(), 0.0));

    return sumsOfVectors;
}

// (e)
int main() {
    // Initialization
    std::vector<std::vector<double>> emptyVectors = {{}, {}, {}};
    std::vector<double> randomV = {2.1, 13, 4.2, 1.111};
    std::vector<double> randomV2 = {5.5, 12, 4.12412, 3.2, 123};
    std::vector<std::vector<double>> vForSums = {{0.3, 1, 3.1}, {3, 23.1, 2.22, 12}, {7.6, 4.4, 22, 1}};

    // Output
    // (b)
    std::cout << "Median of empty vector: " << median({}) << std::endl;
    std::cout << "Median of " << std::endl;
    print(randomV);
    std::cout << "(non-odd vector): " << median(randomV) << std::endl;
    std::cout << "Median of " << std::endl;
    print(randomV2);
    std::cout << "(odd vector): " << median(randomV2) << std::endl;
    // (c)
    // sin({});
    sin(randomV);
    sin(randomV2);
    std::cout << "Sins of the same 2 vectors: " << std::endl;
    print(randomV);
    print(randomV2);
    // (d)
    std::cout << "3 vectors: " << std::endl;
    print(vForSums[0]);
    print(vForSums[1]);
    print(vForSums[2]);
    std::cout << "The sum of each: " << std::endl;
    print(sums(vForSums));
    std::cout << "The sum of 3 empty vectors: " << std::endl; 
    print(sums(emptyVectors));

    return 0;
}
