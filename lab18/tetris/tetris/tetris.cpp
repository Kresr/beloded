﻿#include <ctime>
#include <conio.h>
#include "tetris.h"
#include <cstdlib>

using namespace std;

Constractor::Constractor() : ur("Уровень = "), och("Очки    = "), ur_int(1), och_int(0), skorost(0.9), level_1(1)
{
    ver = 20;
    gor = 17;

    // osnova
    osnova = new char* [ver];
    for (int i = 0; i < ver; i++) osnova[i] = new char[gor + 1];
    //pause
    pause = new char* [ver];
    for (int i = 0; i < ver; i++) pause[i] = new char[gor + 1];
    // game_over
    game_over = new char* [ver];
    for (int i = 0; i < ver; i++) game_over[i] = new char[gor + 1];
    // uroven
    uroven = new char* [ver];
    for (int i = 0; i < ver; i++) uroven[i] = new char[gor + 1];

    // установка массива osnova
    for (int i = 0; i < ver; i++)
        for (int j = 0; j < gor - 1; j++)
        {
            osnova[i][j] = 2;

            if ((i != 0 && i != ver - 1) && (j > 0 && j < gor - 2))
                osnova[i][j] = ' ';
        }

    if (gor % 2)
        for (int i = 0; i < ver; i++)
            osnova[i][gor - 2] = 2;

    for (int i = 0; i < ver; i++)
        osnova[i][gor - 1] = '\0';

    // установка массива pause и game_over
    for (int i = 0; i < ver; i++)
        for (int j = 0; j < gor; j++)
        {
            pause[i][j] = osnova[i][j];
            game_over[i][j] = osnova[i][j];
            uroven[i][j] = osnova[i][j];
        }

    const char* zn[3] = { "ПАУЗА", "GAME OVER", "УРОВЕНЬ" };
    int sr_ver = ver / 2;
    int sr_gor = gor / 2;
    int n = 0;

    for (int i = sr_ver; i < sr_ver + 1; i++)
        for (int j = sr_gor - 3; j < sr_gor + 2; j++, n++)
        {
            pause[i][j] = zn[0][n];
        }

    n = 0;
    for (int i = sr_ver; i < sr_ver + 1; i++)
        for (int j = sr_gor - 5; j < sr_gor + 4; j++, n++)
        {
            game_over[i][j] = zn[1][n];
        }

    n = 0;
    int n_2 = 0;

    for (int i = sr_ver; i < sr_ver + 1; i++)
        for (int j = sr_gor - 4; j < sr_gor + 3; j++, n++)
        {
            uroven[i][j] = zn[2][n];
            n_2 = i;
        }

    uroven[n_2][n + 5] = ur_int + 48;

}

Constractor::~Constractor()
{
    for (int i = 0; i < ver; i++) delete[] osnova[i];
    delete[] osnova;

    for (int i = 0; i < ver; i++) delete[] pause[i];
    delete[] pause;

    for (int i = 0; i < ver; i++) delete[] game_over[i];
    delete[] game_over;

    for (int i = 0; i < ver; i++) delete[] uroven[i];
    delete[] uroven;

}

void Constractor::Vosnova()
{
    cout << endl << endl << endl << endl;
    for (int m = 0; m < ver; m++)
        std::cout << "\n\t\t\t\t    " << osnova[m];

    // уровен и очки
    cout << endl << "\t\t\t\t    " << ur << ur_int << endl << "\t\t\t\t    " << och << och_int;
}
void Constractor::Vpause()
{
    cout << endl << endl << endl << endl;
    for (int i = 0; i < ver; i++)
        std::cout << "\n\t\t\t\t    " << pause[i];
}
void Constractor::Vgame_over()
{
    cout << endl << endl << endl << endl;
    for (int i = 0; i < ver; i++)
        std::cout << "\n\t\t\t\t    " << game_over[i];
}
void Constractor::Vuroven(int n)///////////////////////////////
{
    if (n != 15)
        uroven[10][12] = n + 48;

    cout << endl << endl << endl << endl;
    for (int i = 0; i < ver; i++)
        std::cout << "\n\t\t\t\t    " << uroven[i];
}

// Методы
char Constractor::Pause(char paus)
{
    for (; paus == '0';)
    {
        Vpause();

        cout << "\n";
        paus = _getch();

        if (paus == '0')
        {
            system("cls");
            paus = ' ';
            break;
        }
        else
        {
            system("cls");
            continue;
        }
    }

    return paus;
}

void Constractor::Delay(double n)
{
    // задержка цикла
    float secs = n;
    clock_t delay = secs * CLOCKS_PER_SEC;
    clock_t start = clock();
    while (clock() - start < delay);
}


int Constractor::Yes()
{
    int one = 0;
    int two = 0;

    for (int i = 1; i < ver - 1; i++)
    {
        for (int j = 1; j < gor - 2; j++)
        {
            if (osnova[i][j] == 2)
                one++;
        }
        if (one == gor - 3)
        {
            two++;
            for (int n = 1; n < gor - 2; n++)
            {
                osnova[i][n] = ' ';

                Vosnova();

                Delay(0.03);
                system("CLS");
            }

            for (int n = i - 1; n > 0; n--)
                for (int m = 1; m < gor - 2; m++)
                    if (osnova[n][m] == 2)
                    {
                        osnova[n][m] = ' ';
                        osnova[n + 1][m] = 2;
                    }

            Vosnova();

            Delay(0.03);
            system("CLS");
        }
        one = 0;
    }


    return two * two;
}

int Constractor::Lavel(int n)
{
    int max = 0;
    int temp = 0;
    int accidentally;
    srand(time(0));

    if (ur_int == 1)
        max = 50;
    else if (ur_int == 2)
        max = 100;
    else if (ur_int == 3)
        max = 150;
    else if (ur_int == 4)
        max = 200;
    else if (ur_int == 5)
        max = 250;
    else if (ur_int == 6)
        max = 300;
    else if (ur_int == 7)
        max = 350;
    else if (ur_int == 8)
        max = 400;

    if (n > max)
    {
        ur_int++;

        ////////////////////////////////

        if (ur_int > 8)
        {
            Victory(); return 0;
        }


        /////////////////////////////
        skorost -= 0.1;
        temp = ver - 2 - ((ur_int - 1) * 2);

        if (temp < 5)
            temp = 5;

        for (int i = 0; i < ver; i++)
            for (int j = 0; j < gor; j++)
                if (uroven[i][j] == 'Ь')
                    uroven[i][j + 2] = (ur_int)+48;

        Vuroven();

        // Установка уровня
        for (int i = 1; i < ver - 1; i++)
            for (int j = 1; j < gor - 2; j++)
                osnova[i][j] = ' ';


        for (int i = ver - 2; i > temp; i--)
            for (int j = 1; j < gor - 2; j++)
            {
                if (rand() % 2)
                {
                    osnova[i][j] = 2;
                }
                else
                {
                    osnova[i][j] = ' ';
                }
            }

        cout << "\n";
        system("pause");
        system("cls");

    }
    return 0;
}

void Constractor::Game_over()
{

    ///////// Проверка на Game over
    bool BL = true;

    for (int i = 1; i < gor - 3; i++)
        if (osnova[1][i] == 2)
            BL = false;

    if (!BL)
    {
        // Эффект заполнения
        for (int i = ver - 2; i > 0; i--)
        {
            for (int j = gor - 3; j > 0; j--)
            {
                osnova[i][j] = 2;
            }

            Vosnova();

            Delay(0.2);
            system("cls");
        }

        Vgame_over();

        /// Установки в первоначальное значение данных
        for (int i = 1; i < ver - 1; i++)
        {
            for (int j = 1; j < gor - 2; j++)
            {
                osnova[i][j] = ' ';
            }
        }

        level_1 = 1;
        ur_int = 1;
        och_int = 0;
        skorost = 0.9;

        cout << "\n\n";
        system("pause");
        system("cls");
    }

    ///////// Проверка на первый уровень
    bool BL_1 = true;

    for (int i = ver - 2; i > 0; i--)
    {
        for (int j = gor - 3; j > 0; j--)
        {
            if (osnova[i][j] == 2)
                BL_1 = false;
        }
    }

    if (BL_1 && level_1 == 1)
    {
        Vuroven(ur_int);

        cout << "\n\n";
        system("pause");
        system("cls");
    }

}

