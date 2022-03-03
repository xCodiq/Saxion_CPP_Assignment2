//
// Created by elmar on 02/03/2022.
//

#include "Program.h"

// Implementation of Program::displayMenu();
void Program::displayMenu() {
    // Print the options menu to the console
    cout << endl;
    cout << "1. Count of transactions" << endl;
    cout << "2. Minimum resource size" << endl;
    cout << "3. All transactions" << endl;
    cout << "4. Transactions of id" << endl;
    cout << "5. Sum of claims until n" << endl;
    cout << "6. List identifiers" << endl;
    cout << "7. Validate" << endl;
    cout << "8. Quit" << endl;
    cout << endl;
}

// Implementation of Program::processMenuOption(int option);
void Program::processMenuOption(int option) {
    TransactionList currentTransactionList = this->transactionList;

    switch (option) {
        case 1:
            cout << "There are " << this->transactionList.count() << " transactions." << endl;
            break;
        case 2:
            cout << "The minimum resource size is " << this->transactionList.getMinimumResources() << endl;
            break;
        case 3: {
            std::map<string, int> values;
            Transaction *currentTransactions = currentTransactionList.getTransactions();

            for (int i = 0; i < this->transactionList.count(); ++i) {
                Transaction transaction = currentTransactions[i];

                const string identifier = transaction.getIdentifier();
                const int value = transaction.getValue();

                auto valueIterator = values.find(identifier);
                if (valueIterator == values.end()) values.insert_or_assign(identifier, value);
                else valueIterator->second += value;

                cout << i + 1 << "\t" << identifier << "\t" << value << "\t" << values.at(identifier) << endl;
            }
            break;
        }
        case 4: {
            cout << "ID:";
            string identifier{};

            int total = 0;
            while (getline(cin, identifier)) {
                Transaction *currentTransactions = currentTransactionList.getTransactions();

                for (int i = 0; i < this->transactionList.count(); ++i) {
                    Transaction transaction = currentTransactions[i];
                    if (transaction.getIdentifier() != identifier) continue;

                    const int value = transaction.getValue();
                    total += value;

                    cout << i + 1 << "\t" << identifier << "\t" << value << "\t" << total << endl;
                }
                break;
            }
            break;
        }
        case 5: {
            cout << "Until when:";
            string untilWhen{};

            while (getline(cin, untilWhen)) {
                int total = currentTransactionList.getTotalWhen(std::stoi(untilWhen));
                cout << "The sum of claims until " << untilWhen << " transactions is " << total << "." << endl;
                break;
            }

            break;
        }
        case 6: {
            for (const std::pair<const std::basic_string<char>, int> &entry: currentTransactionList.getTransactionResources()) {
                cout << entry.first << endl;
            }
            break;
        }
        case 7: {
            bool isValid = true;
            for (const std::pair<const std::basic_string<char>, int> &entry: currentTransactionList.getTransactionResources()) {
                if (entry.second < 0) {
                    isValid = false;
                    break;
                }
            }

            cout << "The list is" << (isValid ? " " : " not ") << "valid" << endl;
            break;
        }
        case 8:
            cout << endl << "Goodbye!";
            this->setProgramState(ProgramState::STOPPING);
            break;
        default:
            // No input option was found, display menu again
            this->displayMenu();
            break;
    }
}

// Implementation of Program::setProgramState(ProgramState newProgramState);
void Program::setProgramState(ProgramState newProgramState) {
    this->programState = newProgramState;
}

// Implementation of Program::getProgramState();
ProgramState Program::getProgramState() const {
    return this->programState;
}
