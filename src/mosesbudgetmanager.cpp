// Brambila, Moses
// 12.8.2025
// Fall 2025 | San Diego Miramar College
// CISC 192-3001 C/C++ Programming | (12104)

//-------9.1 Final Project
//Objective:
//  "Apply your knowledge of programming by creating a simple, yet
//meaningful C++ program that demonstrates all 8 major course
//topics."



//-----begining of headers--------------------
#include <iostream>//for inputs & outputs
#include <string>  //for strings
#include <limits>  //for input cleanup
#include <fstream> //for the files

using namespace std; //no more "std::"
//-----end of headers-------------------------

//Programmers Comments:
//  I have begun this project with the consideration that we begin thinking from the inside and work our way out. We
//  begin with the heart of a budget app which are the reason why we are making the app. The expenses. Our program is
//  holding our data via structs and then the functions we build will operate on said structs.

struct Expense { //The heart of our program. A combination of strings and doubles(names and quantities).
    string name;       //'name' is the current placeholder name for our "Expense" labels.(name of whatever expense)
    double amount;     //the expense will be a double data type and defined as 'amount'(cost of whatever expense)
};

// This is a function prototype for resizing the dynamic array
Expense* resizeExpenses(Expense* oldArray, int oldSize, int newSize);

// Again, working our way from the inside-out, we now are ready to get into the way we will mess with the data coming
// from these structs by using functions. Since we dont know how many of these 'expenses' our users will input, we have
// to use dynamic memory allocation.
void getExpenseDetails(Expense& exp);
void printBudgetReport(Expense* expenses, int count, double initialBudget);
void saveReportToFile(double initialBudget, double totalSpent, double remaining);

//-------------------------------------
//-----MAIN FUNCTION-------------------
//-------------------------------------
int main() {
    //in order to be a budget app, we need to have an initial budget
    double initialBudget = 0.0;
    int capacity = 5;       //Starting size for our dynamic array.
    int expenseCount = 0;   //we begin with an expense quantity of 0. Makes sense....

    // This is where we create the initial array based of our 'capacity' int from earlier and expenses becomes a pointer
    //for Expense
    Expense* expenses = new Expense[capacity];

    // Greet and initialize the budget
    cout << "Welcome to our budgeting app!\n";
    cout << "Please enter your total initial budget: $";
    cin >> initialBudget;

    //Clearing the enter key press
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    //Now that we are taking inputs from our user, we want to create door out of a loop we will use to see if their done
    //with their inputs.
    string userInput = "";    //where our users will place a y or n
    string doneResponse = ""; //new variable with y/n response
    bool isDone = false; //a boolean for y-true and n-false

    //isDone begins as false and continues to loop until isDone becomes true in this while loop.
    while (!isDone) {

        //first check, do we need to resize? Remember our capacity is an int with an initial value of 5. expenseCount
        //begins at 0. Once that limit is reached, we resize by a factor of 2.
        if (expenseCount == capacity) {
            cout << "\n* Array capacity reached. Doubling size to " << capacity * 2 << "...\n";
            expenses = resizeExpenses(expenses, expenseCount, capacity * 2); //pointer updates
            capacity *= 2; //capacity is now self-iterating
        }

        //Now that we've checked for the bounds of our array and grown them should they need, we can now move onto
        //adding the quantity of expenses by doing arithmetic on the expenseCount variable.
        cout << "\n--- Adding Expense " << expenseCount + 1 << " ---\n";

        //maybe use for descriptions and whatnot?
        //getExpenseDetails(expenses[expenseCount]);

        expenseCount++;

        //at this point the user has input atleast 1 expense and so the door is open to leave.
        cout << "Done entering expenses for now? (y/n): ";
        cin >> doneResponse;

        //check for case sensitivity in y or Y lol...
        if (doneResponse == "y" || doneResponse == "Y") {
            isDone = true; //Sets to true whether y or Y so the user doesn't feel wronged
        }

        //Clear the buffer after the y or n prompt
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    //end of while loop for isDone

    //now we are out of the input loop. At this point, we want to show the user what they've input(their expenses,
    //quantity of expenses, and budget)
    printBudgetReport(expenses, expenseCount, initialBudget); //remember those prototypes we declared before main()?

    //Dynamic memory cleanup
    delete[] expenses;
    expenses = nullptr;

    return 0; //gg?
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
