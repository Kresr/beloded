#include <iostream>

int main() {
    setlocale(LC_ALL, "rus");

    int n, k;
    std::cout << "Введите размер первой последовательности: ";
    std::cin >> n;

    int x[100];
    std::cout << "Введите элементы первой последовательности: ";
    for (int i = 0; i < n; i++) {
        std::cin >> x[i];
    }

    std::cout << "Введите размер второй последовательности: ";
    std::cin >> k;

    int y[100];
    std::cout << "Введите элементы второй последовательности: ";
    for (int i = 0; i < k; i++) {
        std::cin >> y[i];
    }

    // Использование указателей для проверки подпоследовательности
    int* xPtr = x, * yPtr = y;

    while (xPtr < x + n && yPtr < y + k) {
        if (*xPtr == *yPtr) {
            ++yPtr;
        }
        ++xPtr;
    }

    if (yPtr == y + k) {
        std::cout << "y - подпоследовательность x\n";
    }
    else {
        std::cout << "y не является подпоследовательностью x\n";
    }

    return 0;
}



