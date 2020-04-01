#include <iostream>
#include <chrono>

int cycle(int n) {
    if (n == 1) return 1;
    return cycle(n % 2 != 0 ? 3 * n + 1 : n / 2) + 1;
}

void max_cycle(int a, int b) {
    while ((scanf("%d %d", &a, &b)) == 2) {
        int i = a;
        int j = b;
        if (i > j) std::swap(i, j);
        int max = cycle(i);
        for (i; i <= j; ++i)
            if (cycle(i) > max)
                max = cycle(i);

        std::cout << a << " " << b << " " << max << std::endl;
    }
}

int main(int argc, char *argv[]) {

    int a, b;
    max_cycle(a, b);
   
    return 0;
}