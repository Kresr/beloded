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
        arr[i] = std::rand() % 100; 
    }
    std::cout << "Исходный массив: ";
    for (const auto& elem : arr) {
        std::cout << elem << " ";
    }
    std::cout << "\n";
    int minIndex = 0, maxIndex = 0;
    for (int i = 1; i < size; ++i) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    int start = std::min(minIndex, maxIndex) + 1;
    int end = std::max(minIndex, maxIndex);

    while (start < end) {
        std::swap(arr[start], arr[end]);
        ++start;
        --end;
    }
    std::cout << "Результирующий массив: ";
    for (const auto& elem : arr) {
        std::cout << elem << " ";
    }
    std::cout << "\n";
    return 0;
}

