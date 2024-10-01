#include <stdio.h>
#include <stdlib.h>
#include <iostream>
int main() {
    setlocale(LC_ALL, "");
    FILE* f1, * f2;
    char line[100];
    int lineNumber = 0;
    int numLines;


    do {
        printf("Введите количество строк (не менее 6): ");
        scanf_s("%d", &numLines);
    } while (numLines < 6);

    fopen_s(&f1, "F1.txt", "w");
    if (f1 == NULL) {
        printf("Не удалось открыть файл F1.txt для записи\n");
        return EXIT_FAILURE;
    }

    printf("Введите строки для записи в файл F1:\n");
    for (int i = 1; i <= numLines; i++) {
        printf("Строка %d: ", i);
        scanf_s("%s", line, sizeof(line));
        fprintf(f1, "%s\n", line);
    }

    
    fclose(f1);
    fopen_s(&f1, "F1.txt", "r");
    if (f1 == NULL) {
        printf("Не удалось открыть файл F1.txt для чтения\n");
        return EXIT_FAILURE;
    }

    fopen_s(&f2, "F2.txt", "w");
    if (f2 == NULL) {
        printf("Не удалось открыть файл F2.txt для записи\n");
        return EXIT_FAILURE;
    }

    
    while (fgets(line, sizeof(line), f1) != NULL) {
        lineNumber++;
        if (lineNumber % 2 == 0) {
            fprintf(f2, "%s", line);
        }
    }

    fclose(f1);
    fclose(f2);

    printf("Программа успешно выполнена.\n");

    return 0;
}



