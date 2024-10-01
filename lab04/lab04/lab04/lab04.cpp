#include <iostream>
int main()
{
    setlocale(LC_CTYPE, "Russian");
    int n,a,b,c;
    printf("Введите натуральное трехзначное число: ");
    scanf_s("%f", &n);

     a = n % 10;       // Единицы
     b= (n / 10) % 10; // Десятки
     c = n / 100;      // Сотни

    if (a == 0 ||a == 9 || b == 0 || b == 9 || c == 0 || c == 9) 
    {
        printf("Да, среди цифр числа есть 0 или 9.\n");
    }
    else {
        printf("Нет, среди цифр числа нет 0 или 9.\n");
    }

    return 0;
}