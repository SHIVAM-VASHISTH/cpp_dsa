#include <iostream>
using namespace std;

struct Rectangle
{
    int length;
    int breadth;
    char x;
};

int main()
{
    struct Rectangle r1;
    printf("%lu\n", sizeof(r1));
    return 0;
}