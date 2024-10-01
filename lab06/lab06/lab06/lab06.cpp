#include <iostream>
#include <cmath>

int main()
{
    setlocale(LC_CTYPE, "ru");
    float t, d, f, a = -4.2, i = 4,j;

    for ( j = 0; j < 5; j++)
    {
        printf("Введите t: ");
        scanf_s("%f", &t);

        d = i + 2 * t * (1 + sqrt(3 * pow(a, 2)));
        if (d >= t * (t + i)) {
            f = t * i;
        }
        else
        {
            f = exp(t - d) + 9;
        }
        printf("f= %.2f\n", f);
    }

    return 0;
}