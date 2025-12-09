#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H
#include <QString>
#include <QDate>
#include <QVector>

struct Income {
    QString name;
    double amount;
    QDate date;
};

struct Expense {
    QString name;
    double amount;
    QDate date;
    QString category;
};


class BudgetManager {
public:
    BudgetManager();

    // add items
    void addIncome(const Income &income);
    void addExpense(const Expense &expense);

    // remove items
    void removeIncomeAt(int index);

    // totals
    double totalIncome() const;
    double totalExpenses() const;
    double netBalance() const;


    // getters for data
    const QVector<Income>& getIncomes() const;
    const QVector<Expense>& getExpenses() const;

private:
    QVector<Income> member_incomes;
    QVector<Expense> member_expenses;
};

#endif // BUDGETMANAGER_H