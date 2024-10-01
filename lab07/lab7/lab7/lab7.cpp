#include <iostream>
int main()
{

    setlocale(LC_ALL, "Rus");
    float n = 5, i, x, a = 0, b = 1;
    

    for (i = 1; i <=n; i++)
    {
        printf("Введите x: ");
        scanf_s("%f", &x);
        if  (x > 0) {
            a += x;
            printf("a= %f\n ", a);
        }
        else
        {
            b *= x ;
            printf("b= %f\n ", b);

            
        }
    }

    

    return 0;
}
