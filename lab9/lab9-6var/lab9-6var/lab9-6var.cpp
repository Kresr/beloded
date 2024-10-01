#include <iostream>
#include <vector>

int main() {
    setlocale(LC_ALL, "rus");
    std::cout << "Введите размер массива: ";
    int size;
    std::cin >> size;
    std::vector<int> arr(size);
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 10; 
    }
    std::cout << "Исходный массив: ";
    for (const auto& elem : arr) {
        std::cout << elem << " ";
    }
    std::cout << "\n";

    int valueToDelete;
    std::cout << "Введите значение для удаления: ";
    std::cin >> valueToDelete; 
    arr.erase(std::remove(arr.begin(), arr.end(), valueToDelete), arr.end());
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] % 2 == 0) {
            arr.insert(arr.begin() + i, 1);
            ++i; 
        }
    }
    std::cout << "Результирующий массив: ";
    for (const auto& elem : arr) {
        std::cout << elem << " ";
    }
    std::cout << "\n";

    return 0;
}
