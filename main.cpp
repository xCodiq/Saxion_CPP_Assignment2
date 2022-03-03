/**
 * C++ Foundations - SAXION 2022
 *
 * Project: Assignment 2
 * Datum: 14-02-2022 -> 21-02-2022
 * Door: Elmar Blume
 */

#include <iostream>
#include <sstream>

#include "util/textfile/TextfileUtil.h"
#include "transaction/Transaction.h"
#include "program/Program.h"

using std::cout, std::cin, std::endl, std::getline, std::ifstream, std::string;

int main() {
    // Prompt the user for the name of the file to open
    const string fileName{TextfileUtil::promptFileName()};

    // Create a new input file stream, and validate it through the text file utility class
    ifstream inputStream(fileName);
    if (!TextfileUtil::validateInputStream(&inputStream, "File does not exist!")) return 1;
    else cout << endl << "Opening \"" << fileName << "\"" << endl;

    // Initialize a new transaction list class for the Program to use
    TransactionList transactionList = TransactionList::initializeTransactionList(inputStream);

    // Create a new program object for the user to interact with
    Program program = Program(transactionList);

    // Run the program while the state is RUNNING
    while (program.getProgramState() == ProgramState::RUNNING) {
        string optionLine{};

        // Get a new line from the console and assign it to optionLine string variable
        while (getline(cin, optionLine)) {

            // Process the menu option
            program.processMenuOption(std::stoi(optionLine));
            cout << endl;

            // Check if the state changed to STOPPING, break out of loop if it did
            if (program.getProgramState() == ProgramState::STOPPING) break;
        }
    }

    return 0;
}
