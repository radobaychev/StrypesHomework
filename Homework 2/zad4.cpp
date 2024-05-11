#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

void printUsage() {
    std::cerr << "Usage: a.out <file> [-n <number of lines>] [-c <number of characters>]" << std::endl;
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
                ++i;
            } else {
                printUsage();
                return 1;
            }
        }
        else {
            printUsage();
            return 1;
        }
    }

    if (numLines <= 0) {
        std::cerr << "Error: Invalid number of lines/characters specified." << std::endl;
        return 1;
    }

    std::vector<std::string> lines;
    std::string line;
    int totalChars = 0;

    while (std::getline(file, line)) {
        if (numLines > 0 && lines.size() >= static_cast<size_t>(numLines)) {
            lines.erase(lines.begin());
        }

        lines.push_back(line);
    }

    for (const auto& l : lines) {
        std::cout << l << std::endl;
    }

    return 0;
}
