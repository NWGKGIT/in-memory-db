#include <iostream>
#include <string>
#include <vector>
#include "database.h"
#include <sstream>

int main() {
    std::string filename = "sample.csv";
    Database db;
    if (!db.load(filename)) {
        std::cout << "Warning: Could not load initial data. Database is starting empty.\n";
    }

    std::string line;
    while (true) {
        std::cout << "db> ";
        if (!std::getline(std::cin, line)) {
            break;
        }
        if (line == "EXIT") {
            break;
        }

        std::stringstream ss(line);
        std::string command;
        ss >> command;

        if (command == "PRINT") {
            db.display();
        }
        else if (command == "ADD") {
            std::vector<std::string> cells;
            std::string cell;
            while (ss >> cell) {
                cells.push_back(cell);
            }
            if (cells.empty()) {
                std::cout << "Usage: ADD val1 val2 ...\n";
            } else {
                db.add(cells);
            }
        }
        else if (command == "FIND") {
            int col;
            std::string val;
            if (!(ss >> col >> val)) {
                std::cout << "Usage: FIND <col_index> <value>\n";
            } else if (col < 0) {
                std::cout << "Error: Column index must be non-negative.\n";
            } else {
                db.find(static_cast<size_t>(col), val);
            }
        }
        else if (command == "SAVE") {
            std::string saveFile;
            if (!(ss >> saveFile)) {
                saveFile = filename;
            }
            if (db.save(saveFile)) {
                std::cout << "Database saved to " << saveFile << "\n";
            }
        }
        else if (!command.empty()) {
            std::cout << "Unknown command: " << command << "\n";
            std::cout << "Supported commands: PRINT, ADD, FIND, SAVE, EXIT\n";
        }
    }

    std::cout << "Exiting ...\n";
    return 0;
}