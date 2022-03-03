//
// Created by elmar on 15/02/2022.
//

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <utility>
#include <map>

#ifndef ASSIGNMENT2_TRANSACTION_H
#define ASSIGNMENT2_TRANSACTION_H

using std::string, std::cout, std::cin, std::endl, std::getline, std::ifstream, std::istringstream;

/**
 * The Transaction structure, holding a identifier and a value
 */
class Transaction {
private:
    // The identifier/name of the transaction
    string identifier{};

    // The amount involved with the transaction, this can be any whole number
    int value{};

public:
    /**
     * Constructs a new Transaction structure
     *
     * @param identifier the identifier of the transaction
     * @param value the value of the transaction
     */
    Transaction(string &identifier, int &value) {
        this->identifier = identifier;
        this->value = value;
    }

    /**
     * Constructs an empty Transaction structure, it's fields
     * are yet to be assigned to actual data
     */
    Transaction() = default;

    /**
     * Create a new Transaction structure from a string line
     *
     * @param line the string that contains the data
     * @return A populated Transaction structure
     */
    static Transaction fromLine(const string &line);

    /**
     * Gets the identifier of the Transaction
     *
     * @return the identifier of the transaction structure
     */
    [[nodiscard]] string getIdentifier() const;

    /**
     * Gets the value of the Transaction
     *
     * @return the value of the transaction structure
     */
    [[nodiscard]] int getValue() const;
};

/**
 * The TransactionList structure, holding all the appended transactions
 * NOTE: TransactionList#transactions has a max capacity of a 100 transactions
 */
class TransactionList {
public:
    // The max capacity of transactions possible
    static const int MAX_TRANSACTIONS{100};

private:
    // The transactions array to store all the transactions in
    Transaction transactions[MAX_TRANSACTIONS]{{}};

    // The actual count of transactions stored in the array
    int size{};

    std::map<string, int> transactionResources{};

public:
    /**
     * Initialize the new transaction list, reading the values in a
     * text file, putting them in to the transactions array
     *
     * @param inputStream the input stream of the file to read from
     */
    static TransactionList initializeTransactionList(ifstream &inputStream);

    /**
     * Append a transaction to the transactions array. This function
     * will also increase the TransactionList#size field.
     *
     * @param transaction the transaction to append
     */
    void appendTransaction(const Transaction &transaction);

    /**
     * Gets the registered/appended transactions in the transactions array
     *
     * @return the transactions array
     */
    Transaction *getTransactions();

    /**
     * Gets all the total transaction resources stored in a map with identifier as key
     *
     * @return am ap with total transaction resources
     */
    std::map<string, int> getTransactionResources();

    /**
     * Gets the total transaction resources up to a certain amount of transactions
     *
     * @param when the total transaction limit
     * @return the total of resources up to a certain amount of transactions
     */
    int getTotalWhen(int when);

    /**
     * Gets the minimum required resources
     *
     * @return the minimum resources
     */
    [[nodiscard]] int getMinimumResources() const;

    /**
     * Return the TransactionList#size field, which represents the amount
     * of transactions existing in the transactions array
     *
     * @return the amount of transactions in the transactions array
     */
    [[nodiscard]] int count() const;
};


#endif //ASSIGNMENT2_TRANSACTION_H
