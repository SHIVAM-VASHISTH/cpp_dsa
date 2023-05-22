#include <iostream>
using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

int main()
{
    struct Rectangle *p = (struct Rectangle *)malloc(sizeof(struct Rectangle)); // C method
    p = new Rectangle();                                                        // C++ method

    p->length = 15;
    p->breadth = 7;

    cout << p->length << endl
         << p->breadth << endl;
    return 0;
}