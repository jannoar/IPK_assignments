#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// (a)
bool readGitter(std::string gitterString, std::string gitterLine, std::vector<std::string> &lines) {
    bool ret = true;
    std::ifstream gitter;
    gitter.open("CGoL.txt");

    while (gitter.good()) {
        std::getline(gitter, gitterLine);
        lines.push_back(gitterLine);
        std::cout << gitterLine << std::endl;
    }
    for (int i = 0; i < lines.size() - 1; ++i) {
        // Checks if only viable characters are in the txt
        for (char character : lines[i]) {
            if (character != '0' && character != ' ') {
                std::cout << lines[i] << std::endl;
                std::cout << character << std::endl;
                std::cerr << "Dein Spielfeld ist ungültig." << std::endl;
                return false;
            }
        }
        if (lines[0].length() != lines[i].length())
            ret = false;
    }

    gitter.close();
    return ret;
}

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
    int nachbarn = 0;
    // Checks neighbours
    for (int i = 0; spielfeld.size() - 1; ++i) {
            nachbarn++;
        if (spielfeld[i-1][i]) {
            nachbarn++;
        }
        if (spielfeld[i][i-1]) {
            nachbarn++;
        }
        if (spielfeld[i-1][i+1]) {
            nachbarn++;
        }
        if (spielfeld[i+1][i-1]) {
            nachbarn++;
        }
        if (spielfeld[i][i+1]) {
            nachbarn++;
        }
        if (spielfeld[i+1][i]) {
            nachbarn++;
        }
        if (spielfeld[i+1][i+1]) {
            nachbarn++;
        }
        // updateCell(spielfeld[i][i]);
    }
}

int main() {
    std::vector<std::string> lines = {};
    std::string gitterString;
    std::string gitterLine;

    readGitter(gitterString, gitterLine, lines);
    std::vector<std::vector<bool>> spielfeld = {};
    for (std::string line : lines) {
        std::vector<bool> element = {};
        for (char character : line) {
            if (character == '0') {
                element.push_back(true);
            } else if ( character == ' ') {
                element.push_back(false);
            }

        }
        spielfeld.push_back(element);
    }
    std::cout << spielfeld.size() << std::endl;


    return 0;
}
