#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {
    setlocale(LC_ALL, "rus");
    std::cout << "Введите размер массива: ";
    int size;
    std::cin >> size;
    std::vector<int> arr(size);
    std::srand(std::time(0)); 
    for (int i = 0; i < size; ++i) {
        arr[i] = std::rand() % 10; 
    }
    std::cout << "Исходный массив: ";
    for (const auto& elem : arr) {
        std::cout << elem << " ";
    }
    std::cout << "\n";
    int maxElement = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }
    for (int i = 0; i < size; ++i) {
        if (i % 2 != 0) {
            arr[i] = maxElement;
        }
    }
    std::cout << "Результирующий массив: ";
    for (const auto& elem : arr) {
        std::cout << elem << " ";
    }
    std::cout << "\n";
    return 0;
}
