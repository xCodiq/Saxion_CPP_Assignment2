//
// Created by elmar on 15/02/2022.
//

#include <iostream>
#include <string>

#ifndef ASSIGNMENT2_VALIDATOR_H
#define ASSIGNMENT2_VALIDATOR_H

using std::cout, std::endl, std::string;

namespace Validator {

    /**
     * Check if the specified expression is correct, if not, print a
     * fail message to the console as feedback
     *
     * @param expression the expression to check
     * @param failMessage the fail message to send
     */
    void checkExpression(bool expression, const string &failMessage);
}

#endif //ASSIGNMENT2_VALIDATOR_H
