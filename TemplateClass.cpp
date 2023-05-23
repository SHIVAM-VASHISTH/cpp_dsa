#include <iostream>
using namespace std;

template <class T>
class Arithmetic
{
private:
    T a;
    T b;

public:
    Arithmetic(T a, T b);
    T add();
    T sub();
};

template <class T>
Arithmetic<T>::Arithmetic(T a, T b)
{
    this->a = a;
    this->b = b;
}

template <class T>
T Arithmetic<T>::add()
{
    return this->a + this->b;
}

template <class T>
T Arithmetic<T>::sub()
{
    return this->a - this->b;
}

int main()
{
    int a = 'A';
    int b = 'B';
    cout << a << endl;
    cout << b << endl;
    char c = a + b;
    cout << (int)c << endl;
    Arithmetic<char> ar('A', 'B');

    cout << "Add " << (int) ar.add() << endl;
    cout << "Sub " << (int) ar.sub() << endl;
    return 0;
}