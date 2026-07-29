#include <iostream>
using namespace std;

void recursiveSelectionSort(int arr[], int start, int n)
{
    // Base case
    if (start >= n - 1)
        return;

    // Find index of minimum element
    int minIndex = start;

    for (int i = start + 1; i < n; i++)
    {
        if (arr[i] < arr[minIndex])
        {
            minIndex = i;
        }
    }

    // Swap minimum element with current position
    swap(arr[start], arr[minIndex]);

    // Recursively sort remaining array
    recursiveSelectionSort(arr, start + 1, n);
}
void selectionsort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int smallest = i;

        for (int j = i + 1; j < n; j++)
        {

            if (arr[j] < arr[smallest])
                smallest = j;
        }
        // swap
        int temp = arr[smallest];
        arr[smallest] = arr[i];
        arr[i] = temp;
    }
}
int main()
{
    int arr[5] = {5, 7, 4, 3, 1};

    cout<<"-------Selection Sort---------"<<endl;
    selectionsort(arr, 5);
    cout << "sorted array" << endl;
    for (int k = 0; k < 5; k++)
    {
        cout << arr[k] << ",";
    }
    cout<<endl;
    cout<<"-------Recursive Selection Sort---------"<<endl;
    recursiveSelectionSort(arr, 0, 5);
    cout << "sorted array" << endl;
    for (int k = 0; k < 5; k++)
    {
        cout << arr[k] << ",";
    }
}