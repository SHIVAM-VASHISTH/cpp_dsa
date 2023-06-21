#include <iostream>
using namespace std;

void fun()
{
    int size;
    cin >> size;
    int y[size];

    for (int i = 0; i < size; i++) cout << y[i] << " ";
}

int main()

{
    fun();
    return 0;
}