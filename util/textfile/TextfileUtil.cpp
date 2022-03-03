//
// Created by elmar on 15/02/2022.
//

#include "TextfileUtil.h"

// Implementation of the TextfileUtil namespace
namespace TextfileUtil {

    // Implementation of TextfileUtil::promptFileName();
    string promptFileName() {
        string fileName{};
        cout << "Please enter a file name:";

        // Read the first line that is entered in the console
        getline(cin, fileName);

        // Check if the entered input is valid/successful and not empty
        if (!cin.fail() && !fileName.empty()) return fileName;

        // Clear the input, and ignore until a line break
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // Send an error message to the console, and call it's self
        cout << "Something went wrong while prompting for a file name!" << endl;
        return promptFileName();
    }

    // Implementation of TextfileUtil::convertFileNameToOutputFileName(const string &fileName);
    string convertFileNameToOutputFileName(const string &fileName) {
        // Look for the period in the $fileName
        std::basic_string<char>::size_type position = fileName.find('.');

        // Check if the position equals a non position character
        if (position == string::npos) return fileName + ".out";

        // Return a sub string of $fileName at index 0->position and concat '.out' at the end
        return fileName.substr(0, position) + ".out";
    }

    // Implementation of TextfileUtil::validateInputStream(const ifstream *inputStream, const string &errorMessage);
    bool validateInputStream(const ifstream *inputStream, const string &errorMessage) {
        const bool isOpen = inputStream->is_open();

        // Check if the file is open, if not, send an error message to the console
        Validator::checkExpression(!isOpen, errorMessage);

        // Return the result of the validation process
        return isOpen;
    }
}
