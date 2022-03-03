//
// Created by elmar on 02/03/2022.
//
#include "../transaction/Transaction.h"

#ifndef ASSIGNMENT2_PROGRAM_H
#define ASSIGNMENT2_PROGRAM_H

using std::cout, std::cin, std::endl, std::getline, std::ifstream, std::string;

/**
 * The Program enum, used for status checking on runtime
 */
enum ProgramState {
    /**
     * The ProgramState will be initially set to STARTING to avoid
     * problems with receiving input. The program will be set to RUNNING
     * once a new Program instance has been created
     */
    STARTING,

    /**
     * The ProgramState will be set to RUNNING if the program is currently
     * running and when the user is still able to provide input through the console
     */
    RUNNING,

    /**
     * The ProgramState will be set to STOPPING if the program is
     * about to close/end, meaning any provided input through the
     * console will be ignored and not processed
     */
    STOPPING
};

/**
 * The Program structure, holding the current transaction list
 */
class Program {
private:
    // The transaction list bound to runtime
    TransactionList transactionList;

    // The current state of the program
    ProgramState programState = ProgramState::STARTING;

public:
    /**
     * Constructs a new Program structure
     *
     * @param transactionList the transaction list to use for this Program
     */
    explicit Program(TransactionList &transactionList) {
        this->transactionList = transactionList;
        this->setProgramState(ProgramState::RUNNING);

        // Display the menu for the first time
        Program::displayMenu();
    }

    /**
     * Display the program menu to the console, showing all the
     * possible inputs to interact with the TransactionList
     */
    static void displayMenu();

    /**
     * Receive an input from the user through the console
     * and process it with the transaction list for the correct response
     */
    void processMenuOption(int option);

    /**
     * Gets the current state of the program
     *
     * @return the current state of the program
     */
    [[nodiscard]] ProgramState getProgramState() const;

    /**
     * Change the program state to a new program state
     *
     * @param programState the new program state
     */
    void setProgramState(ProgramState programState);
};


#endif //ASSIGNMENT2_PROGRAM_H
