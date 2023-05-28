#include<iostream>
using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};


int main()
{
    int a1;
    char a2;
    float a3;
    double a4;
    struct Rectangle a5;

    cout << sizeof(a1) << endl;
    cout << sizeof(a2) << endl;
    cout << sizeof(a3) << endl;
    cout << sizeof(a4) << endl;
    cout << sizeof(a5) << endl;

    cout << "-----------------" << endl;

    int *p1;
    char *p2;
    float *p3;
    double *p4;
    struct Rectangle *p5;

    cout << sizeof(p1) << endl;
    cout << sizeof(p2) << endl;
    cout << sizeof(p3) << endl;
    cout << sizeof(p4) << endl;
    cout << sizeof(p5) << endl;
    return 0;
}