#include <iostream>
using namespace std;

int expo(int m, int n)
{
    if (n == 0)
        return 1;
    return expo(m, n - 1) * m;
}

int expoOptimized(int m, int n)
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
        return expoOptimized(m * m, n / 2);
    else
        return m * expoOptimized((m * m), (n - 1) / 2);
}

int main()
{
    cout << expo(2, 9) << endl;
    cout << expoOptimized(2, 9) << endl;
    return 0;
}