#include<iostream>
using namespace std;

void fun1(int *A, int n)
{
    A[0] = 15;
}

int * fun2(int size) {
    int *p = new int[size];
    for (int i = 0; i < size; i++) p[i] = i + 1;
    return p;
}

int main()
{
    int A[] = { 2, 4, 6, 8 , 10 };
    int n = 5;
    fun1(A, n);
    for (int x : A) cout << "x - " << x << endl;

    cout << "---------" << endl;

    int *ptr, sz = 5;
    ptr = fun2(sz);
    for (int i = 0; i < sz; i++) cout << "i - " << ptr[i] << endl;

    return 0;
}