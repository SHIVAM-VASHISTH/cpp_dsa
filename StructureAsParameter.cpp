#include <iostream>
using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

void fun(struct Rectangle *p)
{
    (*p).length++;
    cout << "Length - " << p->length << endl
         << "Breadth - " << p->breadth << endl;
}

struct Rectangle *fun()
{
    struct Rectangle *p = new Rectangle;
    p->length = 15;
    p->breadth = 7;
    return p;
}

int main()
{
    struct Rectangle *ptr = fun();
    printf("Length - %d \nBreadth - %d\n", ptr->length, ptr->breadth);
    return 0;
}