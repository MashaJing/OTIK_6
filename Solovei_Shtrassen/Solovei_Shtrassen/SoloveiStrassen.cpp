#include "SoloveiStrassen.h"

/* Этот алгоритм рекурсивно вычисляет символ Якоби */
int SoloveiStrassen:: Jacobi(int a, int b)
{
    int g;
    assert(odd(b));
    if (a >= b)
        a %= b;
    if (a == 0)
        return 0;
    if (a == 1)
        return 1;

    if (a < 0)
        if (((b - 1) / 2 )% 2 == 0)
            return Jacobi(-a, b);
        else
            return -Jacobi(-a, b);

    if (a % 2 == 0)
        if (((b * b - 1) / 8) % 2 == 0)
            return +Jacobi(a / 2, b);
        else
            return -Jacobi(a / 2, b);

    g = Euclidean(a, b); // g = НОД (a, b)
    assert(odd(a));
    if (g == a)
        return 0;
    else
        if (g != 1)
            return Jacobi(g, b) * Jacobi(a / g, b);
        else
            if (((a - 1) * (b - 1) / 4) % 2 == 0)
                return +Jacobi(b, a);
            else
                return -Jacobi(b, a);
}

int SoloveiStrassen::Euclidean(int a, int b)
{
    while (a != 0 && b != 0)
    {
        if (a > b) a %= b;
        else  b %= a;
    }
        return a + b;
}

bool SoloveiStrassen::Is_simple(int n)
{
    n = abs(n);
    if (n == 0 || n == 1 || n == 2) return true;
    if (n % 2 == 0) return false;
  
    /*1.	Выбираем случайное число a из интервала [1; n–1].*/
    int a = 1 + rand()%(n - 1);
    if (n >= 5)
    {
        a = 1 + rand() % 4;
    }
    
    /*2.	Проверяем с помощью алгоритма Евклида условие НОД (a, n) = 1. Если оно не выполняется, то n – составное.*/
    
    if (Euclidean(a, n) != 1) return false;
    /*3.	Проверяем выполнимость сравнения (2). Если оно не выполняется, то n – составное.
    Если сравнение выполнено, то ответ неизвестен (и тест можно повторить еще раз). */
    int j;
    
    int temp = a;

    for (int i = 0; i < (n - 1) / 2 - 1; i++)
    {
        a *= temp;
    }
   
    //if (a == 0) { a = 1;  }
    j = Jacobi(a, n);
    if (mod(a, n) == mod(j, n)) return true;

    return false;
}

bool odd(int b)
{
    return (b % 2 == 0 ? false : true);
}

int mod(int a, int b)
{
    if ((a > 0) && (b > 0)) return a % b;
    if ((a > 0) && (b < 0)) return -(abs(b) - (a % abs(b)));
    if ((a < 0) && (b > 0)) return b - abs(a) % b;
    if ((a < 0) && (b < 0)) return a % b;
}