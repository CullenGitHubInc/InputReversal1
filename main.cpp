#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

// this function is to append the user input into the file
void appendToFile(const std::string& filename, const std::string& userInput) {
    std::ofstream outFile(filename, std::ios::app); // this opens the file to allow the append to occur

    if (outFile.is_open()) {
        outFile << userInput << std::endl; // this part checks to see if file properly opened. If so, it then appends user input and gives user feeback

        outFile.close();
        std::cout << "Data successfully appended to " << filename << std::endl;
    } else {
        std::cerr << "Error opening file for appending." << std::endl;
    }
}

// this is to reverse file content and then to store in a new file
void reverseFileContent(const std::string& inputFilename, const std::string& outputFilename) {
    std::ifstream inFile(inputFilename);
    std::ofstream outFile(outputFilename);

    if (inFile.is_open() && outFile.is_open()) {
        // this reads the contents of the entire file  
        std::string content((std::istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>());
        inFile.close(); // this closes the input file once its read

        // reversing content
        std::reverse(content.begin(), content.end());
        // reversed content is written to the output file
        outFile << content;
        outFile.close();
        std::cout << "Reversed content successfully written to " << outputFilename << std::endl;
    } else {
        std::cerr << "Error opening files for reading/writing." << std::endl;
    }
}

int main() {
    std::string userInput;
    const std::string inputFilename = "CSC450_CT5_mod5.txt";
    const std::string outputFilename = "CSC450_mod5_reverse.txt";

    // retireving input from user
    std::cout << "Enter text to append to the file: ";
    std::getline(std::cin, userInput);

    // appending input to file
    appendToFile(inputFilename, userInput);

    // reversing file content and storing it in the new file
    reverseFileContent(inputFilename, outputFilename);

    return 0;
}
