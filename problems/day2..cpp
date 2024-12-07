#include "problems.h"

bool isSafe(std::vector<int> nums) {
    bool safe = true;
    bool isIncreasing = true;
    bool isDecreasing = true;
    for(size_t i = 1; i < nums.size(); i++) {
        int diff = nums[i] - nums[i-1];
        
        // Check if diff is not between 1 and 3
        if(std::abs(diff) > 3 || std::abs(diff) < 1) {
            safe = false;
            break;
        }

        // Update the increasing and decreasing flags
        if(diff < 0) {
            isIncreasing = false;
        } else if(diff > 0) {
            isDecreasing = false;
        } else {  // diff == 0
            safe = false;
            break;
        }

        // If sequence changes direction, line is not safe
        if(!isIncreasing && !isDecreasing) {
            safe = false;
            break;
        }
    }
    return safe;
}

void problems::day2() {
    std::ifstream file("../inputs/problem2.txt");
    if(!file.is_open()) {
        std::cerr << "File not found." << std::endl;
        return;
    }

    std::string line;
    int counterP1 = 0;
    int counterP2 = 0;

    while(std::getline(file, line)) {
        std::istringstream iss(line);
        std::vector<int> nums;
        int num;
        
        // Convert the line into a vector of integers
        while(iss >> num) {
            nums.push_back(num);
        }

        // Iterate over the line and check adjacent numbers
        bool safe = isSafe(nums);

        // If the line is safe increment the counter
        if(safe) counterP1++;

        // If line wasn't safe then remove each element iteratively and check if
        // the line is safe with the removal
        if(!safe) {
            for(size_t i = 0; i < nums.size(); i++) {
                std::vector<int> temp = nums;
                temp.erase(temp.begin() + i);
                safe = isSafe(temp);
                if(safe) break;
            }
        }

        if(safe) counterP2++;
        
    }

    std::cout << "2.1) " << counterP1 << std::endl;
    std::cout << "2.2) " << counterP2 << std::endl;
}