#include <iostream>
#include <climits>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
Node HT[10];
int hashfunction(int key)
{
    return key % 10;
}
void Insert(int key)
{
    int index = hashfunction(key);
    if (HT[index].data == INT_MIN)
    {
        HT[index].data = key;
    }
    else
    {
        Node *temp = new Node;
        temp->data = key;
        temp->next = NULL;
        Node *cur = HT[index].next;
        if (cur == NULL)
        {
            HT[index].next = temp;
        }
        else
        {
            while ((cur->next) != NULL)
            {
                cur = cur->next;
            }
            cur->next = temp;
        }
    }
}
void Search(int key)
{
    int index = hashfunction(key);
    if (HT[index].data != INT_MIN)
    {
        if (HT[index].data == key)
        {
            cout << key << " found at index " << index << endl;
        }
        else
        {
            Node *cur = HT[index].next;
            while(cur != NULL)
            {
                if (cur->data == key)
                {
                    cout << key << " found at index " << index << endl;
                }
                cur = cur->next;
            }
        }
    }
}
void Display()
{
    for (int i = 0; i < 10; i++)
    {
        cout << i << ": ";
        if (HT[i].data != INT_MIN)
        {
            cout << HT[i].data;
            Node *cur = HT[i].next;
            while (cur != NULL)
            {
                cout << " -> " << cur->data;
                cur = cur->next;
            }
        }
        cout << endl;
    }
}
int main()
{
    for (int i = 0; i < 10; i++)
    {
        HT[i].data = INT_MIN;
    }
    int choice, key;
    bool start = true;
    while (start)
    {
        cout << "\n1. Insert";
        cout << "\n2. Search";

        cout << "\n3. Display";
        cout << "\n4. Exit";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Insert: ";
            cin >> key;
            Insert(key);
            break;
        case 2:
            cout << "Search: ";
            cin >> key;
            Search(key);
            break;

        case 3:
            Display();
            break;
        case 4:
            cout << "Exit";
            start = false; // to stop loop
            break;
        default:
            cout << "Invalid";
            break;
        }
    }
    // insert(75);
    // insert(23);
    // insert(79);
    // insert(113);
    // insert(88);
    // insert(123);
    // insert(153);
    // insert(233);
    // search(113);
    return 0;
}