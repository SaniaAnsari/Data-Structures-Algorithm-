#include <iostream>
using namespace std;
int main()
{
    int arr[10] = {23, 36, 45, 49, 56, 67, 76, 78, 88, 90};
    int target;
    cout << "enter a target:  ";
    cin >> target;
    int l = 0, r = 9, mid;
    bool flag = false;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (target == arr[mid])
        {
            cout << "Element found at index: " << mid;
            flag = true;
            break;
        }
        if (target > arr[mid])
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    if (flag == false)
    {
        cout << "Not found";
    }
    return 0;
}