void Constractor::Victory()
{
    char** temp;

    temp = new char* [ver + 8];
    for (int i = 0; i < ver + 8; i++) temp[i] = new char[gor + 9];

    for (int i = 0; i < ver + 8; i++)
        for (int j = 0; j < gor + 8; j++)
            temp[i][j] = ' ';

    for (int i = 4; i < ver + 4; i++)
        for (int j = 4; j < gor + 4; j++)
        {
            temp[i][j] = 2;

            if ((i != 4 && i != ver + 3) && (j > 4 && j < gor + 5))
                temp[i][j] = ' ';
        }

    for (int i = 4; i < ver + 4; i++)
        temp[i][gor + 3] = 2;

    // эффект заполнения
    for (int i = ver + 2; i > 4; i--)
    {
        for (int j = 5; j < gor + 3; j++)
        {
            temp[i][j] = 1;

        }
        for (int i = 0; i < ver + 8; i++) {
            cout << "\t\t\t\t";
            for (int j = 0; j < gor + 8; j++)
                cout << temp[i][j];
            cout << endl;
        }
        Delay(0.2);
        system("cls");

    }

    // эффект сжатия

    int nnn = 1;
    int nn;
    int n;

    int mmm = 1;
    int mm;
    int m;

    int sss = 1;
    int ss;
    int s;

    int ccc = 1;
    int cc;
    int c;


    for (int i = ver + 2; i > 8; i--)
    {
        nn = 5;
        n = i;
        for (int k = 0; k < nnn; k++, nn++, n++)
        {
            temp[n][nn] = ' ';

        }

        mm = 5;
        m = ver + 7 - i;
        for (int k = 0; k < mmm; k++, mm++, m--)
        {
            temp[m][mm] = ' ';

        }

        ss = 19;
        s = i;
        for (int k = 0; k < nnn; k++, ss--, s++)
        {
            temp[s][ss] = ' ';

        }

        cc = 19;
        c = ver + 7 - i;
        for (int k = 0; k < mmm; k++, cc--, c--)
        {
            temp[c][cc] = ' ';

        }




        /////////////////////////////////////////
        for (int i = 0; i < ver + 8; i++) {
            cout << "\t\t\t\t";
            for (int j = 0; j < gor + 8; j++)
                cout << temp[i][j];
            cout << endl;
        }

        /////////////////////////////////////////
        nnn++;
        mmm++;
        sss++;
        ccc++;


        if (i == 9)
            Delay(0.4);
        else
            Delay(0.2);

        system("cls");
    }

    // Мигаем
    for (int a = 1; a < 5; a++)
    {
        if (a % 2)
        {
            for (int i = 12; i < ver - 4; i++) {
                for (int j = 11; j < gor - 3; j++)
                    if (temp[i][j] == 1)
                        temp[i][j] = 2;
            }
        }
        else
        {
            for (int i = 12; i < ver - 4; i++) {
                for (int j = 11; j < gor - 3; j++)
                    if (temp[i][j] == 2)
                        temp[i][j] = 1;
            }
        }

        /////////////////////////////////////////
        for (int i = 0; i < ver + 8; i++) {
            cout << "\t\t\t\t";
            for (int j = 0; j < gor + 8; j++)
                cout << temp[i][j];
            cout << endl;
        }

        Delay(0.4);

        system("cls");

        /////////////////////////////////////////
    }

    // Взрыв!!!!
    // заполнениe
    for (int i = ver + 2; i > 4; i--)
    {
        for (int j = 5; j < gor + 3; j++)
        {
            temp[i][j] = 1;

        }
    }
    // Рисую
    temp[3][4] = 1;
    temp[4][3] = 1;
    temp[3][3] = 1;
    temp[2][2] = 1;
    temp[3][7] = 1;
    temp[3][8] = 1;
    temp[3][9] = 1;
    temp[3][10] = 1;
    temp[2][8] = 1;
    temp[2][9] = 1;
    temp[1][8] = 1;
    temp[3][14] = 1;
    temp[3][15] = 1;
    temp[3][16] = 1;
    temp[3][17] = 1;
    temp[2][18] = 1;
    temp[2][19] = 1;
    temp[2][17] = 1;
    temp[2][16] = 1;
    temp[1][20] = 1;
    temp[1][19] = 1;
    temp[1][18] = 1;
    temp[0][22] = 1;
    temp[0][21] = 1;
    temp[1][21] = 1;
    temp[1][22] = 1;
    temp[2][21] = 1;
    temp[2][22] = 1;
    temp[2][20] = 1;
    temp[3][20] = 1;
    temp[3][21] = 1;
    temp[3][19] = 1;
    temp[3][18] = 1;
    temp[4][21] = 1;
    temp[0][23] = 1;
    temp[8][21] = 1;
    temp[9][21] = 1;
    temp[10][21] = 1;
    temp[8][22] = 1;
    temp[9][22] = 1;
    temp[7][23] = 1;
    temp[8][23] = 1;
    temp[7][24] = 1;
    temp[14][21] = 1;
    temp[15][21] = 1;
    temp[16][21] = 1;
    temp[16][22] = 1;
    temp[15][22] = 1;
    temp[16][23] = 1;
    temp[15][23] = 1;
    temp[16][24] = 1;
    temp[24][21] = 1;
    temp[25][22] = 1;
    temp[26][23] = 1;
    temp[27][24] = 1;
    temp[23][21] = 1;
    temp[22][21] = 1;
    temp[24][20] = 1;
    temp[24][19] = 1;
    temp[23][22] = 1;
    temp[24][22] = 1;
    temp[25][23] = 1;
    temp[25][21] = 1;
    temp[24][13] = 1;
    temp[24][12] = 1;
    temp[24][11] = 1;
    temp[24][10] = 1;
    temp[25][12] = 1;
    temp[25][11] = 1;
    temp[26][11] = 1;
    temp[24][2] = 1;
    temp[24][3] = 1;
    temp[24][4] = 1;
    temp[24][5] = 1;
    temp[23][3] = 1;
    temp[25][1] = 1;
    temp[25][2] = 1;
    temp[25][3] = 1;
    temp[26][0] = 1;
    temp[26][1] = 1;
    temp[17][3] = 1;
    temp[18][3] = 1;
    temp[19][3] = 1;
    temp[18][2] = 1;
    temp[19][2] = 1;
    temp[19][1] = 1;
    temp[12][3] = 1;
    temp[11][3] = 1;
    temp[10][3] = 1;
    temp[9][3] = 1;
    temp[8][3] = 1;
    temp[11][2] = 1;
    temp[10][2] = 1;
    temp[9][2] = 1;
    temp[8][2] = 1;
    temp[9][1] = 1;
    temp[8][1] = 1;
    temp[8][0] = 1;
    temp[7][0] = 1;
    temp[5][12] = ' ';
    temp[6][5] = ' ';
    temp[7][5] = ' ';
    temp[7][6] = ' ';
    temp[14][5] = ' ';
    temp[15][5] = ' ';
    temp[14][6] = ' ';
    temp[20][5] = ' ';
    temp[21][5] = ' ';
    temp[20][6] = ' ';
    temp[22][8] = ' ';
    temp[22][16] = ' ';
    temp[22][17] = ' ';
    temp[21][16] = ' ';
    temp[18][19] = ' ';
    temp[17][19] = ' ';
    temp[17][18] = ' ';
    temp[12][19] = ' ';
    temp[7][19] = ' ';
    temp[7][18] = ' ';
    temp[6][19] = ' ';

    temp[13][8] = 'П';
    temp[13][9] = 'О';
    temp[13][10] = 'Б';
    temp[13][11] = 'Е';
    temp[13][12] = 'Д';
    temp[13][13] = 'А';
    temp[13][14] = '!';
    temp[13][15] = '!';
    temp[13][16] = '!';

    /////////////////////////////////////////
    for (int i = 0; i < ver + 8; i++) {
        cout << "\t\t\t\t";
        for (int j = 0; j < gor + 8; j++)
            cout << temp[i][j];
        cout << endl;
    }

    /// Установки в первоначальное значение данных
    for (int i = 1; i < ver - 1; i++)
    {
        for (int j = 1; j < gor - 2; j++)
        {
            osnova[i][j] = ' ';
        }
    }

    level_1 = 1;
    ur_int = 1;
    och_int = 0;
    skorost = 0.9;

    cout << "\n\n";
    system("pause");
    system("cls");

    for (int i = 0; i < ver; i++) delete[] temp[i];
    delete[] temp;
}
// Куб
void Constractor::Show_kub()
{
    // Общее обьявления //
    char a = ' ';           // основа управления
    char b = ' ';           // для ускорения падения
    int schet_1 = 1;        // значение массива 1
    int schet_2 = gor / 2;    // значение массива 2

    char* speed;            // для быстрого перемещения в бока
    speed = new char[gor];
    //...................//

    // Проверка на конец
    Game_over();
    // Переменная для проверки уровня
    level_1++;

    // Начало цикла падения //
    for (int osn = 0; ; osn++)
    {
        // Управление
        for (int i = 0; i < gor; i++)
            if (_kbhit())
                speed[i] = _getch();

        a = speed[0];

        if (b != '2')
            b = speed[0];

        if (osn > 0)
        {
            schet_1--;
            osnova[schet_1][schet_2] = ' ';
            osnova[schet_1][schet_2 + 1] = ' ';
            osnova[schet_1 + 1][schet_2] = ' ';
            osnova[schet_1 + 1][schet_2 + 1] = ' ';
            schet_1++;
        }

        // в право
        for (int i = 0; (speed[i] == '6') && (i < gor); i++)
        {
            if (osnova[schet_1 + 1][schet_2 + 2] == 2 || osnova[schet_1][schet_2 + 2] == 2)
                break;
            schet_2++;
            a = ' ';
            b = ' ';
        }

        // в лево
        for (int i = 0; (speed[i] == '4') && (i < gor); i++)
        {
            if (osnova[schet_1 + 1][schet_2 - 1] == 2 || osnova[schet_1][schet_2 - 1] == 2)
                break;
            schet_2--;
            a = ' ';
            b = ' ';
        }

        osnova[schet_1][schet_2] = 2;
        osnova[schet_1][schet_2 + 1] = 2;
        osnova[schet_1 + 1][schet_2] = 2;
        osnova[schet_1 + 1][schet_2 + 1] = 2;

        if (osnova[schet_1 + 2][schet_2] == 2 || osnova[schet_1 + 2][schet_2 + 1] == 2)break;

        schet_1++;

        // пауза
        if (a == '0')
            a = Pause(a);

        // Вывод массива
        Vosnova();

        // в низ
        // задержка
        if (b == '2')
            Delay(0.03);
        else
            Delay(skorost);

        // чистка //
        for (int i = 0; i < gor / 2; i++)
            speed[i] = ' ';

        a = ' ';

        system("CLS");
    }
    //....................//

    // Проверка на полную строку //
    och_int += Yes();
    //....................//

    // Проверка очков на прохождение уровня //
    Lavel(och_int);
    //....................//

    delete[] speed;
}
// Зигзаг а
void Constractor::Show_zig_a(int mesto_1, int mesto_2)
{
    // Общее обьявления //
    char a = ' ';           // основа управления
    char b = ' ';           // для ускорения падения
    int schet_1 = mesto_1;      // значение массива 1
    int schet_2 = mesto_2;  // значение массива 2

    char* speed;            // для быстрого перемещения в бока
    speed = new char[gor];
    //...................//

    // Проверка на конец
    Game_over();
    // Переменная для проверки уровня
    level_1++;

    // Начало цикла падения //
    for (int osn = 0; ; osn++)
    {
        // Управление
        for (int i = 0; i < gor; i++)
            if (_kbhit())
                speed[i] = _getch();

        a = speed[0];

        if (b != '2')
            b = speed[0];

        if (osn > 0)
        {
            schet_1--;
            osnova[schet_1][schet_2] = ' ';
            osnova[schet_1 + 1][schet_2] = ' ';
            osnova[schet_1 + 1][schet_2 + 1] = ' ';
            osnova[schet_1 + 2][schet_2 + 1] = ' ';
            schet_1++;
        }

        //// поворот ////
        if (a == '5'
            && osnova[schet_1][schet_2] == ' '
            && osnova[schet_1][schet_2 + 1] == ' '
            && osnova[schet_1 + 1][schet_2] == ' '
            && osnova[schet_1 + 1][schet_2 - 1] == ' '
            )
        {
            Show_zig_a_2(schet_1, schet_2);
            break;
        }
        /////////////////

        // в право
        for (int i = 0; (speed[i] == '6') && (i < gor); i++)
        {
            if (osnova[schet_1][schet_2 + 1] == 2 || osnova[schet_1 + 1][schet_2 + 2] == 2 || osnova[schet_1 + 2][schet_2 + 2] == 2)
                break;
            schet_2++;
            a = ' ';
            b = ' ';
        }

        // в лево
        for (int i = 0; (speed[i] == '4') && (i < gor); i++)
        {
            if (osnova[schet_1][schet_2 - 1] == 2 || osnova[schet_1 + 1][schet_2 - 1] == 2)
                break;
            schet_2--;
            a = ' ';
            b = ' ';
        }
        /////////////////////////////////
        osnova[schet_1][schet_2] = 2;
        osnova[schet_1 + 1][schet_2] = 2;
        osnova[schet_1 + 1][schet_2 + 1] = 2;
        osnova[schet_1 + 2][schet_2 + 1] = 2;

        if (osnova[schet_1 + 2][schet_2] == 2 || osnova[schet_1 + 3][schet_2 + 1] == 2)break;

        schet_1++;

        // пауза
        if (a == '0')
            a = Pause(a);

        // Вывод массива
        Vosnova();

        // в низ
        // задержка
        if (b == '2')
            Delay(0.03);
        else
            Delay(skorost);

        // чистка //
        for (int i = 0; i < gor / 2; i++)
            speed[i] = ' ';

        a = ' ';

        system("CLS");
    }
    //....................//

    // Проверка на полную строку //
    och_int += Yes();
    //....................//

    // Проверка очков на прохождение уровня //
    Lavel(och_int);
    //....................//

    delete[] speed;
}

