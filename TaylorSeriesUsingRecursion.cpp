#include <iostream>
using namespace std;

double e(int x, int n)
{
    static double p = 1, f = 1;
    double result;
    if (n == 0)
        return 1;
    result = e(x, n - 1);
    p *= x;
    f *= n;
    return result + p / f;
}

int main()
{
    cout << e(4, 15) << endl;
    return 0;
}