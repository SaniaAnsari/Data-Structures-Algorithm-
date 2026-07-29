#include <iostream>
#include <climits>
using namespace std;
#define size 11
int hashtable[size];
int hashfunction(int key)
{
    return key % size;
}
// double hashing
void doubleInsert(int key)
{
    int h1 = key % size;
    int h2 = 7 - (key % 7);
    int i = 0;

    while (hashtable[(h1 + i * h2) % size] != INT_MIN)
    {
        i++;
    }
    hashtable[(h1 + i * h2) % size] = key;
    cout<< "Inserted "<< key << " at index " <<(h1 + i * h2) % size << endl;
}

// insert using linear probing
void LinearInsert(int key)
{
    int index = hashfunction(key);
    int startIndex = index;
    while (hashtable[index] != INT_MIN) // Loop until we find an empty slot
    {
        index = (index + 1) % size; // move to next index
        if (index == startIndex)    // Table is full
        {
            cout << "Hashtable is full cannot insert" << endl;
            return;
        }
    }
    hashtable[index] = key; // Insert key into empty slot
    cout << "Inserted " << key << " at index " << index << endl;
}
// searching using linear probing
void LinearSearch(int key)
{
    int index = hashfunction(key);
    int startIndex = index;
    while (hashtable[index] != INT_MIN)
    {
        if (hashtable[index] == key) // Check if slot is empty
        {
            cout << key << " found at index " << index << endl;
        }
        index = (index + 1) % size; // move to next
        if (index == startIndex)
        {
            cout << "Key" << key << " not found in the hashtable " << endl;
            break;
        }
    }

    return;
}
// delete
void DelLinerly(int val)
{
    int index = hashfunction(val);
    int startindex = index;
    while (hashtable[index] != INT_MIN)
    {
        if (hashtable[index] == val)
        {
            hashtable[index] = INT_MIN;
            cout << "Deleted successfully";
            break;
        }
        index = (index + 1) % size;
        if (index == startindex)
        {
            cout << "Key" << val << " not found in the hashtable " << endl;
            break;
        }
    }
}
// insert using quadratic probing
void QuadraticInsert(int key)
{
    int index = hashfunction(key);
    int i = 0;
    int newIndex = index;

    while (hashtable[newIndex] != INT_MIN)
    {
        i++;           // Increment step
        if (i == size) // Checked all slots, table full
        {
            cout << "hashtable full";
            return;
        }
        newIndex = (index + i * i) % size;
    }
    hashtable[newIndex] = key;
    cout << "Inserted " << key << " at index " << index << endl;
}
// Searching using quadratic probing
void QuadraticSearch(int key)
{
    int index = hashfunction(key);
    int i = 0;
    int newIndex = index;
    while (hashtable[newIndex] != INT_MIN)
    {
        if (hashtable[newIndex] == key)
        {
            cout << key << " found at index " << newIndex << endl;
        }
        i++;
        if (i == size)
        {
            break;
        }
        newIndex = (index + i * i) % size;
    }
}
void Display()
{
    cout << "Hashtable" << endl;
    for (int i = 0; i < size; i++)
    {
        if (hashtable[i] == INT_MAX)
        {
            cout << "hashtable is empty" << endl;
        }
        else
        {
            cout << hashtable[i] << endl;
        }
    }
}
int main()
{
    for (int i = 0; i < size; i++)
    {
        hashtable[i] = INT_MIN;
    }
    // int choice, key;
    // bool start = true;
    // while (start)
    // {
    //     cout << "\n1. LinearInsert";
    //     cout << "\n2. LinearSearch";
    //     cout << "\n3. QuadraticInsert";
    //     cout << "\n4. QuadraticSearch";
    //     cout << "\n5. Display";
    //     cout << "\n6. Exit";

    //     cout << "\nEnter choice: ";
    //     cin >> choice;

    //     switch (choice)
    //     {
    //     case 1:
    //         cout << "LinearInsert: ";
    //         cin >> key;
    //         LinearInsert(key);
    //         break;
    //     case 2:
    //         cout << "LinearSearch: ";
    //         cin >> key;
    //         LinearSearch(key);
    //         break;
    //     case 3:
    //         cout << "QuadraticInsert: ";
    //         cin >> key;
    //         QuadraticInsert(key);
    //         break;
    //     case 4:
    //         cout << "QuadraticSearch: ";
    //         cin >> key;
    //         QuadraticInsert(key);
    //         break;
    //     case 5:
    //         Display();
    //         break;
    //     case 6:
    //         cout << "Exit";
    //         start = false; // to stop loop
    //         break;
    //     default:
    //         cout << "Invalid";
    //         break;
    //     }
    // }

    doubleInsert(25);
    doubleInsert(35);
    doubleInsert(15);
    doubleInsert(45);
    doubleInsert(75);

    // LinearInsert(75);
    // LinearInsert(23);
    // LinearInsert(79);
    // LinearInsert(113);
    // LinearInsert(88);
    // LinearInsert(123);
    // LinearInsert(153);
    // LinearInsert(233);
    Display();
    // DelLinerly(79);
    // Display();
    return 0;
}
