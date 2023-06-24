#include <iostream>
using namespace std;

struct Array
{
    int *A;
    int size;
    int length;
};

void display(struct Array array)
{
    int i;
    printf("Elements are : ");
    for (i = 0; i < array.length; i++)
        printf("%d ", array.A[i]);
    printf("\n");
}

void append(struct Array *arr, int x)
{
    if (arr->length < arr->size)
        arr->A[arr->length++] = x;
}

void insert(struct Array *arr, int index, int x)
{
    if (index < 0 || index > arr->length)
        return;

    int i;

    for (i = arr->length; i > index; i--)
        arr->A[i] = arr->A[i - 1];

    arr->A[index] = x;
    arr->length++;
}

int deleteElement(struct Array *arr, int index)
{
    int x = 0;
    if (index < 0 || index >= arr->length)
        return x;

    x = arr->A[index];
    for (int i = index; i < arr->length - 1; i++)
        arr->A[i] = arr->A[i + 1];

    arr->length--;

    return x;
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int linearSearch(struct Array *arr, int key)
{
    for (int i = 0; i < arr->length; i++)
    {
        if (arr->A[i] == key)
        {
            swap(&arr->A[i], &arr->A[i - 1]);
            return i;
        }
    }

    return -1;
}

int binarySearch(struct Array *arr, int key)
{
    int l = 0, h = arr->length - 1;

    while (l <= h)
    {
        int mid = (l + h) / 2;

        if (arr->A[mid] < key)
            l = mid + 1;
        else if (arr->A[mid] > key)
            h = mid - 1;
        else
            return mid;
    }

    return -1;
}

int binarySearchRecursive(struct Array *arr, int l, int h, int key)
{
    if (l <= h)
    {
        int mid = (l + h) / 2;
        if (arr->A[mid] < key)
            return binarySearchRecursive(arr, mid + 1, h, key);
        else if (arr->A[mid] > key)
            return binarySearchRecursive(arr, l, mid - 1, key);
        else
            return mid;
    }
    return -1;
}

int get(struct Array arr, int index)
{
    if (index < 0 || index >= arr.length)
        return -1;
    return arr.A[index];
}

void set(struct Array *arr, int index, int value)
{
    if (index < 0 || index >= arr->length)
        return;
    arr->A[index] = value;
}

int max(struct Array arr)
{
    int max = arr.A[0];

    for (int i = 1; i < arr.length; i++)
        if (arr.A[i] > max)
            max = arr.A[i];

    return max;
}

int min(struct Array arr)
{
    int min = arr.A[0];

    for (int i = 1; i < arr.length; i++)
        if (arr.A[i] < min)
            min = arr.A[i];

    return min;
}

int sum(struct Array arr)
{
    int sum = 0;

    for (int i = 0; i < arr.length; i++)
        sum += arr.A[i];

    return sum;
}

float avg(struct Array arr)
{
    int sum = 0;

    for (int i = 0; i < arr.length; i++)
        sum += arr.A[i];

    return sum / arr.length;
}

int sumUsingRecursion(int A[], int n)
{
    if (n < 0)
        return 0;

    return sumUsingRecursion(A, n - 1) + A[n];
}

void reverse(struct Array *arr)
{
    int *B;
    int i, j;

    B = (int *)malloc(arr->length * sizeof(int));

    for (int i = 0, j = arr->length - 1; i < arr->length; i++, j--)
    {
        B[j] = arr->A[i];
    }

    for (int i = 0; i < arr->length; i++)
    {
        arr->A[i] = B[i];
    }
}

void reverseSecond(struct Array *arr)
{
    int i = 0, j = arr->length - 1;

    while (i < j)
    {
        swap(arr->A[i], arr->A[j]);
        i++;
        j--;
    }
}

void insertSort(struct Array *arr, int x)
{
    if (arr->length == arr->size)
        return;

    int i;

    for (i = arr->length - 1; i >= 0; i--)
    {
        if (arr->A[i] > x)
            arr->A[i + 1] = arr->A[i];
        else
            break;
    }

    arr->A[i + 1] = x;
    arr->length++;
}

int isSorted(struct Array arr)
{
    for (int i = 0; i < arr.length - 1; i++)
    {
        if (arr.A[i] > arr.A[i + 1])
            return 0;
    }
    return 1;
}

void rearrange(struct Array *arr)
{
    int i = 0, j = arr->length - 1;

    while (i < j)
    {
        while (arr->A[i] < 0)
            i++;

        while (arr->A[j] >= 0)
            j--;

        if (i < j)
            swap(arr->A[i], arr->A[j]);
    }
}

struct Array *merge(struct Array *arr1, struct Array *arr2)
{
    int i, j, k = 0;

    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    }

    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];

    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];

    arr3->length = arr1->length + arr2->length;
    arr3->size = 10;
    return arr3;
}

struct Array *arrayUnion(struct Array *arr1, struct Array *arr2)
{
    int i, j, k = 0;

    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if (arr1->A[i] > arr2->A[j])
            arr3->A[k++] = arr2->A[j++];
        else
        {
            arr3->A[k++] = arr1->A[i];
            i++;
            j++;
        }
    }

    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];

    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];

    arr3->length = k;
    arr3->size = arr1->size + arr2->size;

    return arr3;
}

struct Array *arrayIntersection(struct Array *arr1, struct Array *arr2)
{
    int i, j, k = 0;

    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            i++;
        else if (arr1->A[i] > arr2->A[j])
            j++;
        else
        {
            arr3->A[k++] = arr1->A[i];
            i++;
            j++;
        }
    }

    arr3->length = k;
    arr3->size = arr1->size + arr2->size;

    return arr3;
}

struct Array *arrayDifference(struct Array *arr1, struct Array *arr2)
{
    int i, j, k = 0;

    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if (arr1->A[i] > arr2->A[j])
            j++;
        else
        {
            i++;
            j++;
        }
    }

    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];

    arr3->length = k;
    arr3->size = arr1->size + arr2->size;

    return arr3;
}

int main()
{
    struct Array arr1;
    int ch, x, index;

    printf("Enter Size of Array : ");
    scanf("%d", &arr1.size);
    arr1.A = (int *)malloc(arr1.size * sizeof(int));

    do
    {

        printf("Menu\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Sun\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("enter your choice");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter an element and index : ");
            scanf("%d%d", &x, &index);
            insert(&arr1, index, x);
            break;

        case 2:
            printf("Enter index : ");
            scanf("%d", &index);
            x = deleteElement(&arr1, index);
            printf("Deleted Element is %d\n", x);
            break;

        case 3:
            printf("Enter element to search : ");
            scanf("%d", &x);
            index = linearSearch(&arr1, x);
            printf("Element index %d", index);
            break;

        case 4:
            printf("Sum is %d\n", sum(arr1));
            break;

        case 5:
            display(arr1);
        }
    } while (ch < 6);

    return 0;
}