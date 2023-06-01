#include <iostream>
using namespace std;

int fact(int n)
{
    if (n == 0)
        return 1;
    return fact(n - 1) * n;
}

int iFact(int n)
{
    int r = 1;
    for (int i = 1; i <= n; i++)
    {
        r *= i;
    }
    return r;
}

int main()
{
    cout << fact(6) << endl;
    cout << iFact(6) << endl;
    return 0;
}