void Constractor::Show_zig_a_2(int mesto_1, int mesto_2)
{
    // Общее обьявления //
    char a = ' ';           // основа управления
    char b = ' ';           // для ускорения падения
    int schet_1 = mesto_1;      // значение массива 1
    int schet_2 = mesto_2;  // значение массива 2

    char* speed;            // для быстрого перемещения в бока
    speed = new char[gor];
    //...................//

    // Проверка на конец
    Game_over();
    // Переменная для проверки уровня
    level_1++;

    // Начало цикла падения //
    for (int osn = 0; ; osn++)
    {
        // Управление
        for (int i = 0; i < gor; i++)
            if (_kbhit())
                speed[i] = _getch();

        a = speed[0];

        if (b != '2')
            b = speed[0];

        if (osn > 0)
        {
            schet_1--;
            osnova[schet_1][schet_2] = ' ';
            osnova[schet_1][schet_2 + 1] = ' ';
            osnova[schet_1 + 1][schet_2] = ' ';
            osnova[schet_1 + 1][schet_2 - 1] = ' ';
            schet_1++;
        }

        //// поворот ////
        if (a == '5'
            && osnova[schet_1][schet_2] == ' '
            && osnova[schet_1 + 1][schet_2] == ' '
            && osnova[schet_1 + 1][schet_2 + 1] == ' '
            && osnova[schet_1 + 2][schet_2 + 1] == ' '
            )
        {
            Show_zig_a(schet_1, schet_2);
            break;
        }
        /////////////////

        // в право
        for (int i = 0; (speed[i] == '6') && (i < gor); i++)
        {
            if (osnova[schet_1][schet_2 + 2] == 2)
                break;
            schet_2++;
            a = ' ';
            b = ' ';
        }

        // в лево
        for (int i = 0; (speed[i] == '4') && (i < gor); i++)
        {
            if (osnova[schet_1 + 1][schet_2 - 2] == 2 || osnova[schet_1][schet_2 - 1] == 2)
                break;
            schet_2--;
            a = ' ';
            b = ' ';
        }
        /////////////////////////////////
        osnova[schet_1][schet_2] = 2;
        osnova[schet_1][schet_2 + 1] = 2;
        osnova[schet_1 + 1][schet_2] = 2;
        osnova[schet_1 + 1][schet_2 - 1] = 2;

        if (osnova[schet_1 + 1][schet_2 + 1] == 2 || osnova[schet_1 + 2][schet_2] == 2 || osnova[schet_1 + 2][schet_2 - 1] == 2)break;

        schet_1++;

        // пауза
        if (a == '0')
            a = Pause(a);

        // Вывод массива
        Vosnova();

        // в низ
        // задержка
        if (b == '2')
            Delay(0.03);
        else
            Delay(skorost);

        // чистка //
        for (int i = 0; i < gor / 2; i++)
            speed[i] = ' ';

        a = ' ';

        system("CLS");
    }
    //....................//

    // Проверка на полную строку //
    och_int += Yes();
    //....................//

    // Проверка очков на прохождение уровня //
    Lavel(och_int);
    //....................//

    delete[] speed;
}
// Зигзаг б
void Constractor::Show_zig_b(int mesto_1, int mesto_2)
{
    // Общее обьявления //
    char a = ' ';           // основа управления
    char b = ' ';           // для ускорения падения
    int schet_1 = mesto_1;      // значение массива 1
    int schet_2 = mesto_2;  // значение массива 2

    char* speed;            // для быстрого перемещения в бока
    speed = new char[gor];
    //...................//

    // Проверка на конец
    Game_over();
    // Переменная для проверки уровня
    level_1++;

    // Начало цикла падения //
    for (int osn = 0; ; osn++)
    {
        // Управление
        for (int i = 0; i < gor; i++)
            if (_kbhit())
                speed[i] = _getch();

        a = speed[0];

        if (b != '2')
            b = speed[0];

        if (osn > 0)
        {
            schet_1--;
            osnova[schet_1][schet_2] = ' ';
            osnova[schet_1 + 1][schet_2] = ' ';
            osnova[schet_1 + 1][schet_2 - 1] = ' ';
            osnova[schet_1 + 2][schet_2 - 1] = ' ';
            schet_1++;
        }

        //// поворот ////
        if (a == '5'
            && osnova[schet_1][schet_2] == ' '
            && osnova[schet_1][schet_2 + 1] == ' '
            && osnova[schet_1 + 1][schet_2 + 1] == ' '
            && osnova[schet_1 + 1][schet_2 + 2] == ' '
            )
        {
            Show_zig_b_2(schet_1, schet_2);
            break;
        }
        /////////////////

        // в право
        for (int i = 0; (speed[i] == '6') && (i < gor); i++)
        {
            if (osnova[schet_1][schet_2 + 1] == 2 || osnova[schet_1 + 1][schet_2 + 1] == 2)
                break;
            schet_2++;
            a = ' ';
            b = ' ';
        }

        // в лево
        for (int i = 0; (speed[i] == '4') && (i < gor); i++)
        {
            if (osnova[schet_1][schet_2 - 1] == 2 || osnova[schet_1 + 1][schet_2 - 2] == 2 || osnova[schet_1 + 2][schet_2 - 2] == 2)
                break;
            schet_2--;
            a = ' ';
            b = ' ';
        }
        /////////////////////////////////
        osnova[schet_1][schet_2] = 2;
        osnova[schet_1 + 1][schet_2] = 2;
        osnova[schet_1 + 1][schet_2 - 1] = 2;
        osnova[schet_1 + 2][schet_2 - 1] = 2;

        if (osnova[schet_1 + 3][schet_2 - 1] == 2 || osnova[schet_1 + 2][schet_2] == 2)break;

        schet_1++;

        // пауза
        if (a == '0')
            a = Pause(a);

        // Вывод массива
        Vosnova();

        // в низ
        // задержка
        if (b == '2')
            Delay(0.03);
        else
            Delay(skorost);

        // чистка //
        for (int i = 0; i < gor / 2; i++)
            speed[i] = ' ';

        a = ' ';

        system("CLS");
    }
    //....................//

    // Проверка на полную строку //
    och_int += Yes();
    //....................//

    // Проверка очков на прохождение уровня //
    Lavel(och_int);
    //....................//

    delete[] speed;
}

