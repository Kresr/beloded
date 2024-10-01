#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
int main() {
    setlocale(LC_ALL, "rus");
    std::srand(std::time(0));
    std::cout << "Введите размер массива: ";
    int size;
    std::cin >> size;
    std::vector<int> arr(size);
    for (int i = 0; i < size; ++i) {
        arr[i] = std::rand() % 100; 
    }
    std::cout << "Исходный массив: ";
    for (const auto& elem : arr) {
        std::cout << elem << " ";
    }
    std::cout << "\n";
    int currentCount = 1;
    int maxCount = 1;

    for (int i = 1; i < size; ++i) {
        if (arr[i] == arr[i - 1]) {
            currentCount++;
        }
        else {
            currentCount = 1;
        }

        if (currentCount > maxCount) {
            maxCount = currentCount;
        }
    }
    if (maxCount > 1) {
        std::cout << "Наибольшее число подряд идущих одинаковых элементов: " << maxCount << "\n";
    }
    else {
        std::cout << "В массиве нет подряд идущих одинаковых элементов.\n";
    }
    return 0;
}

