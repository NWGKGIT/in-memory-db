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
    bool load(const std::string& filename);
    bool save(const std::string& filename) const;
    void display() const;
    void find(size_t colIndex, const std::string& value) const;
    void add(const std::vector<std::string>& cells);
};

#endif //IN_MEMORY_DB_DATABASE_H