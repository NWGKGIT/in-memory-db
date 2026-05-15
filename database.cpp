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


bool Database::load(const std::string &filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << "\n";
        return false;
    }

    m_table.clear();
    std::string line;
    size_t expectedCols = 0;
    bool firstRow = true;

    while (std::getline(file, line)) {
        if (line.empty()) continue;

        Row row;
        std::stringstream ss(line);
        std::string cell;

        while (std::getline(ss, cell, ',')) {
            row.cells.push_back(cell);
        }

        if (firstRow) {
            expectedCols = row.cells.size();
            firstRow = false;
        } else if (row.cells.size() != expectedCols) {
            std::cerr << "Warning: Row has " << row.cells.size() << " columns, expected " << expectedCols << ". Skipping.\n";
            continue;
        }

        this->m_table.push_back(row);
    }
    return true;
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