void Constractor::Show_zig_b_2(int mesto_1, int mesto_2)
{
    // Общее обьявления //
    char a = ' ';           // основа управления
    char b = ' ';           // для ускорения падения
    int schet_1 = mesto_1;      // значение массива 1
    int schet_2 = mesto_2;  // значение массива 2

    char* speed;            // для быстрого перемещения в бока
    speed = new char[gor];
    //...................//

    // Проверка на конец
    Game_over();
    // Переменная для проверки уровня
    level_1++;

    // Начало цикла падения //
    for (int osn = 0; ; osn++)
    {
        // Управление
        for (int i = 0; i < gor; i++)
            if (_kbhit())
                speed[i] = _getch();

        a = speed[0];

        if (b != '2')
            b = speed[0];

        if (osn > 0)
        {
            schet_1--;
            osnova[schet_1][schet_2] = ' ';
            osnova[schet_1][schet_2 + 1] = ' ';
            osnova[schet_1 + 1][schet_2 + 1] = ' ';
            osnova[schet_1 + 1][schet_2 + 2] = ' ';
            schet_1++;
        }

        //// поворот ////
        if (a == '5'
            && osnova[schet_1][schet_2] == ' '
            && osnova[schet_1 + 1][schet_2] == ' '
            && osnova[schet_1 + 1][schet_2 - 1] == ' '
            && osnova[schet_1 + 2][schet_2 - 1] == ' '
            )
        {
            Show_zig_b(schet_1, schet_2);
            break;
        }
        /////////////////

        // в право
        for (int i = 0; (speed[i] == '6') && (i < gor); i++)
        {
            if (osnova[schet_1 + 1][schet_2 + 3] == 2)
                break;
            schet_2++;
            a = ' ';
            b = ' ';
        }

        // в лево
        for (int i = 0; (speed[i] == '4') && (i < gor); i++)
        {
            if (osnova[schet_1][schet_2 - 1] == 2 || osnova[schet_1 + 1][schet_2 - 1] == 2)
                break;
            schet_2--;
            a = ' ';
            b = ' ';
        }
        /////////////////////////////////
        osnova[schet_1][schet_2] = 2;
        osnova[schet_1][schet_2 + 1] = 2;
        osnova[schet_1 + 1][schet_2 + 1] = 2;
        osnova[schet_1 + 1][schet_2 + 2] = 2;

        if (osnova[schet_1 + 1][schet_2] == 2 || osnova[schet_1 + 2][schet_2 + 1] == 2 || osnova[schet_1 + 2][schet_2 + 2] == 2)break;

        schet_1++;

        // пауза
        if (a == '0')
            a = Pause(a);

        // Вывод массива
        Vosnova();

        // в низ
        // задержка
        if (b == '2')
            Delay(0.03);
        else
            Delay(skorost);

        // чистка //
        for (int i = 0; i < gor / 2; i++)
            speed[i] = ' ';

        a = ' ';

        system("CLS");
    }
    //....................//

    // Проверка на полную строку //
    och_int += Yes();
    //....................//

    // Проверка очков на прохождение уровня //
    Lavel(och_int);
    //....................//

    delete[] speed;
}
// Палка
void Constractor::Show_pulka(int mesto_1, int mesto_2)
{
    // Общее обьявления //
    char a = ' ';           // основа управления
    char b = ' ';           // для ускорения падения
    int schet_1 = mesto_1;      // значение массива 1
    int schet_2 = mesto_2;  // значение массива 2

    char* speed;            // для быстрого перемещения в бока
    speed = new char[gor];
    //...................//

    // Проверка на конец
    Game_over();
    // Переменная для проверки уровня
    level_1++;

    // Начало цикла падения //
    for (int osn = 0; ; osn++)
    {
        // Управление
        for (int i = 0; i < gor; i++)
            if (_kbhit())
                speed[i] = _getch();

        a = speed[0];

        if (b != '2')
            b = speed[0];

        if (osn > 0)
        {
            schet_1--;
            osnova[schet_1][schet_2] = ' ';
            osnova[schet_1 + 1][schet_2] = ' ';
            osnova[schet_1 + 2][schet_2] = ' ';
            osnova[schet_1 + 3][schet_2] = ' ';
            schet_1++;
        }

        //// поворот ////
        if (a == '5'
            && osnova[schet_1][schet_2] == ' '
            && osnova[schet_1][schet_2 - 1] == ' '
            && osnova[schet_1][schet_2 + 1] == ' '
            && osnova[schet_1][schet_2 + 2] == ' '
            )
        {
            Show_pulka_b(schet_1, schet_2);
            break;
        }
        /////////////////

        // в право
        for (int i = 0; (speed[i] == '6') && (i < gor); i++)
        {
            if (osnova[schet_1][schet_2 + 1] == 2 || osnova[schet_1 + 1][schet_2 + 1] == 2 || osnova[schet_1 + 2][schet_2 + 1] == 2 || osnova[schet_1 + 3][schet_2 + 1] == 2)
                break;
            schet_2++;
            a = ' ';
            b = ' ';
        }

        // в лево
        for (int i = 0; (speed[i] == '4') && (i < gor); i++)
        {
            if (osnova[schet_1][schet_2 - 1] == 2 || osnova[schet_1 + 1][schet_2 - 1] == 2 || osnova[schet_1 + 2][schet_2 - 1] == 2 || osnova[schet_1 + 3][schet_2 - 1] == 2)
                break;
            schet_2--;
            a = ' ';
            b = ' ';
        }
        /////////////////////////////////
        osnova[schet_1][schet_2] = 2;
        osnova[schet_1 + 1][schet_2] = 2;
        osnova[schet_1 + 2][schet_2] = 2;
        osnova[schet_1 + 3][schet_2] = 2;

        if (osnova[schet_1 + 4][schet_2] == 2)break;

        schet_1++;

        // пауза
        if (a == '0')
            a = Pause(a);

        // Вывод массива
        Vosnova();

        // в низ
        // задержка
        if (b == '2')
            Delay(0.03);
        else
            Delay(skorost);

        // чистка //
        for (int i = 0; i < gor / 2; i++)
            speed[i] = ' ';

        a = ' ';

        system("CLS");
    }
    //....................//

    // Проверка на полную строку //
    och_int += Yes();
    //....................//

    // Проверка очков на прохождение уровня //
    Lavel(och_int);
    //....................//

    delete[] speed;
}

