#include "ExpenseManager.h"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <utility>

ExpenseManager::ExpenseManager(std::string filename)
    : filename_(std::move(filename)) {
    loadExpenses();
}

void ExpenseManager::addExpense(const Expense& expense) {
    if (expense.getAmount() <= 0) {
        std::cerr << "Error: Amount must be positive.\n";
        return;
    }

    expenses_.push_back(expense);
    saveExpenses();
}

void ExpenseManager::displayExpenses() const {
    if (expenses_.empty()) {
        std::cout << "No expenses recorded yet.\n";
        return;
    }

    std::cout << std::fixed << std::setprecision(2);

    for (std::size_t i = 0; i < expenses_.size(); ++i) {
        const Expense& expense = expenses_[i];

        std::cout << i + 1 << ". "
                  << expense.getDescription()
                  << " | " << expense.getCategory()
                  << " | EUR " << expense.getAmount()
                  << '\n';
    }
}

double ExpenseManager::getTotalSpending() const {
    double total = 0.0;

    for (const Expense& expense : expenses_) {
        total += expense.getAmount();
    }

    return total;
}

void ExpenseManager::loadExpenses() {
    std::ifstream file(filename_);

    if (!file) {
        return;
    }

    std::string description;
    std::string category;
    double amount = 0.0;

    while (file >> std::quoted(description)
                && file.ignore(1, ',')
                && file >> std::quoted(category)
                && file.ignore(1, ',')
                && file >> amount) {
        if (amount > 0) {
            expenses_.emplace_back(description, category, amount);
        }
    }
}

void ExpenseManager::saveExpenses() const {
    std::ofstream file(filename_);

    if (!file) {
        std::cerr << "Error: Could not save expenses to "
                  << filename_ << '\n';
        return;
    }

    file << std::fixed << std::setprecision(2);

    for (const Expense& expense : expenses_) {
        file << std::quoted(expense.getDescription()) << ','
             << std::quoted(expense.getCategory()) << ','
             << expense.getAmount() << '\n';
    }
}
