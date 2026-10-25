
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

struct Expense {
    std::string description;
    std::string category;
    double amount;
};

const std::string FILE_NAME = "expenses.csv";

void saveExpenses(const std::vector<Expense>& expenses) {
    std::ofstream file(FILE_NAME);

    if (!file) {
        std::cerr << "Error: Could not save expenses.\n";
        return;
    }

    for (const Expense& expense : expenses) {
        file << std::quoted(expense.description) << ','
             << std::quoted(expense.category) << ','
             << expense.amount << '\n';
    }
}

void loadExpenses(std::vector<Expense>& expenses) {
    std::ifstream file(FILE_NAME);

    if (!file) {
        return; // The file will be created when we save.
    }

    Expense expense{};

    while (file >> std::quoted(expense.description)
                && file.ignore(1, ',')
                && file >> std::quoted(expense.category)
                && file.ignore(1, ',')
                && file >> expense.amount) {
        expenses.push_back(expense);
    }
}

int main() {
    std::vector<Expense> expenses;
    loadExpenses(expenses);

    int choice = 0;

    while (choice != 4) {
        std::cout << "\n===== EXPENSE TRACKER =====\n";
        std::cout << "1. Add expense\n";
        std::cout << "2. View expenses\n";
        std::cout << "3. Show total spending\n";
        std::cout << "4. Exit\n";
        std::cout << "Choose an option: ";

        if (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a number.\n";
            return 1;
        }

        if (choice == 1) {
            Expense expense{};

            std::cout << "Description: ";
            std::getline(std::cin >> std::ws, expense.description);

            std::cout << "Category: ";
            std::getline(std::cin, expense.category);

            std::cout << "Amount (EUR): ";

            if (!(std::cin >> expense.amount) ||
                expense.amount <= 0) {
                std::cout << "Please enter a valid positive amount.\n";
                return 1;
            }

            expenses.push_back(expense);
            saveExpenses(expenses);

            std::cout << "Expense added and saved successfully!\n";

        } else if (choice == 2) {
            if (expenses.empty()) {
                std::cout << "No expenses recorded yet.\n";
            }

            for (std::size_t i = 0; i < expenses.size(); ++i) {
                std::cout << i + 1 << ". "
                          << expenses[i].description
                          << " | " << expenses[i].category
                          << " | EUR "
                          << std::fixed << std::setprecision(2)
                          << expenses[i].amount << '\n';
            }

        } else if (choice == 3) {
            double total = 0.0;

            for (const Expense& expense : expenses) {
                total += expense.amount;
            }

            std::cout << std::fixed << std::setprecision(2);
            std::cout << "Total spending: EUR " << total << '\n';

        } else if (choice == 4) {
            std::cout << "Thank you for using Expense Tracker!\n";

        } else {
            std::cout << "Invalid option. Choose 1-4.\n";
        }
    }

    return 0;
}