void Constractor::Show_pulka_b(int mesto_1, int mesto_2)
{
    // Общее обьявления //
    char a = ' ';           // основа управления
    char b = ' ';           // для ускорения падения
    int schet_1 = mesto_1;      // значение массива 1
    int schet_2 = mesto_2;  // значение массива 2

    char* speed;            // для быстрого перемещения в бока
    speed = new char[gor];
    //...................//

    // Проверка на конец
    Game_over();
    // Переменная для проверки уровня
    level_1++;

    // Начало цикла падения //
    for (int osn = 0; ; osn++)
    {
        // Управление
        for (int i = 0; i < gor; i++)
            if (_kbhit())
                speed[i] = _getch();

        a = speed[0];

        if (b != '2')
            b = speed[0];

        if (osn > 0)
        {
            schet_1--;
            osnova[schet_1][schet_2] = ' ';
            osnova[schet_1][schet_2 - 1] = ' ';
            osnova[schet_1][schet_2 + 1] = ' ';
            osnova[schet_1][schet_2 + 2] = ' ';
            schet_1++;
        }

        //// поворот ////
        if (a == '5'
            && osnova[schet_1][schet_2] == ' '
            && osnova[schet_1 + 1][schet_2] == ' '
            && osnova[schet_1 + 2][schet_2] == ' '
            && osnova[schet_1 + 3][schet_2] == ' '
            )
        {
            Show_pulka(schet_1, schet_2);
            break;
        }
        /////////////////

        // в право
        for (int i = 0; (speed[i] == '6') && (i < gor); i++)
        {
            if (osnova[schet_1][schet_2 + 3] == 2)
                break;
            schet_2++;
            a = ' ';
            b = ' ';
        }

        // в лево
        for (int i = 0; (speed[i] == '4') && (i < gor); i++)
        {
            if (osnova[schet_1][schet_2 - 2] == 2)
                break;
            schet_2--;
            a = ' ';
            b = ' ';
        }
        /////////////////////////////////
        osnova[schet_1][schet_2] = 2;
        osnova[schet_1][schet_2 - 1] = 2;
        osnova[schet_1][schet_2 + 1] = 2;
        osnova[schet_1][schet_2 + 2] = 2;

        if (osnova[schet_1 + 1][schet_2] == 2 || osnova[schet_1 + 1][schet_2 - 1] == 2 || osnova[schet_1 + 1][schet_2 + 1] == 2 || osnova[schet_1 + 1][schet_2 + 2] == 2)break;

        schet_1++;

        // пауза
        if (a == '0')
            a = Pause(a);

        // Вывод массива
        Vosnova();

        // в низ
        // задержка
        if (b == '2')
            Delay(0.03);
        else
            Delay(skorost);

        // чистка //
        for (int i = 0; i < gor / 2; i++)
            speed[i] = ' ';

        a = ' ';

        system("CLS");
    }
    //....................//

    // Проверка на полную строку //
    och_int += Yes();
    //....................//

    // Проверка очков на прохождение уровня //
    Lavel(och_int);
    //....................//

    delete[] speed;
}
// Уголок левый
void Constractor::Show_ugoll(int mesto_1, int mesto_2)
{
    // Общее обьявления //
    char a = ' ';           // основа управления
    char b = ' ';           // для ускорения падения
    int schet_1 = mesto_1;      // значение массива 1
    int schet_2 = mesto_2;  // значение массива 2

    char* speed;            // для быстрого перемещения в бока
    speed = new char[gor];
    //...................//

    // Проверка на конец
    Game_over();
    // Переменная для проверки уровня
    level_1++;

    // Начало цикла падения //
    for (int osn = 0; ; osn++)
    {
        // Управление
        for (int i = 0; i < gor; i++)
            if (_kbhit())
                speed[i] = _getch();

        a = speed[0];

        if (b != '2')
            b = speed[0];

        if (osn > 0)
        {
            schet_1--;
            osnova[schet_1][schet_2] = ' ';
            osnova[schet_1 + 1][schet_2] = ' ';
            osnova[schet_1 + 2][schet_2] = ' ';
            osnova[schet_1 + 2][schet_2 + 1] = ' ';
            schet_1++;
        }

        //// поворот ////
        if (a == '5'
            && osnova[schet_1 + 1][schet_2 - 2] == ' '
            && osnova[schet_1 + 1][schet_2 - 1] == ' '
            && osnova[schet_1 + 1][schet_2] == ' '
            && osnova[schet_1][schet_2] == ' '
            )
        {
            Show_ugoll_b(schet_1, schet_2);
            break;
        }
        /////////////////

        // в право
        for (int i = 0; (speed[i] == '6') && (i < gor); i++)
        {
            if (osnova[schet_1][schet_2 + 2] == 2 || osnova[schet_1 + 1][schet_2 + 2] == 2 || osnova[schet_1 + 2][schet_2 + 1] == 2)
                break;
            schet_2++;
            a = ' ';
            b = ' ';
        }

        // в лево
        for (int i = 0; (speed[i] == '4') && (i < gor); i++)
        {
            if (osnova[schet_1][schet_2 - 1] == 2 || osnova[schet_1 + 1][schet_2 - 1] == 2 || osnova[schet_1 + 2][schet_2 - 1] == 2)
                break;
            schet_2--;
            a = ' ';
            b = ' ';
        }
        /////////////////////////////////
        osnova[schet_1][schet_2] = 2;
        osnova[schet_1 + 1][schet_2] = 2;
        osnova[schet_1 + 2][schet_2] = 2;
        osnova[schet_1 + 2][schet_2 + 1] = 2;

        if (osnova[schet_1 + 3][schet_2] == 2 || osnova[schet_1 + 3][schet_2 + 1] == 2)break;

        schet_1++;

        // пауза
        if (a == '0')
            a = Pause(a);

        // Вывод массива
        Vosnova();

        // в низ
        // задержка
        if (b == '2')
            Delay(0.03);
        else
            Delay(skorost);

        // чистка //
        for (int i = 0; i < gor / 2; i++)
            speed[i] = ' ';

        a = ' ';

        system("CLS");
    }
    //....................//

    // Проверка на полную строку //
    och_int += Yes();
    //....................//

    // Проверка очков на прохождение уровня //
    Lavel(och_int);
    //....................//

    delete[] speed;
}

void Constractor::Show_ugoll_b(int mesto_1, int mesto_2)
{
    // Общее обьявления //
    char a = ' ';           // основа управления
    char b = ' ';           // для ускорения падения
    int schet_1 = mesto_1;      // значение массива 1
    int schet_2 = mesto_2;  // значение массива 2

    char* speed;            // для быстрого перемещения в бока
    speed = new char[gor];
    //...................//

    // Проверка на конец
    Game_over();
    // Переменная для проверки уровня
    level_1++;

    // Начало цикла падения //
    for (int osn = 0; ; osn++)
    {
        // Управление
        for (int i = 0; i < gor; i++)
            if (_kbhit())
                speed[i] = _getch();

        a = speed[0];

        if (b != '2')
            b = speed[0];

        if (osn > 0)
        {
            schet_1--;
            osnova[schet_1 + 1][schet_2 - 2] = ' ';
            osnova[schet_1 + 1][schet_2 - 1] = ' ';
            osnova[schet_1 + 1][schet_2] = ' ';
            osnova[schet_1][schet_2] = ' ';
            schet_1++;
        }

        //// поворот ////
        if (a == '5'
            && osnova[schet_1][schet_2] == ' '
            && osnova[schet_1 + 1][schet_2] == ' '
            && osnova[schet_1 + 2][schet_2] == ' '
            && osnova[schet_1 + 2][schet_2 + 1] == ' '
            )
        {
            Show_ugoll_c(schet_1, schet_2);
            break;
        }
        /////////////////

        // в право
        for (int i = 0; (speed[i] == '6') && (i < gor); i++)
        {
            if (osnova[schet_1][schet_2 + 1] == 2 || osnova[schet_1 + 1][schet_2 + 1] == 2)
                break;
            schet_2++;
            a = ' ';
            b = ' ';
        }

        // в лево
        for (int i = 0; (speed[i] == '4') && (i < gor); i++)
        {
            if (osnova[schet_1 + 1][schet_2 - 3] == 2 || osnova[schet_1][schet_2 - 1] == 2)
                break;
            schet_2--;
            a = ' ';
            b = ' ';
        }
        /////////////////////////////////
        osnova[schet_1 + 1][schet_2 - 2] = 2;
        osnova[schet_1 + 1][schet_2 - 1] = 2;
        osnova[schet_1 + 1][schet_2] = 2;
        osnova[schet_1][schet_2] = 2;

        if (osnova[schet_1 + 2][schet_2] == 2 || osnova[schet_1 + 2][schet_2 - 1] == 2 || osnova[schet_1 + 2][schet_2 - 2] == 2)break;

        schet_1++;

        // пауза
        if (a == '0')
            a = Pause(a);

        // Вывод массива
        Vosnova();

        // в низ
        // задержка
        if (b == '2')
            Delay(0.03);
        else
            Delay(skorost);

        // чистка //
        for (int i = 0; i < gor / 2; i++)
            speed[i] = ' ';

        a = ' ';

        system("CLS");
    }
    //....................//

    // Проверка на полную строку //
    och_int += Yes();
    //....................//

    // Проверка очков на прохождение уровня //
    Lavel(och_int);
    //....................//

    delete[] speed;
}

void Constractor::Show_ugoll_c(int mesto_1, int mesto_2)
{
    // Общее обьявления //
    char a = ' ';           // основа управления
    char b = ' ';           // для ускорения падения
    int schet_1 = mesto_1;      // значение массива 1
    int schet_2 = mesto_2;  // значение массива 2

    char* speed;            // для быстрого перемещения в бока
    speed = new char[gor];
    //...................//

    // Проверка на конец
    Game_over();
    // Переменная для проверки уровня
    level_1++;

    // Начало цикла падения //
    for (int osn = 0; ; osn++)
    {
        // Управление
        for (int i = 0; i < gor; i++)
            if (_kbhit())
                speed[i] = _getch();

        a = speed[0];

        if (b != '2')
            b = speed[0];

        if (osn > 0)
        {
            schet_1--;
            osnova[schet_1][schet_2] = ' ';
            osnova[schet_1][schet_2 - 1] = ' ';
            osnova[schet_1 + 1][schet_2] = ' ';
            osnova[schet_1 + 2][schet_2] = ' ';
            schet_1++;
        }

        //// поворот ////
        if (a == '5'
            && osnova[schet_1 + 1][schet_2 - 2] == ' '
            && osnova[schet_1 + 1][schet_2 - 1] == ' '
            && osnova[schet_1 + 1][schet_2] == ' '
            && osnova[schet_1][schet_2] == ' '
            )
        {
            Show_ugoll_d(schet_1, schet_2);
            break;
        }
        /////////////////

        // в право
        for (int i = 0; (speed[i] == '6') && (i < gor); i++)
        {
            if (osnova[schet_1][schet_2 + 1] == 2 || osnova[schet_1 + 1][schet_2 + 1] == 2 || osnova[schet_1 + 2][schet_2 + 1] == 2)
                break;
            schet_2++;
            a = ' ';
            b = ' ';
        }

        // в лево
        for (int i = 0; (speed[i] == '4') && (i < gor); i++)
        {
            if (osnova[schet_1][schet_2 - 2] == 2 || osnova[schet_1 + 1][schet_2 - 1] == 2 || osnova[schet_1 + 2][schet_2 - 1] == 2)
                break;
            schet_2--;
            a = ' ';
            b = ' ';
        }
        /////////////////////////////////
        osnova[schet_1][schet_2] = 2;
        osnova[schet_1][schet_2 - 1] = 2;
        osnova[schet_1 + 1][schet_2] = 2;
        osnova[schet_1 + 2][schet_2] = 2;

        if (osnova[schet_1 + 3][schet_2] == 2 || osnova[schet_1 + 1][schet_2 - 1] == 2)break;

        schet_1++;

        // пауза
        if (a == '0')
            a = Pause(a);

        // Вывод массива
        Vosnova();

        // в низ
        // задержка
        if (b == '2')
            Delay(0.03);
        else
            Delay(skorost);

        // чистка //
        for (int i = 0; i < gor / 2; i++)
            speed[i] = ' ';

        a = ' ';

        system("CLS");
    }
    //....................//

    // Проверка на полную строку //
    och_int += Yes();
    //....................//

    // Проверка очков на прохождение уровня //
    Lavel(och_int);
    //....................//

    delete[] speed;
}

