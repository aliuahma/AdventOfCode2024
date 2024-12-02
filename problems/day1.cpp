#include "problems.h"

void problems::day1::historianHysteria() {
    std::ifstream file("../inputs/problem1.txt");
    if(!file.is_open()) {
        std::cerr << "File not found." << std::endl;
        return;
    }

    std::vector<int> vec1, vec2;
    std::string line;

    // Populate vec1 and vec2 with the numbers from the file
    while(std::getline(file, line)) {
        std::istringstream iss(line);
        int num1, num2;
        if(iss >> num1 >> num2) {
            vec1.push_back(num1);
            vec2.push_back(num2);
        }
    }

    // Sort the vectors to compare elements in ascending order
    std::sort(vec1.begin(), vec1.end());
    std::sort(vec2.begin(), vec2.end());

    // Sum the differences between the elements of vec1 and vec2
    int sumP1 = 0;
    for(int i = 0; i < vec1.size(); i++) {
        sumP1 += std::abs(vec1[i] - vec2[i]);
    }

    std::cout << "1.1) " << sumP1 << std::endl;

    std::unordered_map<int, int> frequencyMap;
    
    // First build a frequency map of vec2 elements
    for(int i = 0; i < vec2.size(); i++) {
        if(frequencyMap.find(vec2[i]) == frequencyMap.end()) {
            frequencyMap[vec2[i]] = 0;
        }
        frequencyMap[vec2[i]]++;
    }

    // Loop through vec1 and multiply the current number by the frequency of that number in vec2
    int sumP2 = 0;
    for(int i = 0; i < vec1.size(); i++) {
        if(frequencyMap.find(vec2[i]) == frequencyMap.end()) {
            frequencyMap[vec2[i]] = 0;
        }
        sumP2 += vec1[i] * frequencyMap[vec1[i]];
    }

    std::cout << "1.2) " << sumP2 << std::endl;
}   
