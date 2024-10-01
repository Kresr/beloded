#include <iostream>

int main() {
    setlocale(LC_ALL, "RUS");
    char inputString[100];
     
    // Ввод строки
    std::cout << "Введите строку: ";
    char c;
    int i = 0;
    while ((c = getchar()) != '\n' && i < 99) {
        if (c != '*') {
            *(inputString + i++) = c;
            *(inputString + i++) = c; // Повторение символа
        }
    }
    *(inputString + i) = '\0'; // Установка конечного символа строки

    // Вывод результата
    std::cout << "Результат: ";
    for (int j = 0; *(inputString + j) != '\0'; ++j) {
        std::cout << *(inputString + j);
    }
    std::cout << std::endl;

    return 0;
}