void Constractor::Show_ugoll_d(int mesto_1, int mesto_2)
{
    // Общее обьявления //
    char a = ' ';           // основа управления
    char b = ' ';           // для ускорения падения
    int schet_1 = mesto_1;      // значение массива 1
    int schet_2 = mesto_2;  // значение массива 2

    char* speed;            // для быстрого перемещения в бока
    speed = new char[gor];
    //...................//

    // Проверка на конец
    Game_over();
    // Переменная для проверки уровня
    level_1++;

    // Начало цикла падения //
    for (int osn = 0; ; osn++)
    {
        // Управление
        for (int i = 0; i < gor; i++)
            if (_kbhit())
                speed[i] = _getch();

        a = speed[0];

        if (b != '2')
            b = speed[0];

        if (osn > 0)
        {
            schet_1--;
            osnova[schet_1][schet_2] = ' ';
            osnova[schet_1 + 1][schet_2] = ' ';
            osnova[schet_1][schet_2 + 1] = ' ';
            osnova[schet_1][schet_2 + 2] = ' ';
            schet_1++;
        }

        //// поворот ////
        if (a == '5'
            && osnova[schet_1][schet_2] == ' '
            && osnova[schet_1 + 1][schet_2] == ' '
            && osnova[schet_1 + 2][schet_2] == ' '
            && osnova[schet_1 + 2][schet_2 + 1] == ' '
            )
        {
            Show_ugoll(schet_1, schet_2);
            break;
        }
        /////////////////

        // в право
        for (int i = 0; (speed[i] == '6') && (i < gor); i++)
        {
            if (osnova[schet_1][schet_2 + 3] == 2 || osnova[schet_1 + 1][schet_2 + 1] == 2)
                break;
            schet_2++;
            a = ' ';
            b = ' ';
        }

        // в лево
        for (int i = 0; (speed[i] == '4') && (i < gor); i++)
        {
            if (osnova[schet_1][schet_2 - 1] == 2 || osnova[schet_1 + 1][schet_2 - 1] == 2)
                break;
            schet_2--;
            a = ' ';
            b = ' ';
        }
        /////////////////////////////////
        osnova[schet_1][schet_2] = 2;
        osnova[schet_1 + 1][schet_2] = 2;
        osnova[schet_1][schet_2 + 1] = 2;
        osnova[schet_1][schet_2 + 2] = 2;

        if (osnova[schet_1 + 2][schet_2] == 2 || osnova[schet_1 + 1][schet_2 + 1] == 2 || osnova[schet_1 + 1][schet_2 + 2] == 2)break;

        schet_1++;

        // пауза
        if (a == '0')
            a = Pause(a);

        // Вывод массива
        Vosnova();

        // в низ
        // задержка
        if (b == '2')
            Delay(0.03);
        else
            Delay(skorost);

        // чистка //
        for (int i = 0; i < gor / 2; i++)
            speed[i] = ' ';

        a = ' ';

        system("CLS");
    }
    //....................//

    // Проверка на полную строку //
    och_int += Yes();
    //....................//

    // Проверка очков на прохождение уровня //
    Lavel(och_int);
    //....................//

    delete[] speed;
}
// Уголок правый
void Constractor::Show_ugolp(int mesto_1, int mesto_2)
{
    // Общее обьявления //
    char a = ' ';           // основа управления
    char b = ' ';           // для ускорения падения
    int schet_1 = mesto_1;      // значение массива 1
    int schet_2 = mesto_2;  // значение массива 2

    char* speed;            // для быстрого перемещения в бока
    speed = new char[gor];
    //...................//

    // Проверка на конец
    Game_over();
    // Переменная для проверки уровня
    level_1++;

    // Начало цикла падения //
    for (int osn = 0; ; osn++)
    {
        // Управление
        for (int i = 0; i < gor; i++)
            if (_kbhit())
                speed[i] = _getch();

        a = speed[0];

        if (b != '2')
            b = speed[0];

        if (osn > 0)
        {
            schet_1--;
            osnova[schet_1][schet_2] = ' ';
            osnova[schet_1 + 1][schet_2] = ' ';
            osnova[schet_1 + 2][schet_2] = ' ';
            osnova[schet_1 + 2][schet_2 - 1] = ' ';
            schet_1++;
        }

        //// поворот ////
        if (a == '5'
            && osnova[schet_1][schet_2] == ' '
            && osnova[schet_1 + 1][schet_2] == ' '
            && osnova[schet_1 + 1][schet_2 + 1] == ' '
            && osnova[schet_1 + 1][schet_2 + 2] == ' '
            )
        {
            Show_ugolp_b(schet_1, schet_2);
            break;
        }
        /////////////////

        // в право
        for (int i = 0; (speed[i] == '6') && (i < gor); i++)
        {
            if (osnova[schet_1][schet_2 + 1] == 2 || osnova[schet_1 + 1][schet_2 + 1] == 2 || osnova[schet_1 + 2][schet_2 + 1] == 2)
                break;
            schet_2++;
            a = ' ';
            b = ' ';
        }

        // в лево
        for (int i = 0; (speed[i] == '4') && (i < gor); i++)
        {
            if (osnova[schet_1][schet_2 - 1] == 2 || osnova[schet_1 + 1][schet_2 - 1] == 2 || osnova[schet_1 + 2][schet_2 - 2] == 2)
                break;
            schet_2--;
            a = ' ';
            b = ' ';
        }
        /////////////////////////////////
        osnova[schet_1][schet_2] = 2;
        osnova[schet_1 + 1][schet_2] = 2;
        osnova[schet_1 + 2][schet_2] = 2;
        osnova[schet_1 + 2][schet_2 - 1] = 2;

        if (osnova[schet_1 + 3][schet_2] == 2 || osnova[schet_1 + 3][schet_2 - 1] == 2)break;

        schet_1++;

        // пауза
        if (a == '0')
            a = Pause(a);

        // Вывод массива
        Vosnova();

        // в низ
        // задержка
        if (b == '2')
            Delay(0.03);
        else
            Delay(skorost);

        // чистка //
        for (int i = 0; i < gor / 2; i++)
            speed[i] = ' ';

        a = ' ';

        system("CLS");
    }
    //....................//

    // Проверка на полную строку //
    och_int += Yes();
    //....................//

    // Проверка очков на прохождение уровня //
    Lavel(och_int);
    //....................//

    delete[] speed;
}

void Constractor::Show_ugolp_b(int mesto_1, int mesto_2)
{
    // Общее обьявления //
    char a = ' ';           // основа управления
    char b = ' ';           // для ускорения падения
    int schet_1 = mesto_1;      // значение массива 1
    int schet_2 = mesto_2;  // значение массива 2

    char* speed;            // для быстрого перемещения в бока
    speed = new char[gor];
    //...................//

    // Проверка на конец
    Game_over();
    // Переменная для проверки уровня
    level_1++;

    // Начало цикла падения //
    for (int osn = 0; ; osn++)
    {
        // Управление
        for (int i = 0; i < gor; i++)
            if (_kbhit())
                speed[i] = _getch();

        a = speed[0];

        if (b != '2')
            b = speed[0];

        if (osn > 0)
        {
            schet_1--;
            osnova[schet_1][schet_2] = ' ';
            osnova[schet_1 + 1][schet_2] = ' ';
            osnova[schet_1 + 1][schet_2 + 1] = ' ';
            osnova[schet_1 + 1][schet_2 + 2] = ' ';
            schet_1++;
        }

        //// поворот ////
        if (a == '5'
            && osnova[schet_1][schet_2] == ' '
            && osnova[schet_1][schet_2 + 1] == ' '
            && osnova[schet_1 + 1][schet_2] == ' '
            && osnova[schet_1 + 2][schet_2] == ' '
            )
        {
            Show_ugolp_c(schet_1, schet_2);
            break;
        }
        /////////////////

        // в право
        for (int i = 0; (speed[i] == '6') && (i < gor); i++)
        {
            if (osnova[schet_1][schet_2 + 1] == 2 || osnova[schet_1 + 1][schet_2 + 3] == 2)
                break;
            schet_2++;
            a = ' ';
            b = ' ';
        }

        // в лево
        for (int i = 0; (speed[i] == '4') && (i < gor); i++)
        {
            if (osnova[schet_1][schet_2 - 1] == 2 || osnova[schet_1 + 1][schet_2 - 1] == 2)
                break;
            schet_2--;
            a = ' ';
            b = ' ';
        }
        /////////////////////////////////
        osnova[schet_1][schet_2] = 2;
        osnova[schet_1 + 1][schet_2] = 2;
        osnova[schet_1 + 1][schet_2 + 1] = 2;
        osnova[schet_1 + 1][schet_2 + 2] = 2;

        if (osnova[schet_1 + 2][schet_2] == 2 || osnova[schet_1 + 2][schet_2 + 1] == 2 || osnova[schet_1 + 2][schet_2 + 2] == 2)break;

        schet_1++;

        // пауза
        if (a == '0')
            a = Pause(a);

        // Вывод массива
        Vosnova();

        // в низ
        // задержка
        if (b == '2')
            Delay(0.03);
        else
            Delay(skorost);

        // чистка //
        for (int i = 0; i < gor / 2; i++)
            speed[i] = ' ';

        a = ' ';

        system("CLS");
    }
    //....................//

    // Проверка на полную строку //
    och_int += Yes();
    //....................//

    // Проверка очков на прохождение уровня //
    Lavel(och_int);
    //....................//

    delete[] speed;
}

