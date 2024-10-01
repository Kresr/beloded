#include <iostream> 
#include <iomanip>


int main()
{
    setlocale(LC_CTYPE, "Russian");

    float v, w, b, m, u = 0.005e-4, k, i;


    for (k = 0; k < 3; k++) {
        printf("Enter m:");
        scanf_s("%f", &m);
        b = 7;
        while (b < 8) {

            v = u + b - 2 * sqrt(0.7 * k + m);
            w = 100 * exp(-0.2 * u) - log(8.1 * u);
            b += 0.2001;

            printf("v = %5.3f\t", v);
            printf("w = %5.3f\n", w);
        }

    }

    return 0;
}