#include <stdio.h>
#include <stdlib.h> 
#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_CTYPE, "Russian");

    int size, ** K, ** L, ** M;
    FILE* A, * B, * C;
    cout << "Введите размер матрицы: ";
    cin >> size;

    K = new int* [size];
    for (int i = 0; i < size; i++)
    {
        K[i] = new int[size];
        for (int j = 0; j < size; j++)
        {
            K[i][j] = 1 + rand() % 10;
        }
    }

    L = new int* [size];
    for (int i = 0; i < size; i++)
    {
        L[i] = new int[size];
        for (int j = 0; j < size; j++)
        {
            L[i][j] = 1 + rand() % 10;
        }
    }

    errno_t err1, err2;
    err1 = fopen_s(&A, "A.txt", "w");
    if (err1 != 0)
    {
        perror("Ошибка открытия a.txt");
        return EXIT_FAILURE;
    }

    err2 = fopen_s(&B, "B.txt", "w");
    if (err2 != 0)
    {
        perror("Ошибка открытия b.txt");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i == 0 && j == 0)
            {
                fprintf(A, "%d ", size);
                fprintf(B, "%d ", size);
                fprintf(A, "\n");
                fprintf(B, "\n");
            }
            fprintf(A, "%d ", K[i][j]);
            fprintf(B, "%d ", L[i][j]);
        }
        fprintf(A, "\n");
        fprintf(B, "\n");
    }
    fclose(A);
    fclose(B);

    M = new int* [size];
    for (int i = 0; i < size; i++)
    {
        M[i] = new int[size];
        for (int j = 0; j < size; j++)
        {
            M[i][j] = 0;
            for (int k = 0; k < size; k++)
            {
                M[i][j] += K[i][k] * L[k][j];
            }
        }
    }

    fopen_s(&C, "C.txt", "w");

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i == 0 && j == 0)
            {
                fprintf(C, "%d ", size);
                fprintf(C, "\n");
            }
            fprintf(C, "%d ", M[i][j]);
        }
        fprintf(C, "\n");
    }
    fclose(C);

    for (int i = 0; i < size; i++)
        delete[] K[i];
    delete[] K;

    for (int i = 0; i < size; i++)
        delete[] L[i];
    delete[] L;
    return 0;
}
