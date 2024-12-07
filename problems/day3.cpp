#include "problems.h"

void problems::day3() {
    std::ifstream file("../inputs/problem3.txt");
    if(!file.is_open()) {
        std::cerr << "File not found." << std::endl;
        return;
    }

    std::string line;

    bool enabled = true;
    int result1 = 0;
    int result2 = 0;

    while(std::getline(file, line)) {
        std::string text = line;
        std::regex pattern(R"(mul\((\d+),(\d+)\)|do\(\)|don't\(\))");
        std::smatch match;
    
        std::string::const_iterator searchStart(text.cbegin());

        while (std::regex_search(text, match, pattern)) {
            if(match.str(0).substr(0, 3) == "mul") {
                int x = std::stoi(match[1]);
                int y = std::stoi(match[2]);
                result1 += x * y;
                if(enabled) result2 += x * y;
            } else if(match.str(0) == "do()") {
                enabled = true;
            } else if(match.str(0) == "don't()") {
                enabled = false;
            }
            text = match.suffix();  // Continue with remaining string
        }
    }

    std::cout << "3.1) " << result1 << std::endl;
    std::cout << "3.2) " << result2 << std::endl;
}   