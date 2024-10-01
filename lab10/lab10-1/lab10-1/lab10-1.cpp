#include <iostream>
#include <cstring>

int main() {
    using namespace std;
    setlocale(LC_ALL, "rus");
    int num;
    char tmp[33];
    cout << "Введите целое число: ";
    cin >> num;
  
    _itoa_s(num, tmp, 2);
    cout << "Число A в двоичной системе до установки каждого второго бита в 1: \n" << tmp << endl;
    for (int i = 0; i < 33; i++) {
        if (i % 2 == 1) {
            tmp[i] = tmp[i] & '0';
        }
        else {
            if (tmp[i] != '0' && tmp[i] != '1') {
                break;
            }
        }
    }
    cout << "Число A в двоичной системе после установки каждого второго бита в 1: \n" << tmp << endl;
    return 0;
}



