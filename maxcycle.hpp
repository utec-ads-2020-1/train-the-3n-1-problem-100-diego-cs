#ifndef MAXCYCLE_HPP
#define MAXCYCLE_HPP

#include <iostream>
#include <algorithm> // std::remove

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

void read() {
    std::string line;
    int i, j;
    //char remainder[SIZE];
    
    while (getline(std::cin, line)) {
        line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
        //int ret = sscanf(line.c_str(), "%d%d%s", &i, &j, remainder);
        bool isCorrect = !(i < 0 || (j > i && j < 10000));

        if (isCorrect) {
            int max = cycle(i);
            for (i = i + 1; i <= j; ++i) {
                if (cycle(i) > max)
                    max = cycle(i);
            std::cout << max << std::endl;
            }    
            isCorrect = false;
        }    
    }
}

#endif