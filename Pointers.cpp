#include<iostream>
using namespace std;

int main()
{
    int *p;
    p = (int *) malloc(5 * sizeof(int)); //C Method to create an array in heap
    p = new int[5]; //C++ Method to create an array in heap
    p[0] = 10; p[1] = 15; p[2] = 20; p[3] = 25; p[4] = 30;
    
    for (int i = 0; i < 5; i++) cout << p[i] << endl;

    delete []p; //Deallocating the memory that is created in heap C++
    free(p); //Deallocating the memory that is created in heap C
    return 0;
}