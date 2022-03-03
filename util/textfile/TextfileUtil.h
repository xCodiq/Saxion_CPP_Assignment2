//
// Created by elmar on 15/02/2022.
//

#include <iostream>
#include <string>
#include <fstream>
#include "../validation/Validator.h"

#ifndef ASSIGNMENT2_TEXTFILEUTIL_H
#define ASSIGNMENT2_TEXTFILEUTIL_H

using std::string, std::cout, std::cin, std::endl, std::getline, std::ifstream;

namespace TextfileUtil {

    /**
     * Prompt the user for a file name which will be used
     * as the name for the input stream
     *
     * NOTE: Recursive call if input has failed
     *
     * @return the name of the file
     * @uses std::getline(), std::ignore()
     */
    string promptFileName();

    /**
     * Convert an input file name to an output file name.
     * Example: alice.txt -> alice.out
     *
     * @param fileName the file name to convert
     * @return the output file name of $fileName
     */
    string convertFileNameToOutputFileName(const string &fileName);

    /**
     * Check if the input stream opened a file successfully
     *
     * @param inputStream the input stream that is suppose to open a file
     * @param errorMessage the detailed error message sent to the console
     * @return Returns true if the input stream is valid, false otherwise
     */
    bool validateInputStream(const ifstream *inputStream, const string &errorMessage);
}


#endif //ASSIGNMENT2_TEXTFILEUTIL_H
