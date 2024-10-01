#include <stdio.h>
#include <iostream> 

int main()
{
    setlocale(LC_CTYPE, "RUS");
    int k, f, t;

    printf("Введите три целых числа k,f,t: ");
    scanf_s("%d %d %d", &k, &f, &t);

    printf("Пары кратных чисел: ");

    if (k % f == 0 || f % k == 0) {
        printf("(%d, %d)", k, f);
    }

    if (k % t == 0 || t % k == 0) {
        printf("(%d, %d)\n", k, t);
    }

    if (f % t == 0 || t % f == 0) {
        printf("(%d, %d)\n", f, t); 
    }
    if ((k % f != 0 && f % k != 0) && (k % t != 0 && t % k != 0) && (f % t != 0 && t % f != 0)) {
    
        printf("Таких нет.\n");

    }

    return 0;
}
