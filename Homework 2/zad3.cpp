#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

void printUsage() {
    std::cerr << "Usage: a.out <file> [-n <number of lines>]" << std::endl;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printUsage();
        return 1;
    }

    std::string fileName = argv[argc - 1];
    std::ifstream file(fileName);

    if (!file) {
        std::cerr << "Error: Unable to open file." << std::endl;
        return 1;
    }

    int numLines = 10; 

    for (int i = 1; i < argc - 1; ++i) {
        if (std::string(argv[i]) == "-n") {
            if (i + 1 < argc) {
                numLines = std::atoi(argv[i + 1]);
                if (numLines <= 0) {
                    std::cerr << "Error: Invalid number of lines specified." << std::endl;
                    return 1;
                }
                ++i;
            } else {
                printUsage();
                return 1;
            }
        } else {
            printUsage();
            return 1;
        }
    }

    std::string line;
    int totalChars = 0;
    int linesPrinted = 0;

    while (std::getline(file, line)) {
        if (numLines > 0 && linesPrinted >= numLines) {
            break;
        }

        std::cout << line << std::endl;
        ++linesPrinted;
    }

    return 0;
}
