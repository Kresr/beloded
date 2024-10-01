#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include "tetris.h"

int main()
{
    using namespace std;
    setlocale(LC_ALL, "rus");
    srand(time(0));
    int accidentally;
    char a = ' ';

    Constractor tetris;
    for (;;)
    {
        accidentally = rand();

        if (accidentally > 0 && accidentally < 100)
            accidentally = 1;
        else if (accidentally > 100 && accidentally < 200)
            accidentally = 2;
        else if (accidentally > 200 && accidentally < 300)
            accidentally = 3;
        else if (accidentally > 300 && accidentally < 400)
            accidentally = 4;
        else if (accidentally > 400 && accidentally < 500)
            accidentally = 5;
        else if (accidentally > 500 && accidentally < 600)
            accidentally = 6;
        else if (accidentally > 600 && accidentally < 700)
            accidentally = 7;

        switch (accidentally)
        {
        case 1:
            tetris.Show_kub();
            break;
        case 2:
            tetris.Show_zig_a();
            break;
        case 3:
            tetris.Show_zig_b();
            break;
        case 4:
            tetris.Show_pulka();
            break;
        case 5:
            tetris.Show_ugoll();
            break;
        case 6:
            tetris.Show_ugolp();
            break;
        case 7:
            tetris.Show_polkrest();
            break;
        }
    }

    cout << "\n\n";
    system("pause");
    return 0;
}