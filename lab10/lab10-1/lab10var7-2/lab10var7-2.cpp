#include <iostream>
using namespace std;

int main() {
    setlocale(LC_CTYPE, "Russian");

    char tmp[33];
    int A, B, n, p, m, q;

    cout << "Первое число (A)=";
    cin >> A;
    _itoa_s(A, tmp, 2);
    cout << "A= " << tmp << endl;

    cout << "Второе число (B)=";
    cin >> B;
    _itoa_s(B, tmp, 2);
    cout << "B= " << tmp << endl;

    cout << "Введите количество бит для установки (n):";
    cin >> n;

    cout << "Введите позицию для установки битов в числе A (p):";
    cin >> p;

    cout << "Введите количество бит для замены (m):";
    cin >> m;

    cout << "Введите позицию для начала замены битов в числе B (q):";
    cin >> q;

    // Сохранение оригинальных битов из A, начиная с позиции p
    int originalBitsA = (A >> p) & ((1 << m) - 1);

    // Установка n битов в A начиная с позиции p
    int maskSet = ((1 << n) - 1) << p;
    A |= maskSet;
    _itoa_s(A, tmp, 2);
    cout << "A=" << tmp << endl;

    // Замена m битов в B начиная с позиции q оригинальными битами из A
    int maskReplace = ((1 << m) - 1) << q;
    B = (B & ~maskReplace) | (originalBitsA << q);

    _itoa_s(B, tmp, 2);
    cout << "B=" << tmp << endl;

    return 0;
}
