#include <iostream>
using namespace std;

#define size 10
int arr[size];

int Partition(int L, int R)
{
    int pivot = arr[R];
    int i = L - 1;

    for (int j = L; j < R; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // place pivot at correct position
    int temp = arr[i + 1];
    arr[i + 1] = arr[R];
    arr[R] = temp;

    return i + 1;
}

void QuickSort(int L, int R)
{
    if (L < R)
    {
        int pivot = Partition(L, R);
        QuickSort(L, pivot - 1);
        QuickSort(pivot + 1, R);
    }
}

int main()
{
    cout << "Enter array elements" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << "Original array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    QuickSort(0, size - 1);

    cout << "\nSorted array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}