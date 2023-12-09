#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// (a)
std::vector<std::vector<bool>> readGame(std::string textFile) {
    std::vector<std::vector<bool>> spielfeld = {};
    std::ifstream gitter;
    std::vector<std::string> lines = {};
    std::string gitterString;
    std::string gitterLine;
    gitter.open(textFile);

    while (gitter.good()) {
        std::getline(gitter, gitterLine);
        lines.push_back(gitterLine);
    }
    int lineSize = lines[0].size();

    for (std::string line : lines) {
        if (line.size() != lineSize) 
            return {};

        std::vector<bool> element = {};
        for (char character : line) {
            if (character == '0') {
                element.push_back(true);
            } else if ( character == ' ') {
                element.push_back(false);
            } else {
                return {};
            }

        }
        spielfeld.push_back(element);
    }

    gitter.close();
    return spielfeld;
}

// (b) 
void updateCell(bool &cell, int nachbarn) {
    if (cell == false && nachbarn == 3) {
        cell = true;
    } 
    if (cell == true && (nachbarn == 2 || nachbarn == 3)) {
        cell = true;
    } else {
        cell = false;
    }

}

void updateGitter(std::vector<std::vector<bool>> spielfeld) {
    int actualSize = 0;
    for (auto v : spielfeld)
        for (auto a: v)
            actualSize++;
    std::cout << actualSize;
    
    std::vector<std::vector<bool>> temp = {};
    std::vector<int> neighbours = {};

    // Checks neighbours
    for (int i = 0; actualSize; ++i) {
        std::cout << "Irgendwas" << std::endl;
        int nachbarn = 0;
        if (spielfeld[i-1][i]) {
            std::cout << "y" << std::endl;
            nachbarn++;
        }
        if (spielfeld[i][i-1]) {
            std::cout << "y" << std::endl;
            nachbarn++;
        }
        if (spielfeld[i-1][i+1]) {
            std::cout << "y" << std::endl;
            nachbarn++;
        }
        if (spielfeld[i+1][i-1]) {
            std::cout << "y" << std::endl;
            nachbarn++;
        }
        if (spielfeld[i][i+1]) {
            std::cout << "y" << std::endl;
            nachbarn++;
        }
        if (spielfeld[i+1][i]) {
            std::cout << "y" << std::endl;
            nachbarn++;
        }
        if (spielfeld[i+1][i+1]) {
            std::cout << "y" << std::endl;
            nachbarn++;
        }
        neighbours.push_back(nachbarn);
    }
    for (auto v : neighbours)
        std::cout << v << std::endl;
    // updateCell(spielfeld[i][i]);
}

// (c)
void printGame(std::vector<std::vector<bool>> spielfeld) {
    for (std::vector<bool> line : spielfeld) {
        for (bool value : line) {
            if (value == true)
                std::cout << "0";
            else {
                std::cout << " ";
            }    
        }
        std::cout << "\n";
    }
    
}

int main() {
    std::vector<int> a = {1, 2, 3};
    std::cout << a[-2] << std::endl; 
    // std::cout << spielfeld.size() << std::endl;

    // printGame(readGame("CGoL.txt"));
    // updateGitter(readGame("CGoL.txt"));

    return 0;
}
