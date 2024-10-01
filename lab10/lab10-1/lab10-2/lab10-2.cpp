#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_CTYPE, "Russian");
    char tmp[33];
    int A, B, n, m;
    cout << "Первое число=";
    cin >> A;
    _itoa_s(A, tmp, 2); 
    cout << "A=" << tmp << endl;
    cout << "Второе число=";
    cin >> B;
    _itoa_s(B, tmp, 2);
    cout << "B=" << tmp << endl;
    cout << "Введите позицию n для числа A:";
    cin >> n;
    cout << "Введите позицию m для числа B:";
    cin >> m;
    int maskA = ((1 << 3) - 1) << n;
    int extractedBitsA = (A & maskA) >> n;
    int maskB = ~(((1 << 3) - 1) << m);
    B &= maskB;
    B |= (extractedBitsA << m);
    _itoa_s(B, tmp, 2);
    cout << "B=" << tmp << endl;

    return 0;
}