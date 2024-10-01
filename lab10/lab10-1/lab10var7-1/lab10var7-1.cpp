#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_CTYPE, "Russian");

    char tmp[33];
    int A, B;

    cout << "Первое число= ";
    cin >> A;
    _itoa_s(A, tmp, 2); 
    cout << "A= " << tmp << endl;
    cout << "Второе число= ";
    cin >> B;
    _itoa_s(B, tmp, 2); 
    cout << "B= " << tmp << endl;

    
    int maskA = ((1 << 5) - 1) << 5;
    int extractedBitsA = (A & maskA) >> 5;

    
    B = (B << 4) | extractedBitsA;

    _itoa_s(B, tmp, 2);
    cout << "Число B после добавления битов справа= " << tmp << endl;

    return 0;
}
