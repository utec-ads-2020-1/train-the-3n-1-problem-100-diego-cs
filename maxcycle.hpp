#ifndef MAXCYCLE_HPP
#define MAXCYCLE_HPP

#include <iostream>
#include <vector>
#include <sstream>

int cycle(int n) {
    int count = 0;
    if (n == 1) return 1;
    else {
        while (n != 1) {
            if (n % 2 != 0)
                n = 3 * n + 1;    
            else
                n = n / 2;  
            ++count;        
        }
    }
    return count + 1;
}

void output(const std::string& line) {
    std::string number;
    std::vector<std::string> numbers;
    std::stringstream stream(line);

    while (getline(stream, number, ' '))
        numbers.push_back(number);
    if (numbers.size() == 2) { // i and j
        int i = std::stoi(numbers[0]);
        int j = std::stoi(numbers[1]);
        if (0 < i && i < j && j < 10000) {
            int max = cycle(i);
            for (i = i + 1; i <= j; ++i) {
                if (cycle(i) > max)
                    max = cycle(i);
            }
            std::cout << numbers[0] << " " << numbers[1] << " " << max << std::endl;
        }      
    }
}

#endif