//
// Created by elmar on 15/02/2022.
//

#include "Transaction.h"

// Implementation of TransactionList::initializeTransactionList(ifstream &inputStream);
TransactionList TransactionList::initializeTransactionList(ifstream &inputStream) {
    // Declare a new TransactionList structure
    TransactionList transactionList{};
    string transactionLine{};

    // Loop through every line of the input stream, while the transaction list size is be low the max capacity
    while (getline(inputStream, transactionLine) && transactionList.size < TransactionList::MAX_TRANSACTIONS) {
        // Convert the read line to a Transaction structure
        Transaction transaction = Transaction::fromLine(transactionLine);

        // Append the newly created Transaction structure to the transactions array in TransactionList
        transactionList.appendTransaction(transaction);
    }

    // Return the populated TransactionList structure
    return transactionList;
}

// Implementation of TransactionList::appendTransaction(const Transaction &transaction);
void TransactionList::appendTransaction(const Transaction &transaction) {
    this->transactions[this->size++] = transaction;

    auto valueIterator = this->transactionResources.find(transaction.getIdentifier());
    if (valueIterator == this->transactionResources.end())
        this->transactionResources.insert_or_assign(transaction.getIdentifier(), transaction.getValue());
    else valueIterator->second += transaction.getValue();

}

// Implementation of TransactionList::getTransactions();
Transaction *TransactionList::getTransactions() {
    return this->transactions;
}

// Implementation of TransactionList::count();
int TransactionList::count() const {
    return this->size;
}

// Implementation of TransactionList::getTotalWhen(int when);
int TransactionList::getTotalWhen(int when) {
    int total{};

    // Loop through every transaction
    Transaction *currentTransactions = this->getTransactions();
    for (int i = 0; i < this->count(); ++i) {
        // Check if the index is at our when limit
        if (when == i + 1) break;

        // Add the transaction's value to the total
        total += currentTransactions[i].getValue();
    }

    // Return the total of combined values
    return total;
}

// Implementation of TransactionList::getMinimumResources();
int TransactionList::getMinimumResources() const {
    int minimum = 0;

    // Loop through all the entries of the transactionValues map
    for (const std::pair<const std::basic_string<char>, int> &entry: this->transactionResources) {
        const int value = entry.second;

        // Check if the value is greater than the current minimum
        if (value > minimum) minimum = value;
    }


    // Return the absolute minimum of required resources
    return minimum;
}

// Implementation of TransactionList::getTransactionResources();
std::map<string, int> TransactionList::getTransactionResources() {
    return this->transactionResources;
}

// Implementation of Transaction::fromLine();
Transaction Transaction::fromLine(const string &line) {
    // Find where the space is located in the line
    auto position = line.find(' ');

    // Sub string the line into the desired Transaction fields
    string identifier = line.substr(0, position);
    int value = std::stoi(line.substr(position + 1));

    // Declare a new Transaction structure
    Transaction transaction = Transaction(identifier, value);

    // Return the populated Transaction structure
    return transaction;
}

// Implementation of Transaction::getIdentifier();
string Transaction::getIdentifier() const {
    return this->identifier;
}

// Implementation of Transaction::getValue();
int Transaction::getValue() const {
    return this->value;
}
