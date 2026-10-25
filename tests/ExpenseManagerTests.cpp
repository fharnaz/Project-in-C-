#include "ExpenseManager.h"

#include <cassert>
#include <cmath>
#include <cstdio>
#include <iostream>

bool approximatelyEqual(double a, double b) {
    return std::abs(a - b) < 0.001;
}

int main() {
    const std::string testFile = "test_expenses.csv";
    std::remove(testFile.c_str());

    {
        ExpenseManager manager(testFile);

        assert(approximatelyEqual(manager.getTotalSpending(), 0.0));

        manager.addExpense(Expense("Lunch", "Food", 12.50));
        manager.addExpense(Expense("Bus ticket", "Transport", 3.00));

        assert(approximatelyEqual(manager.getTotalSpending(), 15.50));
    }

    {
        ExpenseManager reloadedManager(testFile);

        assert(approximatelyEqual(
            reloadedManager.getTotalSpending(), 15.50));
    }

    std::remove(testFile.c_str());

    std::cout << "All ExpenseManager tests passed!\n";
    std::cout << "Saving and loading test passed!\n";

    return 0;
}
