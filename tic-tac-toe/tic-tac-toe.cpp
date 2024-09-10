// tic-tac-toe.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdio.h>
#include <string.h> // подрубили токен
#include <stdlib.h>
#include <locale.h>

int board(int table[3][3]);
int game();
int win(int table[3][3], int player);
int input(int table[3][3], int* x, int* y);
int is_number(const char* str);

int main()
{
    setlocale(LC_ALL, "russian");
    game();
    return 0;
}

int board(int table[3][3])
{
    printf("+---+---+---+\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (table[i][j] == 2)
                printf("|   ");
            if (table[i][j] == 0)
                printf("| X ");
            if (table[i][j] == 1)
                printf("| O ");
        }
        printf("| \n");
        printf("+---+---+---+\n");
    }
    return 0;
}

int game()
{
    int table[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            table[i][j] = 2;
    }
    int player, x, y;
    board(table);
    for (int i = 0; i < 9; i++)
    {
        player = i % 2;
        if (player)
            printf("Ходит игрок за нолики\n");
        else
            printf("Ходит игрок на крестики\n");
        printf("Введите кординаты клетки (начало от 0)\n");
        input(table, &x, &y);
        table[x][y] = player;
        if (i == 4)
        {
            if (win(table, player))
            {
                if (player == 1)
                    printf("Победил игрок, за нолик");
                else
                    printf("Победил игрок за крестик\n");
                break;
            }
        }
        board(table);
    }
    return 0;
}

int win(int table[3][3], int player)
{
    if (table[0][0] == player && table[0][1] == player && table[0][2] == player)
        return 1;
    if (table[0][0] == player && table[1][0] == player && table[2][0] == player)
        return 1;
    if (table[2][2] == player && table[1][2] == player && table[0][2] == player)
        return 1;
    if (table[2][0] == player && table[2][1] == player && table[2][2] == player)
        return 1;
    if (table[1][0] == player && table[1][1] == player && table[1][2] == player)
        return 1;
    if (table[2][1] == player && table[1][1] == player && table[0][1] == player)
        return 1;
    if (table[2][2] == player && table[1][1] == player && table[0][0] == player)
        return 1;
    if (table[2][0] == player && table[1][1] == player && table[0][2] == player)
        return 1;
    return 0;
}

int input(int table[3][3], int* x, int* y)
{
    char c[10];
    char* token;
    while (1)
    {
        fgets(c, 10, stdin);

        int len = strlen(c);                                     // удоляем \n ибо он ломает токен и он не видит 0 во второй координате
        if (len > 0 && c[len - 1] == '\n')
            c[len - 1] = '\0';

        token = strtok(c, " ");
        if (token != NULL && is_number(c))
        {
            *x = atoi(token);
            token = strtok(NULL, " ");
        }
        else
        {
            printf("Вы ввели что-то не то, пробуем еще раз\n");
            continue;
        }
        if (token != NULL && is_number(c))
            *y = atoi(token);
        else
        {
            printf("Вы ввели что-то не то, пробуем еще раз\n");
            continue;
        }
        if ((*x <= 2 && *x >= 0) && (*y >= 0 && *y <= 2) && table[*x][*y] == 2)
            return 0;
        else
            printf("Вы ввели что-то не то, пробуем еще раз\n");
    }
}

int is_number(const char* str)
{
    while (*str)
    {
        if (!isdigit(*str))
            return 0;
        str++;
    }
    return 1;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
