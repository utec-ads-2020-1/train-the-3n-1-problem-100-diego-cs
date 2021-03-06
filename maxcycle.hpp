#ifndef MAXCYCLE_HPP
#define MAXCYCLE_HPP

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm> // std::remove_if, std::move

std::vector<std::string> generate_range(std::string& line) {
    std::string number{" "};
    std::vector<std::string> numbers = {}; // i and j
    std::stringstream stream(line); // internal memory buffer

    while (getline(stream, number, ' '))
            numbers.push_back(number);

    /* Erases the empty values from vector, std::remove_if returns an iterator to the element that follows the last element not removed  */
    numbers.erase(std::remove_if(numbers.begin() + 2, numbers.end(), [](const std::string& s) { return s.find(" ", 0); }), numbers.end());
    return numbers;
}

int cycle(int n) {
    if (n == 1) return 1;
    return cycle(n % 2 != 0 ? 3 * n + 1 : n / 2) + 1;
}

void max_cycle(std::string& line) {
    auto numbers = std::move(generate_range(line));

    if (numbers.size() == 2) { // i and j only validation
        int i = std::stoi(numbers[0]);
        int j = std::stoi(numbers[1]);
        if (i > j) std::swap(i, j);  
        int max = cycle(j);
        for (i; i <= j; ++i) {
            if (cycle(i) > max)
                max = cycle(i);
        }
        std::cout << numbers[0] << " " << numbers[1] << " " << max << std::endl;
    }
    else if (numbers.size() == 0)
        std::cout << std::endl;
}

#endif