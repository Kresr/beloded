#include <iostream>

int main() {
    setlocale(LC_ALL, "RUS");

    const int maxLength = 100;
    char S[maxLength];
    char S1[maxLength];

    std::cout << "������� ������ S: ";
    char c;
    int i = 0;
    while ((c = getchar()) != '\n' && i < maxLength - 1) {
        S[i++] = c;
    }
    S[i] = '\0'; // ��������� ��������� ������� ������

    std::cout << "������� ��������� S1: ";
    i = 0;
    while ((c = getchar()) != '\n' && i < maxLength - 1) {
        S1[i++] = c;
    }
    S1[i] = '\0'; // ��������� ��������� ������� ������

    int n, k;
    std::cout << "������� ������� n ��� ������� � ����� ��������� k: ";
    std::cin >> n >> k;

    // ������� ��������� S1 � ������ S
    int lenS = 0;
    while (S[lenS] != '\0') {
        ++lenS;
    }

    int lenS1 = 0;
    while (S1[lenS1] != '\0' && lenS1 < k) {
        ++lenS1;
    }

    if (n < 0 || n > lenS) {
        std::cout << "������: ������������ ������� ��� �������." << std::endl;
        return 1;
    }

    if (lenS + lenS1 > maxLength - 1) {
        std::cout << "������: ��������� ����� ������." << std::endl;
        return 1;
    }

    // �������� ����� ������ S ����� ������� n �� lenS1 ������� ������
    for (int i = lenS + lenS1; i >= n + lenS1; --i) {
        S[i] = S[i - lenS1];
    }

    // �������� ��������� S1 � ������ S
    for (int i = 0; i < lenS1; ++i) {
        S[n + i] = S1[i];
    }

    // ����� ����������
    std::cout << "���������: ";
    for (int i = 0; i < lenS + lenS1; ++i) {
        std::cout << S[i];
    }
    std::cout << std::endl;

    return 0;
}


