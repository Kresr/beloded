#include <iostream>

int main() {
    setlocale(LC_ALL, "rus");

    // Ввод размера массива n и числа k
    int n, k;
    std::cout << "Введите размер массива: ";
    std::cin >> n;

    int* A = new int[n]; // Динамический массив

    // Ввод элементов массива
    std::cout << "Введите элементы массива:\n";
    for (int* ptr = A; ptr < A + n; ++ptr) {
        std::cin >> *ptr;
    }

    std::cout << "Введите число k: ";
    std::cin >> k;

    // Поиск номеров элементов
    std::cout << "Номера элементов, равных k: ";
    for (int i = 0; i < n; ++i) {
        if (A[i] == k) {
            std::cout << i << " ";
        }
    }

    std::cout << "\nНомера элементов, меньших k: ";
    for (int i = 0; i < n; ++i) {
        if (A[i] < k) {
            std::cout << i << " ";
        }
    }

    std::cout << "\nНомера элементов, больших k: ";
    for (int i = 0; i < n; ++i) {
        if (A[i] > k) {
            std::cout << i << " ";
        }
    }

    delete[] A; // Освобождение памяти после использования динамического массива

    return 0;
}

