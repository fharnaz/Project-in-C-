#ifndef EXPENSE_H
#define EXPENSE_H

#include <string>
#include <utility>

class Expense {
public:
    Expense(std::string description, std::string category, double amount)
        : description_(std::move(description)),
          category_(std::move(category)),
          amount_(amount) {}

    const std::string& getDescription() const {
        return description_;
    }

    const std::string& getCategory() const {
        return category_;
    }

    double getAmount() const {
        return amount_;
    }

private:
    std::string description_;
    std::string category_;
    double amount_;
};

#endif