void Constractor::Show_ugolp_c(int mesto_1, int mesto_2)
{
    // Общее обьявления //
    char a = ' ';           // основа управления
    char b = ' ';           // для ускорения падения
    int schet_1 = mesto_1;      // значение массива 1
    int schet_2 = mesto_2;  // значение массива 2

    char* speed;            // для быстрого перемещения в бока
    speed = new char[gor];
    //...................//

    // Проверка на конец
    Game_over();
    // Переменная для проверки уровня
    level_1++;

    // Начало цикла падения //
    for (int osn = 0; ; osn++)
    {
        // Управление
        for (int i = 0; i < gor; i++)
            if (_kbhit())
                speed[i] = _getch();

        a = speed[0];

        if (b != '2')
            b = speed[0];

        if (osn > 0)
        {
            schet_1--;
            osnova[schet_1][schet_2] = ' ';
            osnova[schet_1][schet_2 + 1] = ' ';
            osnova[schet_1 + 1][schet_2] = ' ';
            osnova[schet_1 + 2][schet_2] = ' ';
            schet_1++;
        }

        //// поворот ////
        if (a == '5'
            && osnova[schet_1][schet_2] == ' '
            && osnova[schet_1][schet_2 - 1] == ' '
            && osnova[schet_1][schet_2 + 1] == ' '
            && osnova[schet_1 + 1][schet_2 + 1] == ' '
            )
        {
            Show_ugolp_d(schet_1, schet_2);
            break;
        }
        /////////////////

        // в право
        for (int i = 0; (speed[i] == '6') && (i < gor); i++)
        {
            if (osnova[schet_1][schet_2 + 2] == 2 || osnova[schet_1 + 1][schet_2 + 1] == 2 || osnova[schet_1 + 2][schet_2 + 1] == 2)
                break;
            schet_2++;
            a = ' ';
            b = ' ';
        }

        // в лево
        for (int i = 0; (speed[i] == '4') && (i < gor); i++)
        {
            if (osnova[schet_1][schet_2 - 1] == 2 || osnova[schet_1 + 1][schet_2 - 1] == 2 || osnova[schet_1 + 2][schet_2 - 1] == 2)
                break;
            schet_2--;
            a = ' ';
            b = ' ';
        }
        /////////////////////////////////
        osnova[schet_1][schet_2] = 2;
        osnova[schet_1][schet_2 + 1] = 2;
        osnova[schet_1 + 1][schet_2] = 2;
        osnova[schet_1 + 2][schet_2] = 2;

        if (osnova[schet_1 + 3][schet_2] == 2 || osnova[schet_1 + 1][schet_2 + 1] == 2)break;

        schet_1++;

        // пауза
        if (a == '0')
            a = Pause(a);

        // Вывод массива
        Vosnova();

        // в низ
        // задержка
        if (b == '2')
            Delay(0.03);
        else
            Delay(skorost);

        // чистка //
        for (int i = 0; i < gor / 2; i++)
            speed[i] = ' ';

        a = ' ';

        system("CLS");
    }
    //....................//

    // Проверка на полную строку //
    och_int += Yes();
    //....................//

    // Проверка очков на прохождение уровня //
    Lavel(och_int);
    //....................//

    delete[] speed;
}

void Constractor::Show_ugolp_d(int mesto_1, int mesto_2)
{
    // Общее обьявления //
    char a = ' ';           // основа управления
    char b = ' ';           // для ускорения падения
    int schet_1 = mesto_1;      // значение массива 1
    int schet_2 = mesto_2;  // значение массива 2

    char* speed;            // для быстрого перемещения в бока
    speed = new char[gor];
    //...................//

    // Проверка на конец
    Game_over();
    // Переменная для проверки уровня
    level_1++;

    // Начало цикла падения //
    for (int osn = 0; ; osn++)
    {
        // Управление
        for (int i = 0; i < gor; i++)
            if (_kbhit())
                speed[i] = _getch();

        a = speed[0];

        if (b != '2')
            b = speed[0];

        if (osn > 0)
        {
            schet_1--;
            osnova[schet_1][schet_2] = ' ';
            osnova[schet_1][schet_2 - 1] = ' ';
            osnova[schet_1][schet_2 + 1] = ' ';
            osnova[schet_1 + 1][schet_2 + 1] = ' ';
            schet_1++;
        }

        //// поворот ////
        if (a == '5'
            && osnova[schet_1][schet_2] == ' '
            && osnova[schet_1 + 1][schet_2] == ' '
            && osnova[schet_1 + 2][schet_2] == ' '
            && osnova[schet_1 + 2][schet_2 - 1] == ' '
            )
        {
            Show_ugolp(schet_1, schet_2);
            break;
        }
        /////////////////

        // в право
        for (int i = 0; (speed[i] == '6') && (i < gor); i++)
        {
            if (osnova[schet_1][schet_2 + 2] == 2 || osnova[schet_1 + 1][schet_2 + 2] == 2)
                break;
            schet_2++;
            a = ' ';
            b = ' ';
        }

        // в лево
        for (int i = 0; (speed[i] == '4') && (i < gor); i++)
        {
            if (osnova[schet_1][schet_2 - 2] == 2 || osnova[schet_1 + 1][schet_2] == 2)
                break;
            schet_2--;
            a = ' ';
            b = ' ';
        }
        /////////////////////////////////
        osnova[schet_1][schet_2] = 2;
        osnova[schet_1][schet_2 - 1] = 2;
        osnova[schet_1][schet_2 + 1] = 2;
        osnova[schet_1 + 1][schet_2 + 1] = 2;

        if (osnova[schet_1 + 1][schet_2] == 2 || osnova[schet_1 + 1][schet_2 - 1] == 2 || osnova[schet_1 + 2][schet_2 + 1] == 2)break;

        schet_1++;

        // пауза
        if (a == '0')
            a = Pause(a);

        // Вывод массива
        Vosnova();

        // в низ
        // задержка
        if (b == '2')
            Delay(0.01);
        else
            Delay(skorost);

        // чистка //
        for (int i = 0; i < gor / 2; i++)
            speed[i] = ' ';

        a = ' ';

        system("CLS");
    }
    //....................//

    // Проверка на полную строку //
    och_int += Yes();
    //....................//

    // Проверка очков на прохождение уровня //
    Lavel(och_int);
    //....................//

    delete[] speed;
}
// Полукрест
void Constractor::Show_polkrest(int mesto_1, int mesto_2)
{
    // Общее обьявления //
    char a = ' ';           // основа управления
    char b = ' ';           // для ускорения падения
    int schet_1 = mesto_1;      // значение массива 1
    int schet_2 = mesto_2;  // значение массива 2

    char* speed;            // для быстрого перемещения в бока
    speed = new char[gor];
    //...................//

    // Проверка на конец
    Game_over();
    // Переменная для проверки уровня
    level_1++;

    // Начало цикла падения //
    for (int osn = 0; ; osn++)
    {
        // Управление
        for (int i = 0; i < gor; i++)
            if (_kbhit())
                speed[i] = _getch();

        a = speed[0];

        if (b != '2')
            b = speed[0];

        if (osn > 0)
        {
            schet_1--;
            osnova[schet_1][schet_2] = ' ';
            osnova[schet_1 + 1][schet_2 - 1] = ' ';
            osnova[schet_1 + 1][schet_2] = ' ';
            osnova[schet_1 + 1][schet_2 + 1] = ' ';
            schet_1++;
        }

        //// поворот ////
        if (a == '5'
            && osnova[schet_1][schet_2] == ' '
            && osnova[schet_1 + 1][schet_2] == ' '
            && osnova[schet_1 + 2][schet_2] == ' '
            && osnova[schet_1 + 1][schet_2 - 1] == ' '
            )
        {
            Show_polkrest_b(schet_1, schet_2);
            break;
        }
        /////////////////

        // в право
        for (int i = 0; (speed[i] == '6') && (i < gor); i++)
        {
            if (osnova[schet_1 + 1][schet_2 + 2] == 2 || osnova[schet_1][schet_2 + 1] == 2)
                break;
            schet_2++;
            a = ' ';
            b = ' ';
        }

        // в лево
        for (int i = 0; (speed[i] == '4') && (i < gor); i++)
        {
            if (osnova[schet_1 + 1][schet_2 - 2] == 2 || osnova[schet_1][schet_2 - 1] == 2)
                break;
            schet_2--;
            a = ' ';
            b = ' ';
        }
        /////////////////////////////////
        osnova[schet_1][schet_2] = 2;
        osnova[schet_1 + 1][schet_2 - 1] = 2;
        osnova[schet_1 + 1][schet_2] = 2;
        osnova[schet_1 + 1][schet_2 + 1] = 2;

        if (osnova[schet_1 + 2][schet_2 - 1] == 2 || osnova[schet_1 + 2][schet_2] == 2 || osnova[schet_1 + 2][schet_2 + 1] == 2)break;

        schet_1++;

        // пауза
        if (a == '0')
            a = Pause(a);

        // Вывод массива
        Vosnova();

        // в низ
        // задержка
        if (b == '2')
            Delay(0.03);
        else
            Delay(skorost);

        // чистка //
        for (int i = 0; i < gor / 2; i++)
            speed[i] = ' ';

        a = ' ';

        system("CLS");
    }
    //....................//

    // Проверка на полную строку //
    och_int += Yes();
    //....................//

    // Проверка очков на прохождение уровня //
    Lavel(och_int);
    //....................//

    delete[] speed;
}

