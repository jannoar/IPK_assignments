#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>

int VERSUCHE = 10;

// (a)
std::string verstecken(std::string input) {
    std::string gameState = "";

    for (int i = 0; i < input.length(); ++i) {
        gameState += "_";
    }
    return gameState;
}

// (b)
bool aufdecken(std::string &currentState, std::string solution, char guess) {
    bool guessInSolution = false;
    int solutionIndex = 0;

    // Checks if letter is in the word to be guessed
    for (char letter : solution) {
        if ((std::tolower(guess) == letter) || (std::toupper(guess) == letter)) {
            guessInSolution = true;
        } 
    }
    if (guessInSolution == false) return false;

    // Adds the letter(s) to the progress
    for (char& character : currentState) {
        if (std::tolower(guess) == solution[solutionIndex]) {
           character = std::tolower(guess);
        } else if (std::toupper(guess) == solution[solutionIndex]) {
            character = std::toupper(guess);
        }
        solutionIndex++;
    } 
    return true;
}

// (c)
bool istFertig(std::string currentState, std::string solution) {
    int underscoreInCurrState = 0;
    int underscoreInSolution = 0;

    // Counts the underscores in both the solution and the current game state
    for (char letter : currentState) {
        if (letter == '_')
            underscoreInCurrState++;
    }
    for (char letter : solution) {
        if (letter == '_')
            underscoreInSolution++;
    }

    // Compares both
    if (underscoreInSolution == underscoreInCurrState) {
        return true;
    }
    return false;
}

// (d)
void gameLoop(std::string solution) {
    std::string gameState = verstecken(solution);
    char userInput = ' ';

    while (true) {
        // Initial-IO
        std::cout << "Aktueller Fortschritt: " << gameState << std::endl;
        std::cout << "Rate einen Buchstaben des Wortes" << std::endl;
        std::cin >> userInput;
        // Computation 
        if (aufdecken(gameState, solution, userInput) == false) {
            VERSUCHE--;
            if (VERSUCHE == 0) {
                std::cout << "Du hast keine Versuche mehr und verloren.\n Das Wort war: " << solution << std::endl;
                break;
            }
            std::cout << "Du hast jetzt noch " << VERSUCHE << " Versuche" << std::endl;
        } else {
            if (istFertig(gameState, solution)) {
                std::cout << "Du hast gewonnen!" << std::endl;
                std::cout << "Das fertige Wort: " << gameState << std::endl;
                break;
            }
        }
        
    }
}

// (f)
void readFiles(std::vector<std::string>& words) {
    // Initialization
    std::ifstream file;
    std::string line;
    words.clear();

    // Handling the file and pushing every word to the words vector
    file.open("wortliste.txt");
    while (file) {
        std::getline(file, line);
        words.push_back(line);
    }
    file.close();
}

// (e)
int main() {
    std::vector<std::string> words = {"Haus", "Tomate", "Universitaet", "Informatik"};
    readFiles(words);

    std::srand(std::time(nullptr));
    gameLoop(words[std::rand() % words.size() + 1]);
    return 0;
}
