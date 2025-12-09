//
// Created by moses on 12/6/2025.
//

#include <iostream>
#include <string>
#include <limits>  //for input cleanup
#include <fstream> // for the files

// no more 'std::'
using namespace std;


//-----I have begun this project with the consideration that we begin thinking from the approach that we start from the
//inside and work our way out. We begin with the fundamental definition of how our program is holding the data most
//important to our program, expenses. They will be structs and then the functions we build will operate on said structs.
//
//  This is where I define a struct that will hold the data for our program
struct Expense {
    string name;       // 'name' is the current placeholder name for the expenses(name of whatever expense)
    double amount;     // the expense will be a double and defined as 'amount'(cost of whatever expense)
};

// This is a function prototype for resizing the dynamic array
Expense* resizeExpenses(Expense* oldArray, int oldSize, int newSize);

// Again, working our way from the inside-out, we now are ready to get into the way we will mess with the data coming
// from these structs by using functions. Since we dont know how many of these 'expenses' our users will input, we have
// to use a dynamic memory allocation. So we use an array and ony ask the computer for the exact memory we need wile the
// program is running.
void getExpenseDetails(Expense& exp);
void printBudgetReport(Expense* expenses, int count, double initialBudget);
void saveReportToFile(double initialBudget, double totalSpent, double remaining);

//-------------------------------------
//-----M A I N ___ F U N C T I O N-----
//-------------------------------------
int main() {
    //Simply declaring variables to be the starting point of the app
    double initialBudget = 0.0;
    int capacity = 5;       //Starting size for our dynamic array
    int expenseCount = 0;   //Keeps count of the numbers of expenses per array

    // This is where we create the initial array of 5 Expense structs. 'expenses' holds the address.(It's the pointer...)
    Expense* expenses = new Expense[capacity];

    // Greet and initialize the budget
    cout << "Welcome to our budgeting app!\n";
    cout << "Enter your total initial budget: $";
    cin >> initialBudget;

    //Clearing buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    //Sentinel-Controlled while loop that runs until the user lets us know they are done
    string userInput = "";
    string doneResponse = ""; //new variable with y/n response
    bool isDone = false; //Sentinel variable set to false

    //Loop runs until isDone becomes true
    while (!isDone) {

        //first check, do we need to resize?
        if (expenseCount == capacity) {
            cout << "\n* Array capacity reached. Doubling size to " << capacity * 2 << "...\n";
            expenses = resizeExpenses(expenses, expenseCount, capacity * 2);
            capacity *= 2;
        }

        //Now that we've checked for the bounds of our array and grown them should they need, we can now move onto
        //adding the Expense
        cout << "\n--- Adding Expense " << expenseCount + 1 << " ---\n";
        getExpenseDetails(expenses[expenseCount]);
        expenseCount++;

        //
        cout << "Done entering expenses for now? (y/n): ";
        cin >> doneResponse;

        //check for case sensitivity in y or Y lol...
        if (doneResponse == "y" || doneResponse == "Y") {
            isDone = true; //Sets the sentinel to true whether y or Y so the user doesn't feel wronged
        }

        //Clear the buffer after the y or n prompt
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    //end of while loop for isDone

    //At this point, we want to show the user what they've input(their expenses, quantity of expenses, and budget)
    printBudgetReport(expenses, expenseCount, initialBudget);

    //Dynamic Memory Cleanup
    delete[] expenses;
    expenses = nullptr;

    return 0;
}
//End of main()

//Now that the compiler knows all of our user input data, we can move onto the other file stuff

Expense* resizeExpenses(Expense* oldArray, int oldSize, int newSize) {
    //creation of larger array
    Expense* newArray = new Expense[newSize];

    for (int i = 0; i < oldSize; ++i) {
        newArray[i] = oldArray[i];
    }

    delete[] oldArray; //release memory from the old array

    return newArray; //return the address of the new array
}

void getExpenseDetails(Expense& exp) {
    cout << "   Enter name for expense: ";
    getline(cin, exp.name);

    double tempAmount;
    bool isValid = false;

    //do-while loop for inputs for previous functions
    do {
        cout << "   Enter amount for expense: $";
        cin >> tempAmount;

        //validation check
        if (cin.fail() || tempAmount <= 0.0) {
            cout << "   [Error] Invalid input. Amount must be a positive number.\n";
            //clears bad state and bad input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            isValid = true;
        }
    } while (!isValid);

    //then we assign the valid amount from the previous checks
    exp.amount = tempAmount;

    //now we clear the buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

//this is now were we get to the functions that calculate totals and print final
void printBudgetReport(Expense *expenses, int count, double initialBudget) {
    double totalSpent = 0.0;

    //iteration structure to sum all expenses
    for (int i = 0; i < count; ++i) {
        totalSpent += expenses[i].amount; //accumulate total
    }

    //remaining balance calculation
    double remaining = initialBudget - totalSpent;

    cout << "\n-------------------------\n";
    cout << "             Financial Report\n";
    cout << "Initial Budget: $" << initialBudget << endl;
    cout << "Total Expenses: $" << totalSpent << endl;

    //this is the over budget check
    if (remaining < 0) {
        cout << "\n** OVER BUDGET by: $" << remaining * -1 << " **\n";
    } else {
        cout << "Remaining Budget: $" << remaining << endl;
    }
    cout << "-------------------------\n";

    saveReportToFile(initialBudget, totalSpent, remaining);
}

//Function that saves the data to a file
void saveReportToFile(double initialBudget, double totalSpent, double remaining) {
    ofstream outFile("budget_report.txt");

    //check if the file successfully opened
    if (outFile.is_open()) {
        //write data to the file
        outFile << "-----Budget Report-----\n";
        outFile << "Initial Budget: $" << initialBudget << "\n";
        outFile << "Total Spent: $" << totalSpent << "\n";
        outFile << "Remaining Balance: $" << remaining << "\n";

        //close the file stream
        outFile.close();
        cout << "\n* Report save successful! File: budget_report.txt\n";
    } else {
        cout << "\n* Error... Unable to open file in order to save.\n";
    }
}