void Constractor::Show_polkrest_b(int mesto_1, int mesto_2)
{
    // Общее обьявления //
    char a = ' ';           // основа управления
    char b = ' ';           // для ускорения падения
    int schet_1 = mesto_1;      // значение массива 1
    int schet_2 = mesto_2;  // значение массива 2

    char* speed;            // для быстрого перемещения в бока
    speed = new char[gor];
    //...................//

    // Проверка на конец
    Game_over();
    // Переменная для проверки уровня
    level_1++;

    // Начало цикла падения //
    for (int osn = 0; ; osn++)
    {
        // Управление
        for (int i = 0; i < gor; i++)
            if (_kbhit())
                speed[i] = _getch();

        a = speed[0];

        if (b != '2')
            b = speed[0];

        if (osn > 0)
        {
            schet_1--;
            osnova[schet_1][schet_2] = ' ';
            osnova[schet_1 + 1][schet_2] = ' ';
            osnova[schet_1 + 2][schet_2] = ' ';
            osnova[schet_1 + 1][schet_2 - 1] = ' ';
            schet_1++;
        }

        //// поворот ////
        if (a == '5'
            && osnova[schet_1][schet_2] == ' '
            && osnova[schet_1][schet_2 + 1] == ' '
            && osnova[schet_1][schet_2 + 2] == ' '
            && osnova[schet_1 + 1][schet_2 + 1] == ' '
            )
        {
            Show_polkrest_c(schet_1, schet_2);
            break;
        }
        /////////////////

        // в право
        for (int i = 0; (speed[i] == '6') && (i < gor); i++)
        {
            if (osnova[schet_1][schet_2 + 1] == 2 || osnova[schet_1 + 1][schet_2 + 1] == 2 || osnova[schet_1 + 2][schet_2 + 1] == 2)
                break;
            schet_2++;
            a = ' ';
            b = ' ';
        }

        // в лево
        for (int i = 0; (speed[i] == '4') && (i < gor); i++)
        {
            if (osnova[schet_1][schet_2 - 1] == 2 || osnova[schet_1 + 1][schet_2 - 2] == 2 || osnova[schet_1 + 2][schet_2 - 1] == 2)
                break;
            schet_2--;
            a = ' ';
            b = ' ';
        }
        /////////////////////////////////
        osnova[schet_1][schet_2] = 2;
        osnova[schet_1 + 1][schet_2] = 2;
        osnova[schet_1 + 2][schet_2] = 2;
        osnova[schet_1 + 1][schet_2 - 1] = 2;

        if (osnova[schet_1 + 3][schet_2] == 2 || osnova[schet_1 + 2][schet_2 - 1] == 2)break;

        schet_1++;

        // пауза
        if (a == '0')
            a = Pause(a);

        // Вывод массива
        Vosnova();

        // в низ
        // задержка
        if (b == '2')
            Delay(0.03);
        else
            Delay(skorost);

        // чистка //
        for (int i = 0; i < gor / 2; i++)
            speed[i] = ' ';

        a = ' ';

        system("CLS");
    }
    //....................//

    // Проверка на полную строку //
    och_int += Yes();
    //....................//

    // Проверка очков на прохождение уровня //
    Lavel(och_int);
    //....................//

    delete[] speed;
}

void Constractor::Show_polkrest_c(int mesto_1, int mesto_2)
{
    // Общее обьявления //
    char a = ' ';           // основа управления
    char b = ' ';           // для ускорения падения
    int schet_1 = mesto_1;      // значение массива 1
    int schet_2 = mesto_2;  // значение массива 2

    char* speed;            // для быстрого перемещения в бока
    speed = new char[gor];
    //...................//

    // Проверка на конец
    Game_over();
    // Переменная для проверки уровня
    level_1++;

    // Начало цикла падения //
    for (int osn = 0; ; osn++)
    {
        // Управление
        for (int i = 0; i < gor; i++)
            if (_kbhit())
                speed[i] = _getch();

        a = speed[0];

        if (b != '2')
            b = speed[0];

        if (osn > 0)
        {
            schet_1--;
            osnova[schet_1][schet_2] = ' ';
            osnova[schet_1][schet_2 + 1] = ' ';
            osnova[schet_1][schet_2 + 2] = ' ';
            osnova[schet_1 + 1][schet_2 + 1] = ' ';
            schet_1++;
        }

        //// поворот ////
        if (a == '5'
            && osnova[schet_1][schet_2] == ' '
            && osnova[schet_1 + 1][schet_2] == ' '
            && osnova[schet_1 + 2][schet_2] == ' '
            && osnova[schet_1 + 1][schet_2 + 1] == ' '
            )
        {
            Show_polkrest_d(schet_1, schet_2);
            break;
        }
        /////////////////

        // в право
        for (int i = 0; (speed[i] == '6') && (i < gor); i++)
        {
            if (osnova[schet_1][schet_2 + 3] == 2 || osnova[schet_1 + 1][schet_2 + 2] == 2)
                break;
            schet_2++;
            a = ' ';
            b = ' ';
        }

        // в лево
        for (int i = 0; (speed[i] == '4') && (i < gor); i++)
        {
            if (osnova[schet_1][schet_2 - 1] == 2 || osnova[schet_1 + 1][schet_2 - 1] == 2)
                break;
            schet_2--;
            a = ' ';
            b = ' ';
        }
        /////////////////////////////////
        osnova[schet_1][schet_2] = 2;
        osnova[schet_1][schet_2 + 1] = 2;
        osnova[schet_1][schet_2 + 2] = 2;
        osnova[schet_1 + 1][schet_2 + 1] = 2;

        if (osnova[schet_1 + 1][schet_2] == 2 || osnova[schet_1 + 2][schet_2 + 1] == 2 || osnova[schet_1 + 1][schet_2 + 2] == 2)break;

        schet_1++;

        // пауза
        if (a == '0')
            a = Pause(a);

        // Вывод массива
        Vosnova();

        // в низ
        // задержка
        if (b == '2')
            Delay(0.03);
        else
            Delay(skorost);

        // чистка //
        for (int i = 0; i < gor / 2; i++)
            speed[i] = ' ';

        a = ' ';

        system("CLS");
    }
    //....................//

    // Проверка на полную строку //
    och_int += Yes();
    //....................//

    // Проверка очков на прохождение уровня //
    Lavel(och_int);
    //....................//

    delete[] speed;
}

void Constractor::Show_polkrest_d(int mesto_1, int mesto_2)
{
    // Общее обьявления //
    char a = ' ';           // основа управления
    char b = ' ';           // для ускорения падения
    int schet_1 = mesto_1;      // значение массива 1
    int schet_2 = mesto_2;  // значение массива 2

    char* speed;            // для быстрого перемещения в бока
    speed = new char[gor];
    //...................//

    // Проверка на конец
    Game_over();
    // Переменная для проверки уровня
    level_1++;

    // Начало цикла падения //
    for (int osn = 0; ; osn++)
    {
        // Управление
        for (int i = 0; i < gor; i++)
            if (_kbhit())
                speed[i] = _getch();

        a = speed[0];

        if (b != '2')
            b = speed[0];

        if (osn > 0)
        {
            schet_1--;
            osnova[schet_1][schet_2] = ' ';
            osnova[schet_1 + 1][schet_2] = ' ';
            osnova[schet_1 + 2][schet_2] = ' ';
            osnova[schet_1 + 1][schet_2 + 1] = ' ';
            schet_1++;
        }

        //// поворот ////
        if (a == '5'
            && osnova[schet_1][schet_2] == ' '
            && osnova[schet_1 + 1][schet_2 - 1] == ' '
            && osnova[schet_1 + 1][schet_2] == ' '
            && osnova[schet_1 + 1][schet_2 + 1] == ' '
            )
        {
            Show_polkrest(schet_1, schet_2);
            break;
        }
        /////////////////

        // в право
        for (int i = 0; (speed[i] == '6') && (i < gor); i++)
        {
            if (osnova[schet_1][schet_2 + 1] == 2 || osnova[schet_1 + 1][schet_2 + 2] == 2 || osnova[schet_1 + 2][schet_2 + 1] == 2)
                break;
            schet_2++;
            a = ' ';
            b = ' ';
        }

        // в лево
        for (int i = 0; (speed[i] == '4') && (i < gor); i++)
        {
            if (osnova[schet_1][schet_2 - 1] == 2 || osnova[schet_1 + 1][schet_2 - 1] == 2 || osnova[schet_1 + 2][schet_2 - 1] == 2)
                break;
            schet_2--;
            a = ' ';
            b = ' ';
        }
        /////////////////////////////////
        osnova[schet_1][schet_2] = 2;
        osnova[schet_1 + 1][schet_2] = 2;
        osnova[schet_1 + 2][schet_2] = 2;
        osnova[schet_1 + 1][schet_2 + 1] = 2;

        if (osnova[schet_1 + 3][schet_2] == 2 || osnova[schet_1 + 2][schet_2 + 1] == 2)break;

        schet_1++;

        // пауза
        if (a == '0')
            a = Pause(a);

        // Вывод массива
        Vosnova();

        // в низ
        // задержка
        if (b == '2')
            Delay(0.01);
        else
            Delay(skorost);

        // чистка //
        for (int i = 0; i < gor / 2; i++)
            speed[i] = ' ';

        a = ' ';

        system("CLS");
    }
    //....................//

    // Проверка на полную строку //
    och_int += Yes();
    //....................//

    // Проверка очков на прохождение уровня //
    Lavel(och_int);
    //....................//

    delete[] speed;
}
