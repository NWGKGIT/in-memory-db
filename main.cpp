#include <iostream>
#include <string>
#include <vector>
#include "database.h"

int main() {
    std::string filename="sample.csv";
    Database db;
    db.load(filename);

    std::string command;

    while (true) {
        std::cout << "db> ";
        std::cin >>command;

        if (command =="EXIT") {
            break;
        }
        else if (command == "PRINT") {
            db.display();
        }
        else if (command =="ADD") {
            std::cout <<"Add func \n";
        }
        else if (command == "FIND") {
            int col;
            std::string val;
            std::cin >> col >> val;
            db.find(col, val);
        }
        else {
            std::cout << "Unknown command: " <<command <<"\n";
        }
    }

    std::cout << "Exiting ...\n";
    return 0;
}