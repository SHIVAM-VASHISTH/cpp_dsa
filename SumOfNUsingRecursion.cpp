#include <iostream>
using namespace std;

int sum(int n)
{
    if (n == 0)
        return 0;
    return sum(n - 1) + n;
}

int iSum(int n)
{
    int s;
    for (int i = 0; i <= n; i++)
    {
        s += i;
    }
    return s;
}

int main()
{
    cout << sum(5) << endl;
    cout << iSum(5) << endl;
    return 0;
}