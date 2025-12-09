#include "../include/budgetmanager.h"

using namespace std;

BudgetManager::BudgetManager() {
}

void BudgetManager::addIncome(const Income &income)
{
    member_incomes.push_back(income);
}

//Add expense to expense vector
void BudgetManager::addExpense(const Expense &expense)
{
    member_expenses.push_back(expense);
}

//Add income to income vector
double BudgetManager::totalIncome() const
{
    double sum = 0.0;
    for (const auto &income : member_incomes) {
        sum += income.amount;
    }
    return sum;
}

double BudgetManager::totalExpenses() const
{
    double sum = 0.0;
    for (const auto &expense : member_expenses) {
        sum += expense.amount;
    }
    return sum;
}

double BudgetManager::netBalance() const
{
    return totalIncome() - totalExpenses();
}

//getter for Income
const QVector<Income>& BudgetManager::getIncomes() const
{
    return member_incomes;
}

//getter for Expense
const QVector<Expense>& BudgetManager::getExpenses() const
{
    return member_expenses;
}

void BudgetManager::removeIncomeAt(int index)
{
    if (index >= 0 && index < member_incomes.size()) {
        member_incomes.removeAt(index);
    }
}
