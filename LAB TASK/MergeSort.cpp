#include <iostream>
using namespace std;
void merge(int arr[], int left, int mid, int right)
{
    int n = right - left + 1;
    int temp[n];

    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left, k = 0; i <= right; i++, k++)
    {
        arr[i] = temp[k];
    }
}

void mergesort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergesort(arr, left, mid);      // left
        mergesort(arr, mid + 1, right); // right
        merge(arr, left, mid, right);
    }
}
int main()
{
    int arr[] = {2, 3, 8, 7, 6, 4, 5};
    int size = 7;
    mergesort(arr, 0, size - 1);

    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    return 0;
}