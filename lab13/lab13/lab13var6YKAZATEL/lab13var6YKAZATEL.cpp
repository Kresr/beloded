#include <iostream>

int main() {
    setlocale(LC_ALL, "RUS");

    int N, M;
    std::cout << "Введите количество строк N: ";
    std::cin >> N;

    std::cout << "Введите количество столбцов M: ";
    std::cin >> M;

    // Выделение динамической памяти для двумерного массива
    int** A = new int*[N];
    for (int i = 0; i < N; ++i) {
        A[i] = new int[M]();  // Используем () для инициализации каждого элемента нулем
    }

    // Заполнение матрицы значениями (ваш ввод или другая инициализация)
    std::cout << "Введите элементы матрицы " << N << "x" << M << ":\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cin >> A[i][j];
        }
    }

    int P = 0, Q = 0;
    std::cout << "Введите номера столбцов P и Q для обмена: ";
    std::cin >> P >> Q;

    // Проверка корректности ввода
    if (P < 0 || P >= M || Q < 0 || Q >= M) {
        std::cout << "Ошибка: некорректные номера столбцов." << std::endl;

        // Освобождение выделенной памяти перед выходом из программы
        for (int i = 0; i < N; ++i) {
            delete[] A[i];
        }
        delete[] A;

        return 1;
    }

    // Обмен столбцов с номерами P и Q с использованием указателей
    for (int i = 0; i < N; ++i) {
        int* ptrP = A[i] + P;
        int* ptrQ = A[i] + Q;

        int temp = *ptrP;
        *ptrP = *ptrQ;
        *ptrQ = temp;
    }

    // Вывод обновленной матрицы с использованием указателей
    std::cout << "Матрица после обмена столбцов:\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cout << A[i][j] << ' ';
        }
        std::cout << '\n';
    }

    // Освобождение выделенной памяти
    for (int i = 0; i < N; ++i) {
        delete[] A[i];
    }
    delete[] A;

    return 0;
}



