#include <stdio.h>
#include <math.h> 
#include <iomanip> 

int main() 
{
    setlocale(LC_CTYPE, "Russian");
    float x1, y1, x2, y2, distance;

    printf("Введите координаты точки M1 (x1 y1): ");
    scanf_s("%f %f", &x1, &y1);

    printf("Введите координаты точки M2 (x2 y2): ");
    scanf_s("%f %f", &x2, &y2);

    
     distance = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

    printf("Расстояние между точками M1 и M2: %f\n", distance);

    return 0;

}