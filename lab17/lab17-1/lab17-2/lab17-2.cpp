#include <iostream>
#include <cstdarg>

int as(int n, ...) {
    int* p = &n;
    int sum = 0;

    if (n >= 3) {
        sum = *(p + 1) * *(p + 2);
        for (int i = 3; i <= n; ++i) {
            if (i % 2 == 0) {
                sum -= *(p + i);
            }
            else {
                sum += *(p + i);
            }
        }
    }
    else if (n == 2) {
        sum = *(p + 1) * *(p + 2);
    }
    else if (n == 1) {
        sum = *(p + 1);
    }

    return sum;
}

int main() {
    setlocale(LC_ALL, "Rus");

    std::cout << as(6, 4, 5, 1, 2, 3, 2) << std::endl;
    std::cout << as(2, 34, 4445) << std::endl;
    std::cout << as(7, 4, 5, 1, 2, 5, 7, 5) << std::endl;

    return 0;
}
