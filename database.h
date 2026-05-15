//
// Created by arc31 on 5/15/26.
//

#ifndef IN_MEMORY_DB_DATABASE_H
#define IN_MEMORY_DB_DATABASE_H
#include <vector>
#include <string>
std::vector<std::string> readCSV(const std::string& filename);

struct Row {
    std::vector<std::string> cells;
};

class Database {

private:
    std::vector<Row> m_table;

public:
    void load(const std::string& filename);
    void display() const;
    void find(int colIndex, const std::string& value) const;

};

#endif //IN_MEMORY_DB_DATABASE_H