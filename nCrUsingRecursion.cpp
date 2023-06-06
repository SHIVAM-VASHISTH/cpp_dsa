#include <iostream>
using namespace std;

int factUsingPascalTriangle(int n, int r)
{
    if (r == 0 || n == r)
        return 1;
    return factUsingPascalTriangle(n - 1, r - 1) + factUsingPascalTriangle(n - 1, r);
}

int fact(int n)
{
    if (n < 1)
        return 1;
    return fact(n - 1) * n;
}

int nCr(int n, int r)
{
    int num = fact(n);
    int den = fact(r) * fact(n - r);
    return num / den;
}

int main()
{
    cout << factUsingPascalTriangle(5, 3) << endl;
    cout << nCr(5, 3) << endl;
    return 0;
}