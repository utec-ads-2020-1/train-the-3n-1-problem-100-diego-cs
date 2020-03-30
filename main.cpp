#include "maxcycle.hpp"

#define SIZE 1000000

/* compile -> g++ main.cpp -o exec*/
/* run     -> ./exec < input */

int main(int argc, char const *argv[]) {

    std::string line;  
    while(getline(std::cin, line))
        output(line);

    return EXIT_SUCCESS;
}