#ifndef EXPENSE_MANAGER_H
#define EXPENSE_MANAGER_H

#include "Expense.h"

#include <string>
#include <vector>

class ExpenseManager {
public:
    explicit ExpenseManager(std::string filename);

    void addExpense(const Expense& expense);
    void displayExpenses() const;
    double getTotalSpending() const;

private:
    std::string filename_;
    std::vector<Expense> expenses_;

    void loadExpenses();
    void saveExpenses() const;
};

#endif
