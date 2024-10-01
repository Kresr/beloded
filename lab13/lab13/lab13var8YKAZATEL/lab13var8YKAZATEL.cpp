#include <iostream>

int main() {
    setlocale(LC_ALL, "RUS");

    int N, M;
    std::cout << "Введите количество строк N: ";
    std::cin >> N;

    std::cout << "Введите количество столбцов M: ";
    std::cin >> M;

    // Выделение динамической памяти для двумерных массивов A и B
    int** A = new int* [N];
    int** B = new int* [N];
    for (int i = 0; i < N; ++i) {
        A[i] = new int[M];
        B[i] = new int[M];
    }

    // Заполнение матриц A и B значениями (ваш ввод или другая инициализация)
    std::cout << "Введите элементы матрицы A " << N << "x" << M << ":\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cin >> *(*(A + i) + j);
        }
    }

    std::cout << "Введите элементы матрицы B " << N << "x" << M << ":\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cin >> *(*(B + i) + j);
        }
    }

    // Подсчет количества пар для каждого условия
    int countLess = 0;
    int countEqual = 0;
    int countGreater = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (*(*(A + i) + j) < *(*(B + i) + j)) {
                ++countLess;
            }
            else if (*(*(A + i) + j) == *(*(B + i) + j)) {
                ++countEqual;
            }
            else {
                ++countGreater;
            }
        }
    }

    // Вывод результатов
    std::cout << "Количество пар (aij, bij) таких, что aij < bij: " << countLess << std::endl;
    std::cout << "Количество пар (aij, bij) таких, что aij = bij: " << countEqual << std::endl;
    std::cout << "Количество пар (aij, bij) таких, что aij > bij: " << countGreater << std::endl;

    // Освобождение выделенной памяти
    for (int i = 0; i < N; ++i) {
        delete[] A[i];
        delete[] B[i];
    }
    delete[] A;
    delete[] B;

    return 0;
}

