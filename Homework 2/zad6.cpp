#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

void printUsage() {
    std::cerr << "Usage: a.out <file>" << std::endl;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printUsage();
        return 1;
    }

    std::string fileName = argv[1];
    std::ifstream file(fileName);

    if (!file) {
        std::cerr << "Error: Unable to open file." << std::endl;
        return 1;
    }

    int lineCount = 0;
    int wordCount = 0;
    int charCount = 0;

    std::string line;
    while (std::getline(file, line)) {
        ++lineCount;
        charCount += line.length() + 1;

        std::stringstream ss(line);
        std::string word;
        while (ss >> word) {
            ++wordCount;
        }
    }

    std::cout << "Lines: " << lineCount << std::endl;
    std::cout << "Words: " << wordCount << std::endl;
    std::cout << "Characters: " << charCount << std::endl;

    return 0;
}
