#include "Expense.h"

#include <cassert>
#include <iostream>

int main() {
    Expense expense("Lunch", "Food", 12.50);

    assert(expense.getDescription() == "Lunch");
    assert(expense.getCategory() == "Food");
    assert(expense.getAmount() == 12.50);

    std::cout << "All Expense tests passed!\n";
    return 0;
}
