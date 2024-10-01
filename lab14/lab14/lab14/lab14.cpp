#include <iostream>
#include <cmath>

void solveArrayTask() {
    int n;
    std::cout << "Введите размер массива: ";
    std::cin >> n;

    // Создание и ввод массива
    double* arr = new double[n];
    std::cout << "Введите элементы массива:\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    // Поиск номера минимального по модулю элемента
    int minModIndex = 0;
    for (int i = 1; i < n; ++i) {
        if (std::abs(arr[i]) < std::abs(arr[minModIndex])) {
            minModIndex = i;
        }
    }

    // Поиск первого отрицательного элемента
    int firstNegIndex = -1;
    for (int i = 0; i < n; ++i) {
        if (arr[i] < 0) {
            firstNegIndex = i;
            break;
        }
    }

    // Вычисление суммы модулей элементов после первого отрицательного
    double sumAfterNeg = 0;
    if (firstNegIndex != -1) {
        for (int i = firstNegIndex + 1; i < n; ++i) {
            sumAfterNeg += std::abs(arr[i]);
        }
    }

    // Вывод результатов
    std::cout << "Номер минимального по модулю элемента: " << minModIndex << std::endl;
    std::cout << "Сумма модулей элементов после первого отрицательного: " << sumAfterNeg << std::endl;

    // Освобождение выделенной памяти
    delete[] arr;
}

void solveMatrixTask() {
    int size;
    std::cout << "Введите размер матрицы: ";
    std::cin >> size;

    // Создание одномерного массива для представления матрицы
    int* matrix = new int[size * size];

    // Ввод элементов матрицы
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << "Введите элемент [" << i << "][" << j << "]: ";
            std::cin >> matrix[i * size + j];
        }
    }

    // Поиск произведения элементов в строках без отрицательных элементов
    int product = 1;
    for (int i = 0; i < size; ++i) {
        bool hasNeg = false;
        for (int j = 0; j < size; ++j) {
            if (matrix[i * size + j] < 0) {
                hasNeg = true;
                break;
            }
        }
        if (!hasNeg) {
            for (int j = 0; j < size; ++j) {
                product *= matrix[i * size + j];
            }
        }
    }

    // Поиск максимума среди сумм элементов диагоналей, параллельных главной диагонали
    int maxDiagonalSum = 0;
    for (int i = 0; i < size - 1; ++i) {
        int diagonalSum = 0;

        // Суммируем элементы первой диагонали
        for (int j = 0; j < size - i; ++j) {
            diagonalSum += matrix[(i + j) * size + j];
        }

        // Суммируем элементы второй диагонали
        for (int j = 0; j < size - i; ++j) {
            diagonalSum += matrix[j * size + (i + j)];
        }

        maxDiagonalSum = std::max(maxDiagonalSum, diagonalSum);
    }

    // Вывод результатов
    std::cout << "Произведение элементов в строках без отрицательных элементов: " << product << std::endl;
    std::cout << "Максимум среди сумм элементов диагоналей, параллельных главной диагонали: " << maxDiagonalSum << std::endl;

    // Освобождение выделенной памяти
    delete[] matrix;
}

int main() {
    setlocale(LC_ALL, "RUS");

    int choose;
    do {
        std::cout << "Выберете какую задачу решить:\n";
        std::cout << "1. Задача с массивами\n";
        std::cout << "2. Задача с матрицами\n";
        std::cout << "3. Выход\n";

        std::cin >> choose;
        switch (choose) {
        case 1:
            solveArrayTask();
            break;

        case 2:
            solveMatrixTask();
            break;

        case 3:
            break;

        default:
            std::cout << "Некорректный выбор.\n";
            break;
        }
    } while (choose != 3);

    return 0;
}

