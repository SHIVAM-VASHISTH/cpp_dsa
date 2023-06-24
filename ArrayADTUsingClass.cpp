#include <iostream>
using namespace std;

class Array
{
private:
    int *A;
    int size;
    int length;
    void swap(int *x, int *y);

public:
    Array()
    {
        size = 10;
        length = 0;
        A = new int[size];
    }

    Array(int sz)
    {
        size = sz;
        length = 0;
        A = new int[size];
    }

    ~Array()
    {
        delete[] A;
    }

    void display();

    void append(int x);

    void insert(int index, int x);

    int linearSearch(int key);

    int deleteElement(int index);

    int get(int index);

    void set(int index, int x);

    int max();

    int min();

    int sum();

    float avg();

    void reverse();

    void reverse2();

    void insertSort(int x);

    int isSorted();

    void rearrange();

    Array *merge(Array *arr2);

    Array *arrayUnion(Array *arr2);

    Array *arrayIntersection(Array *arr2);

    Array *arrayDifference(Array *arr2);
};

void Array::display()
{
    int i;
    printf("Elements are : ");
    for (i = 0; i < length; i++)
        printf("%d ", A[i]);

    printf("\n");
}

void Array::append(int x)
{
    if (length < size)
        A[length++] = x;
}

void Array::insert(int index, int x)
{
    if (index < 0 || index > length)
        return;

    int i;

    for (i = length; i > index; i--)
        A[i] = A[i - 1];

    A[index] = x;
    length++;
}

int Array::linearSearch(int key)
{
    for (int i = 0; i < length; i++)
    {
        if (A[i] == key)
        {
            swap(&A[i], &A[i - 1]);
            return i;
        }
    }

    return -1;
}

int Array::get(int index)
{
    if (index < 0 || index >= length)
        return -1;
    return A[index];
}

void Array::set(int index, int x)
{
    if (index < 0 || index >= length)
        return;
    A[index] = x;
}

int Array::max()
{
    int max = A[0];

    for (int i = 1; i < length; i++)
        if (A[i] > max)
            max = A[i];

    return max;
}

int Array::min()
{
    int min = A[0];

    for (int i = 1; i < length; i++)
        if (A[i] < min)
            min = A[i];

    return min;
}

int Array::sum()
{
    int sum = 0;

    for (int i = 0; i < length; i++)
        sum += A[i];

    return sum;
}

float Array::avg()
{
    int sum = 0;

    for (int i = 0; i < length; i++)
        sum += A[i];

    return sum / length;
}

void Array::reverse()
{
    int *B;
    int i, j;

    B = new int[length];

    for (int i = 0, j = length - 1; i < length; i++, j--)
        B[j] = A[i];

    for (int i = 0; i < length; i++)
        A[i] = B[i];
}

void Array::reverse2()
{
    int i = 0, j = length - 1;

    while (i < j)
    {
        swap(&A[i], &A[j]);
        i++;
        j--;
    }
}

void Array::insertSort(int x)
{
    if (length == size)
        return;

    int i;

    for (i = length - 1; i >= 0; i--)
    {
        if (A[i] > x)
            A[i + 1] = A[i];
        else
            break;
    }

    A[i + 1] = x;
    length++;
}

int Array::isSorted()
{
    for (int i = 0; i < length - 1; i++)
    {
        if (A[i] > A[i + 1])
            return 0;
    }
    return 1;
}

void Array::rearrange()
{
    int i = 0, j = length - 1;

    while (i < j)
    {
        while (A[i] < 0)
            i++;

        while (A[j] >= 0)
            j--;

        if (i < j)
            swap(&A[i], &A[j]);
    }
}

Array *Array::merge(Array *arr2)
{
    int i, j, k = 0;

    Array *arr3 = new Array();

    while (i < length && j < arr2->length)
    {
        if (A[i] < arr2->A[j])
            arr3->A[k++] = A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    }

    for (; i < length; i++)
        arr3->A[k++] = A[i];

    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];

    arr3->length = length + arr2->length;
    arr3->size = 10;
    return arr3;
}

Array *Array::arrayUnion(Array *arr2)
{
    int i, j, k = 0;

    Array *arr3 = new Array();

    while (i < length && j < arr2->length)
    {
        if (A[i] < arr2->A[j])
            arr3->A[k++] = A[i++];
        else if (A[i] > arr2->A[j])
            arr3->A[k++] = arr2->A[j++];
        else
        {
            arr3->A[k++] = A[i];
            i++;
            j++;
        }
    }

    for (; i < length; i++)
        arr3->A[k++] = A[i];

    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];

    arr3->length = k;
    arr3->size = size + arr2->size;

    return arr3;
}

Array *Array::arrayIntersection(Array *arr2)
{
    int i, j, k = 0;

    Array *arr3 = new Array();

    while (i < length && j < arr2->length)
    {
        if (A[i] < arr2->A[j])
            i++;
        else if (A[i] > arr2->A[j])
            j++;
        else
        {
            arr3->A[k++] = A[i];
            i++;
            j++;
        }
    }

    arr3->length = k;
    arr3->size = size + arr2->size;

    return arr3;
}

Array *Array::arrayDifference(Array *arr2)
{
    int i, j, k = 0;

    Array *arr3 = new Array();

    while (i < length && j < arr2->length)
    {
        if (A[i] < arr2->A[j])
            arr3->A[k++] = A[i++];
        else if (A[i] > arr2->A[j])
            j++;
        else
        {
            i++;
            j++;
        }
    }

    for (; i < length; i++)
        arr3->A[k++] = A[i];

    arr3->length = k;
    arr3->size = size + arr2->size;

    return arr3;
}

void Array::swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int Array::deleteElement(int index)
{
    int x = 0;
    if (index < 0 || index >= length)
        return x;

    x = A[index];
    for (int i = index; i < length - 1; i++)
        A[i] = A[i + 1];

    length--;

    return x;
}

int main()
{
    Array *arr1;
    int ch, sz, x, index;

    printf("Enter Size of Array : ");
    scanf("%d", &sz);
    arr1 = new Array(sz);

    do
    {

        printf("Menu\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Sum\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter an element and index : ");
            scanf("%d%d", &x, &index);
            arr1->insert(index, x);
            break;

        case 2:
            printf("Enter index : ");
            scanf("%d", &index);
            x = arr1->deleteElement(index);
            printf("Deleted Element is %d\n", x);
            break;

        case 3:
            printf("Enter element to search : ");
            scanf("%d", &x);
            index = arr1->linearSearch(x);
            printf("Element index %d", index);
            break;

        case 4:
            printf("Sum is %d\n", arr1->sum());
            break;

        case 5:
            arr1->display();
        }
    } while (ch < 6);

    return 0;
}