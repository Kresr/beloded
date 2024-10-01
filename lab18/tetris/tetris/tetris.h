#pragma once
#include <iostream>
#include <string>

class Constractor
{
protected:

    std::string ur;
    std::string och;
    int ur_int;
    int och_int;
    double skorost;
    int level_1;

    char** osnova;
    char** pause;
    char** game_over;
    char** uroven;

    int gor;
    int ver;
public:
    Constractor();
    ~Constractor();

    // фигуры
    // Куб
    void Show_kub();
    // Зигзаг а
    void Show_zig_a(int mesto_1 = 1, int mesto_2 = 7);
    void Show_zig_a_2(int mesto_1 = 1, int mesto_2 = 7);
    // Зигзаг б
    void Show_zig_b(int mesto_1 = 1, int mesto_2 = 7);
    void Show_zig_b_2(int mesto_1 = 1, int mesto_2 = 7);
    // Палка
    void Show_pulka(int mesto_1 = 1, int mesto_2 = 7);
    void Show_pulka_b(int mesto_1 = 1, int mesto_2 = 7);
    // Уголок левый
    void Show_ugoll(int mesto_1 = 1, int mesto_2 = 7);
    void Show_ugoll_b(int mesto_1 = 1, int mesto_2 = 7);
    void Show_ugoll_c(int mesto_1 = 1, int mesto_2 = 7);
    void Show_ugoll_d(int mesto_1 = 1, int mesto_2 = 7);
    // Уголок правый
    void Show_ugolp(int mesto_1 = 1, int mesto_2 = 7);
    void Show_ugolp_b(int mesto_1 = 1, int mesto_2 = 7);
    void Show_ugolp_c(int mesto_1 = 1, int mesto_2 = 7);
    void Show_ugolp_d(int mesto_1 = 1, int mesto_2 = 7);





    // Полукрест
    void Show_polkrest(int mesto_1 = 1, int mesto_2 = 7);
    void Show_polkrest_b(int mesto_1 = 1, int mesto_2 = 7);
    void Show_polkrest_c(int mesto_1 = 1, int mesto_2 = 7);
    void Show_polkrest_d(int mesto_1 = 1, int mesto_2 = 7);

    // методы
    void Delay(double n = 0.9);
    char Pause(char paus);
    int Yes();
    int Lavel(int n);
    void Game_over();
    void Victory();

    // методы вывода
    void Vosnova();
    void Vpause();
    void Vgame_over();
    void Vuroven(int n = 15);
};
