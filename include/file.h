//
// Created by jorda on 12/8/2025.
//

#ifndef HONORSEDIT_FILE_H
#define HONORSEDIT_FILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <QString>
#include "budgetmanager.h"

using namespace std;

class File {
public:

    int printToFile(vector<Expense> vec1,vector<Income> vec2, QString leftOverAmount) {

        ofstream outFile("budgetdata.txt");
        if (!outFile) {
            cerr << "Error opening file.\n";
            return 1;
        }

        outFile << "Expenses:\n";
        for (int i; i<vec1.size(); i++) {
            outFile << vec1[i]  << " ";
        }
        outFile << "\n\n";

        outFile << "Savings:\n";
        for (int i; i<vec2.size(); i++) {
            outFile << vec2[i] << " ";
        }
        outFile << leftOverAmount.toStdString();
        outFile << "\n";

        outFile.close();
        cout << "\nData successfully written to budgetdata.txt\n";

        return 0;
    }


};

#endif //HONORSEDIT_FILE_H