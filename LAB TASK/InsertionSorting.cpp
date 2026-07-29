#include <iostream>
using namespace std;
void RecursiveInsertionSort(int arr[],int n){
    if(n<=1){
        return;
    }
    RecursiveInsertionSort(arr,n-1);
    int last=arr[n-1];
    int j=n-2;
    while(j>=0 && arr[j]>last){
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=last;
    
}
void Insertionsort(int arr[],int n){
     for (int i = 1; i < 7; i++)
    {
        int current = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > current)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }
}
int main()
{
    int arr[7] = {5, 6, 8, 2, 4, 1, 3};
   
     cout<<"------Insertion Sort--------"<<endl;
    Insertionsort(arr,7);
    for (int k = 0; k < 7; k++)
    {
        cout << arr[k] << ",";
    }
    cout<<endl;
    cout<<"------Recursive Insertion Sort--------"<<endl;
    RecursiveInsertionSort(arr,7);
    for (int k = 0; k < 7; k++)
    {
        cout << arr[k] << ",";
    }
}