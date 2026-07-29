#include <iostream>
using namespace std;
#define max 100
int heap[max];
int size = 0;

// max insert
void insert(int val)
{

    heap[size] = val;//99
    int i = size;//3
    size++;//4

    // heapifyup
    while (i > 0 && heap[(i - 1) / 2] < heap[i])
    {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// min insert
void MinInsert(int val)
{
    heap[size] = val;
    int i = size;
    size++;

    // heapifyup
    while (i > 0 && heap[(i - 1) / 2] > heap[i])
    {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Delete
void del()
{
    if (size == 0)
    {
        cout << "heap is empty";
        return;
    }

    // replace root with last element
    heap[0] = heap[size - 1];
    size--;
    int i = 0;
    while (2 * i + 1 < size)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        int largest = left;

        if (right < size && heap[right] > heap[left])
        {
            largest = right;
        }

        if (heap[i] >= heap[largest])
        {
            break;
        }

        swap(heap[i], heap[largest]);
        i = largest;
    }
}
void heapifyDown(int i, int n) // i=0, n=size
{
    while (2 * i + 1 < n)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        int largest = left;

        if (right < n && heap[right] > heap[left])
        {
            largest = right;
        }

        if (heap[i] >= heap[largest])
        {
            break;
        }

        swap(heap[i], heap[largest]);
        i = largest;
    }
}
void heapifyDownMin(int i, int n) // i=0, n=size
{
    while (2 * i + 1 < n)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        int smallest = left;

        if (right < n && heap[right] < heap[left])
        {
            smallest = right;
        }

        if (heap[i] <= heap[smallest])
        {
            break;
        }

        swap(heap[i], heap[smallest]);
        i = smallest;
    }
}
void heapsortmax() // Ascending
{

    // build max heap
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapifyDown(i, size);
    }
    for (int i = size - 1; i > 0; i--)
    {
        swap(heap[0], heap[i]);
        heapifyDown(0, i);
    }
}
void heapsortmin() // Descending
{

    // build min heap
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapifyDownMin(i, size);
    }
    for (int i = size - 1; i > 0; i--)
    {
        swap(heap[0], heap[i]);
        heapifyDownMin(0, i);
    }
}

void display()
{

    if (size == 0)
    {
        cout << "Heap is empty\n";
        return;
    }
    for (int i = 0; i < size; i++)
    {
        cout << heap[i] << " ";
        cout << endl;
    }
}
void disLevelByLevel()
{
    int count = 1;
    int printed = 0;

    for (int i = 0; i < size; i++)
    {
        cout << heap[i] << " ";
        printed++; // 1

        if (printed == count)
        {
            cout << endl;
            count = count * 2;
            printed = 0;
        }
    }
}
int main()
{
    int choice, val;
    bool start = true;

    while (start)
    {
        cout << "\n====== HEAP MENU ======\n";
        cout << "1. Insert (Max Heap)\n";
        cout << "2. Insert (Min Heap)\n";
        cout << "3. Delete Root\n";
        cout << "4. Display Heap\n";
        cout << "5. Display Level-wise\n";
        cout << "6. Heap Sort\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            insert(val);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> val;
            MinInsert(val);
            break;

        case 3:
            del();
            break;

        case 4:
            display();
            break;

        case 5:
            disLevelByLevel();
            break;

        case 6:
            cout << "Before Sorting:\n";
            display();

            heapsortmax();

            cout << "After Heap Sort:\n";
            display();
            break;

        case 7:
            cout << "Exiting...\n";
            start = false;
            break;

        default:
            cout << "Invalid choice\n";
        }
    }

    return 0;
}
