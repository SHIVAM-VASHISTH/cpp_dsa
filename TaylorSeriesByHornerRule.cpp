#include <iostream>
using namespace std;

double eIteration(int x, int n)
{
    double s = 1;
    while (n > 0)
    {
        s = 1 + x * s / n;
        n--;
    };

    return s;
}

double eRecursion(int x, int n)
{
    static double s = 1;
    if (n == 0)
        return s;

    s = 1 + x * s / n;
    return eRecursion(x, n - 1);
}

int main()
{
    cout << eIteration(1, 10) << endl;
    cout << eRecursion(1, 10) << endl;
    return 0;
}