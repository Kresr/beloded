#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
     setlocale(LC_CTYPE, "Russian");
     char c, probel; probel = ' ';
     cout << "Введите символ "; cin >> c;
     cout << setw(20) << setfill(probel) << probel;
     cout << setw(1) << setfill(c) << c;
     cout << setw(20) << setfill(probel) ;
     cout << setw(1) << setfill(c) << c << endl;
     cout << setw(19) << setfill(probel) << probel;
     cout << setw(2) << setfill(c) << c ;
     cout << setw(19) << setfill(probel);
     cout << setw(2) << setfill(c) << c << endl;
     cout << setw(18) << setfill(probel) << probel;
     cout << setw(3) << setfill(c) << c ;
     cout << setw(18) << setfill(probel);
     cout << setw(3) << setfill(c) << c << endl;
     cout << setw(12) << setfill(probel) << probel;
     cout << setw(18) << setfill(c) << c << endl;
     cout << setw(13) << setfill(probel) << probel;
     cout << setw(16) << setfill(c) << c << endl;
     cout << setw(14) << setfill(probel) << probel;
     cout << setw(14) << setfill(c) << c << endl;
     cout << setw(15) << setfill(probel) << probel;
     cout << setw(12) << setfill(c) << c << endl;
     cout << setw(14) << setfill(probel) << probel;
     cout << setw(14) << setfill(c) << c << endl;
     cout << setw(13) << setfill(probel) << probel;
     cout << setw(16) << setfill(c) << c << endl;

     cout << setw(12) << setfill(probel) << probel;
     cout << setw(4) << setfill(c) << c;
     cout << setw(10) << setfill(probel) << probel;
     cout << setw(4) << setfill(c) << c << endl;

     cout << setw(11) << setfill(probel) << probel;
     cout << setw(3) << setfill(c) << c;
     cout << setw(14) << setfill(probel) << probel;
     cout << setw(3) << setfill(c) << c << endl;
  

     cout << setw(10) << setfill(probel) << probel;
     cout << setw(2) << setfill(c) << c;
     cout << setw(18) << setfill(probel) << probel;
     cout << setw(2) << setfill(c) << c << endl;
     



     
    return 0;
}




