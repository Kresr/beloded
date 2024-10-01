#include <iostream>

int main() {
    setlocale(LC_ALL, "RUS");

    const int maxLength = 100;
    char S[maxLength];
    char S1[maxLength];

    std::cout << "Введите строку S: ";
    char c;
    int i = 0;
    while ((c = getchar()) != '\n' && i < maxLength - 1) {
        S[i++] = c;
    }
    S[i] = '\0'; // Установка конечного символа строки

    std::cout << "Введите подстроку S1: ";
    i = 0;
    while ((c = getchar()) != '\n' && i < maxLength - 1) {
        S1[i++] = c;
    }
    S1[i] = '\0'; // Установка конечного символа строки

    int n, k;
    std::cout << "Введите позицию n для вставки и длину подстроки k: ";
    std::cin >> n >> k;

    // Вставка подстроки S1 в строку S
    int lenS = 0;
    while (S[lenS] != '\0') {
        ++lenS;
    }

    int lenS1 = 0;
    while (S1[lenS1] != '\0' && lenS1 < k) {
        ++lenS1;
    }

    if (n < 0 || n > lenS) {
        std::cout << "Ошибка: некорректная позиция для вставки." << std::endl;
        return 1;
    }

    if (lenS + lenS1 > maxLength - 1) {
        std::cout << "Ошибка: превышена длина строки." << std::endl;
        return 1;
    }

    // Сдвигаем часть строки S после позиции n на lenS1 позиций вправо
    for (int i = lenS + lenS1; i >= n + lenS1; --i) {
        S[i] = S[i - lenS1];
    }

    // Копируем подстроку S1 в строку S
    for (int i = 0; i < lenS1; ++i) {
        S[n + i] = S1[i];
    }

    // Вывод результата
    std::cout << "Результат: ";
    for (int i = 0; i < lenS + lenS1; ++i) {
        std::cout << S[i];
    }
    std::cout << std::endl;

    return 0;
}


