#include <cstddef>
#include <iostream>
#include <unordered_map>
#include <string>

// (c)
size_t hashPassword(std::string pw) {
    std::size_t pw_hash = std::hash<std::string>{}(pw);
    return pw_hash;
}

// (a) 
bool createUser(std::unordered_map<std::string, size_t> &db, std::string userName, std::string pw) {
    if (db.find(userName) == db.end()) {
        db.insert(std::make_pair(userName, hashPassword(pw))); 
        return true;
    } else {
        return false;
    }
}

bool authenticateUser(std::unordered_map<std::string, size_t> db, std::string userName, std::string pw) {
    bool ret = false;
    for (auto &it : db) {

        if (it.first == userName && it.second == hashPassword(pw))
            ret = true;
    }
    return ret;
}

// (d)
void listUsers(std::unordered_map<std::string, size_t> db) {
    for (auto& pair : db)
        std::cout << "{" << pair.first << ": " << pair.second << "}\n";
}

void changePassword(std::unordered_map<std::string, size_t> &db, std::string userName, std::string newPassword) {
    db[userName] = hashPassword(newPassword); 
}


int main() {
    std::unordered_map<std::string, size_t> userDatabase = {{"admin", hashPassword("123")}};
    int input;
    std::string userName = "";
    std::string password = ""; 
    std::string changePW = "";
    std::string newPassword = "";

    while (true) {
        std::cout << "Was möchtest du tun? \n [0] Beenden \n [1] Login\n [2] Registrieren" << std::endl;
        std::cin >> input; 
        

        if (input == 1) {
            std::cout << "Was ist dein Nutzername?" << std::endl;
            std::cin >> userName;
            std::cout << "Was ist dein Passwort?" << std::endl;
            std::cin >> password;
            if (authenticateUser(userDatabase, userName, password)) {
                // (e)
                std::cout << "Du bist erfolgreich eingeloggt." << std::endl;
                std::cout << "Möchtest du dein Passwort ändern? (ja / nein)" << std::endl;
                std::cin >> changePW;
                if (changePW == "ja") {
                    std::cout << "Was soll dein neues Passwort sein?";
                    std::cin >> newPassword;
                    changePassword(userDatabase, userName, newPassword);
                    std::cout << "Erfolgreich geändert.";
                }
                // (d)
                if (userName == "admin")
                    listUsers(userDatabase);

            } else {
                std::cout << "Nutzername oder Passwort falsch." << std::endl;
            }
        } else if (input == 2) {
            std::cout << "Was soll dein Nutzername sein?" << std::endl;
            std::cin >> userName;
            std::cout << "Was soll dein Passwort sein?" << std::endl;
            std::cin >> password;

            if (createUser(userDatabase, userName, password)) {
                std::cout << "Du hast dich erfolgreich registriert." << std::endl;
            } else {
                std::cout << "Etwas ist schief gelaufen." << std::endl;
            }
        }
        else if (input == 0)
            break;
    }

    return 0;
}
