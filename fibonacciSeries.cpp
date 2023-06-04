#include <iostream>
using namespace std;

int fibUsingIteration(int n)
{
    int t0 = 0, t1 = 1, sum = 0;
    if (n <= 1)
        return n;

    for (int i = 2; i <= n; i++)
    {
        sum = t0 + t1;
        t0 = t1;
        t1 = sum;
    }

    return sum;
}

int fibUsingRecursion(int n)
{
    if (n <= 1)
        return n;
    return fibUsingRecursion(n - 2) + fibUsingRecursion(n - 1);
}

int F[10];

int fibUsingMemoization(int n)
{
    if (n <= 1)
    {
        F[n] = n;
        return F[n];
    }
    else
    {
        if (F[n - 2] == -1)
            F[n - 2] = fibUsingMemoization(n - 2);
        if (F[n - 1] == -1)
            F[n - 1] = fibUsingMemoization(n - 1);
        F[n] = F[n - 2] + F[n - 1];
        return F[n];
    }
}

int main()
{
    for (int i = 0; i <= 10; i++)
        F[i] = -1;

    cout << fibUsingIteration(7) << endl;
    cout << fibUsingRecursion(7) << endl;
    cout << fibUsingMemoization(6) << endl;
    return 0;
}