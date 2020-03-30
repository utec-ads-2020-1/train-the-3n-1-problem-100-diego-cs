#include "maxcycle.hpp"

/* compile -> g++ main.cpp -o exec*/
/* run     -> ./exec < input */

int main(int argc, char const *argv[]) {

    std::string line;  
    while(getline(std::cin, line))
        max_cycle(line);

    return EXIT_SUCCESS;
}