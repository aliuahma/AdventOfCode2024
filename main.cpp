#include <conio.h>
#include <functional>

#include "problems/problems.h"

int main() {
    std::unordered_map<std::string, std::function<void()>> problemMap;
    problemMap["1"] = problems::day1;
    problemMap["2"] = problems::day2;
    problemMap["3"] = problems::day3;
    problemMap["4"] = problems::day4;
    problemMap["5"] = problems::day5;
    problemMap["6"] = problems::day6;
    problemMap["7"] = problems::day7;

    std::cout << "Enter a day number (1-30) or press ESC, 'exit', or '0' to quit..." << std::endl;
    std::string input;
    while(true) {
        // Check for ESC key press
        if(_kbhit()) {
            int ch = _getch();
            if (ch == 27) { // ESC key
                break;
            }
        }

        std::getline(std::cin, input);

        if(input == "exit" || input == "0") {
            break;
        }

        auto it = problemMap.find(input);
        if(it != problemMap.end()) {
            it->second();
            std::cout << "Enter another day number (1-30) or press ESC, 'exit', or '0' to quit..." << std::endl;
        } else {
            std::cout << "Invalid input. Please enter a day number (1-30) or press ESC, 'exit', or '0' to quit..." << std::endl;
        }
    }
    return 0;
}