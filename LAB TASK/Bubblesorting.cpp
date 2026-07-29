#include <iostream>
using namespace std;
void Recursivebubblesort(int arr[], int n)
{
    if (n == 1)
    {
        return;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }

    Recursivebubblesort(arr, n - 1);
}
void Bubblesort(int arr[], int n)
{
    for (int i = 0; i < 5; i++)
    {
        bool flag = false;
        for (int j = 0; j < 5 - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = true;
            }
        }
        if (i == 0 && flag == false)
        {
            cout << "Already sorted" << endl;
            flag = true;
            break;
        }
    }
}

int main()
{
    int arr[5] = {10, 45, 34, 88, 60};

    cout << "-------Bubblesort------" << endl;
    Bubblesort(arr, 5);
    cout << "Sorted array" << endl;
    for (int k = 0; k < 5; k++)
    {

        cout << arr[k] << ",";
    }
    cout<<endl;
    cout << "-------Recursive BubbleSort------" << endl;
    Recursivebubblesort(arr, 5);

    cout << "Sorted array" << endl;
    for (int k = 0; k < 5; k++)
    {

        cout << arr[k] << ",";
    }
    return 0;
}
