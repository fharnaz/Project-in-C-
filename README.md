# C++ Expense Tracker

A simple, console-based expense tracking application built with **C++20**. This project demonstrates object-oriented programming, file handling, automated testing, and CMake build configuration.

## Features

- **Add expenses** with a description, category, and amount.
- **View expenses** recorded in the application.
- **Calculate total expenses** to track spending.
- **Save and load data** using a CSV file.
- **Automated tests** for expense management and data persistence.

## Technologies

- C++20
- Object-oriented programming (OOP)
- CMake
- GCC / MinGW
- Git and GitHub
- C++ standard library and file handling

## Project Structure

```text
cpp-expense-tracker/
├── CMakeLists.txt
├── README.md
├── .gitignore
├── include/
│   ├── Expense.h
│   └── ExpenseManager.h
├── src/
│   ├── main.cpp
│   └── ExpenseManager.cpp
└── tests/
    ├── ExpenseTests.cpp
    └── ExpenseManagerTests.cpp
```

## Requirements

- A C++20-compatible compiler, such as GCC.
- CMake 3.20 or newer.
- A compatible build tool, such as MinGW Makefiles on Windows.

## Build the Project

Open a terminal in the project root directory and configure CMake:

```bash
cmake -S . -B build
```

Build the application and test programs:

```bash
cmake --build build
```

On Windows with MinGW Makefiles, you can configure explicitly with:

```powershell
cmake -S . -B build -G "MinGW Makefiles"
```

This requires `g++` and `mingw32-make` to be available to CMake.

## Run the Application

On Windows:

```powershell
.\build\expense-tracker.exe
```

On Linux or macOS:

```bash
./build/expense-tracker
```

Follow the console menu to add expenses, view recorded expenses, and calculate the total.

## Run the Tests

Run the automated tests with CTest:

```bash
ctest --test-dir build --output-on-failure
```

The test suite checks expense data and expense management, including saving and loading expenses.

## Data Storage

Expense records are stored in a local CSV file named `expenses.csv`. This file is intended for local application data and is excluded from version control.

## What I Learned

Through this project, I practised:

- Designing and using C++ classes.
- Separating declarations, implementation, and application logic.
- Managing data with file input and output.
- Writing automated tests.
- Configuring a C++ project with CMake.
- Using Git for version control.

## Future Improvements

- Add expense editing and deletion.
- Filter expenses by category.
- Display monthly spending summaries.
- Improve input validation and error handling.
- Add a graphical user interface.

## Author

**Farhana Faruk**

IT student at Savonia University of Applied Sciences, Finland.

[View my GitHub profile](https://github.com/fharnaz)