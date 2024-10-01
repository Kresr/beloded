#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

int findClosestNumber(FILE* file, int target) {
    float currentNumber;
    float closestNumber = 0.0f; 
    int closestIndex = 0;
    float minDifference = INFINITY;

    rewind(file);

    int currentIndex = 0;

    while (fscanf_s(file, "%f", &currentNumber) == 1) {
        float difference = fabs(currentNumber - target);

        if (difference < minDifference) {
            minDifference = difference;
            closestNumber = currentNumber;
            closestIndex = currentIndex;
        }

        currentIndex++;
    }

    printf("Наиболее близкое число: %.2f\n", closestNumber);
    return closestIndex;
}

int main() {
    int target;
    char filename[100] = "a.txt";
    errno_t err;

    setlocale(LC_ALL, "Russian"); 

   
    strcat_s(filename, ".txt");

    FILE* file;

    
    err = fopen_s(&file, filename, "w");
    if (err != 0) {
        printf("Не удалось создать файл.\n");
        return EXIT_FAILURE;
    }

    
    for (int i = 0; i < 10; i++) {
        float randomValue = ((float)rand() / RAND_MAX) * 200.0 - 100.0; 
        fprintf(file, "%.2f ", randomValue);
    }

    
    fclose(file);

    
    err = fopen_s(&file, filename, "r");
    if (err != 0) {
        printf("Не удалось открыть файл.\n");
        return EXIT_FAILURE;
    }

    printf("Введите целое число: ");
    scanf_s("%d", &target);

    int closestIndex = findClosestNumber(file, target);

    printf("Порядковый номер числа, наиболее близкого к введенному: %d\n", closestIndex + 1);

    
    fclose(file);

    return 0;
}








