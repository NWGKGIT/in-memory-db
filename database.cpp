//
// Created by arc31 on 5/15/26.
//
#include <variant>
#include <string>
#include "database.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>


void Database::load(const std::string &filename) {
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        Row row;
        std::stringstream ss(line);
        std::string cell;

        while (std::getline(ss, cell, ',')) {
            row.cells.push_back(cell);
        }
        this->m_table.push_back(row);
    }
}

void Database::display() const {
    for (const auto& row: this->m_table) {
        for (const auto& cell : row.cells) {
            std::cout << cell << " | ";
        }
        std::cout << "\n";
    }
}


void printCells(const auto& cells) {
    for (const auto& cell: cells) {
        std::cout<<cell<<" | ";
    }
    std::cout<<"\n";

}

void Database::find(int colIndex, const std::string &value) const {
    bool found = false;
    for (const auto& row: m_table) {
        if (colIndex < row.cells.size()) {
            if (row.cells[colIndex] == value) {
                printCells(row.cells);
                found=true;
            }
        }

    }
    if (!found) {
        std::cout <<"No matches found for '" << value <<"' in column" <<colIndex <<".\n";
    }

}
