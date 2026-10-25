#include "ExpenseManager.h"

#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

int main() {
    ExpenseManager manager("expenses.csv");

    int choice = 0;

    std::cout << "================================\n";
    std::cout << "      C++ EXPENSE TRACKER\n";
    std::cout << "================================\n";

    while (true) {
        std::cout << "\n1. Add expense\n";
        std::cout << "2. View expenses\n";
        std::cout << "3. Show total spending\n";
        std::cout << "4. Exit\n";
        std::cout << "Choose an option: ";

        if (!(std::cin >> choice)) {
            std::cout << "Please enter a valid menu number.\n";
            std::cin.clear();
            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(), '\n');

        if (choice == 1) {
            std::string description;
            std::string category;
            double amount = 0.0;

            std::cout << "Enter description: ";
            std::getline(std::cin, description);

            std::cout << "Enter category: ";
            std::getline(std::cin, category);

            std::cout << "Enter amount in EUR: ";

            if (!(std::cin >> amount)) {
                std::cout << "Invalid amount. Please enter a number.\n";
                std::cin.clear();
                std::cin.ignore(
                    std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(), '\n');

            if (description.empty() || category.empty() || amount <= 0) {
                std::cout << "Description and category cannot be empty, "
                          << "and amount must be positive.\n";
                continue;
            }

            manager.addExpense(Expense(description, category, amount));
            std::cout << "Expense added successfully.\n";
        } else if (choice == 2) {
            manager.displayExpenses();
        } else if (choice == 3) {
            std::cout << std::fixed << std::setprecision(2);
            std::cout << "Total spending: EUR "
                      << manager.getTotalSpending() << '\n';
        } else if (choice == 4) {
            std::cout << "Thank you for using Expense Tracker!\n";
            break;
        } else {
            std::cout << "Invalid option. Choose 1, 2, 3, or 4.\n";
        }
    }

    return 0;
}
