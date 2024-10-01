#include <iostream>

int main() {
    setlocale(LC_ALL, "RUS");
    int n, sum = 0,num;
    printf("Введите количество элементов в последовательности: ");
    scanf_s("%d", &n);

    

    printf("Введите %d целых чисел:\n", n);
    for (int i = 0; i < n; i++) {
        scanf_s("%d", &num);

        if (num % 2 == 0) {
            sum += num;
        }
    }

    printf("Сумма четных элементов: %d\n", sum);

    return 0;
}
