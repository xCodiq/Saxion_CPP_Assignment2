//
// Created by elmar on 15/02/2022.
//

#include "Validator.h"

namespace Validator {

    // Implementation of Validator::checkExpression(bool expression, const string &failMessage);
    void checkExpression(bool expression, const string &failMessage) {
        // Check if the expression returns true
        if (expression) {
            // Print the fail message to the console
            cout << failMessage << endl;
        }
    }
}
