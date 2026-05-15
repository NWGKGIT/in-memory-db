# In-Memory-DB

A very simple, minimal in-memory database implemented in C++.

> [!NOTE]
> This is a  learning project built in just a few hours. It was for the purpose of understanding basic C++ concepts, file I/O, and simple CLI command parsing.

## Features
- **Load/Save**: Read from and write to CSV files.
- **In-Memory Buffer**: Add rows to the database in RAM.
- **Search**: Basic search functionality by column index.
- **Robustness**: Basic error handling for file operations and CLI inputs.

## Project Structure
- `include/`: Header files (`database.h`).
- `src/`: Source files (`database.cpp`, `main.cpp`).
- `data/`: (Optional) CSV files like `sample.csv`.
- `CMakeLists.txt`: Build configuration.

## Quick Start

### Build
```bash
mkdir build && cd build
cmake ..
make
```

### Run
```bash
./In_Memory_DB
```

> [!NOTE]
> I recommed using CLion, that's what I used for this.

### Commands
- `PRINT`: Display all rows.
- `ADD val1 val2 ...`: Add a new row to the in-memory table.
- `FIND <col_index> <value>`: Search for a specific value in a column.
- `SAVE [filename]`: Save the current table to a CSV file (defaults to `sample.csv`).
- `EXIT`: Close the application.

## License
MIT ofc since it's for learning. . .

## Future plans
- maybe a UI?
