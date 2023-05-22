#include <iostream>
using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    int a = 10, b = 20;
    cout << "a - " << a << ", "
         << "b - " << b << endl;
    cout << "--------------" << endl;
    swap(&a, &b);
    cout << "a - " << a << ", "
         << "b - " << b << endl;
    return 0;
}