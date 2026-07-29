#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node *pre;
};
Node *head = NULL; // Global Declaration

// InsertAtEnd
void insert(int value)
{
    Node *temp = new Node; // 1st memory allocation
    temp->data = value;
    temp->next = NULL;
    temp->pre = NULL;

    if (head == NULL)
    {
        // temp->pre=NULL;
        head = temp;
        return;
    }

    // duplicate check
    Node *cur = head;
    while (cur != NULL)
    {
        if (cur->data == value)
        {
            cout << "duplicates not allowed" << endl;
            delete temp;
            return;
        }
        cur = cur->next;
    }
    cur = head;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = temp;
    temp->pre = cur;
}

// Bubble sorting
void sort()
{
    if (head == NULL)
    {
        cout << "list is empty" << endl;
        return;
    }
    bool swaped;
    do
    {
        swaped = false;
        Node *temp = head;
        while (temp->next != NULL)
        {
            if (temp->data > temp->next->data)
            {
                // swap
                int t = temp->data;
                temp->data = temp->next->data;
                temp->next->data = t;
                swaped = true;
            }
            temp = temp->next;
        }
    } while (swaped);
}

// DisplayForward
void display()
{
    if (head == NULL)
    {
        cout << "Linked List is empty\n";
        return;
    }

    Node *temp = head;
    cout << "Linked List: ";
    while (temp != NULL)
    {
        cout << temp->data << " -><-";
        temp = temp->next;
    }
    cout << "NULL\n";
}
// DisplayBackward
void displayBackward()
{
    if (head == NULL)
    {
        cout << "List is empty";
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    while (temp != NULL)
    {
        cout << temp->data << "-><-";
        temp = temp->pre;
    }
    cout << "NULL\n";
}
// Search
void search(int value)
{
    if (head == NULL)
    {
        cout << "List is empty";
        return;
    }
    int pos = 1;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            cout << "\n"
                 << temp->data << " found at positon  " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Not found";
}
// Delete
void deleteNode(int value)
{
    if (head == NULL)
    {
        cout << "Lsit is empty";
        return;
    }
    Node *cur = head;
    // for head deletion
    if (head->data == value)
    {
        head = head->next; // move head to next
        if (head != NULL)
        {                     // if new head exist
            head->pre = NULL; // remove old head previous link
        }
        delete (cur);
        cout << "deleted" << endl;
        return;
    }
    // for middle or last deletion
    cur = head;
    while (cur != NULL)
    {
        if (cur->data == value)
        {
            cur->pre->next = cur->next;
            if (cur->next != NULL)
            {
                cur->next->pre = cur->pre; // 20<->30<->40<->NULL
            }
            delete (cur);
            cout << "deleted" << endl;
            return;
        }
        cur = cur->next;
    }
    cout << "Not Found" << endl;
}
int findMin()
{
    if (head == NULL)
    {
        return -1;
    }
    int MinVal = head->data;
    Node *temp = head->next;
    while (temp != NULL)
    {
        if (temp->data < MinVal)
        {
            MinVal = temp->data;
        }
        temp = temp->next;
    }
    cout << MinVal;
    return MinVal;
}
int findMax()
{
    if (head == NULL)
    {
        return -1;
    }
    int MaxVal = head->data;
    Node *temp = head->next;
    while (temp != NULL)
    {
        if (temp->data > MaxVal)
        {
            MaxVal = temp->data;
        }
        temp = temp->next;
    }
    cout << "\n"
         << MaxVal << endl;
    return MaxVal;
}
// reverse the list
void reverse()
{
    Node *pre = NULL;
    Node *cur = head;
    Node *next = NULL;

    while (cur != NULL)
    {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
        head = pre;
    }
}
// find middle of the list
Node *middle()
{
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
// copy the list and reverse
Node *CopyReverse()
{
    Node *temp = head;
    Node *newHead = NULL;
    if (head == NULL)
    {
        return NULL;
    }
    while (temp != NULL)
    {
        Node *newNode = new Node;
        newNode->data = temp->data;
        newNode->next = newHead;
        newHead = newNode;

        temp = temp->next;
    }
    return newHead;
}
void displayCopied(Node *newhead)
{
    if (newhead == NULL)
    {
        cout << "Copied list is empty\n";
        return;
    }

    Node *temp = newhead;

    cout << "Copied Reversed List: ";
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}
int main()
{
    //  int choice , value;
    //  bool start=true;
    //  while (start)
    // {
    //     cout << "\n1. Insert";
    //     cout << "\n2. Display";
    //     cout << "\n3. Search";
    //     cout << "\n4. Delete";
    //     cout << "\n5. Exit";
    //     cout << "\nEnter choice: ";
    //     cin >> choice;

    //     switch (choice)
    //     {
    //     case 1:
    //         cout << "Value: ";
    //         cin >> value;
    //         insert(value);
    //         break;
    //     case 2:
    //         display();
    //         break;
    //     case 3:
    //         cout << "Value: ";
    //         cin >> value;
    //         search(value);
    //         break;
    //     case 4:
    //         cout << "Value: ";
    //         cin >> value;
    //         deleteNode(value);
    //         break;
    //     case 5:
    //         cout << "Exit";
    //         start=false;              //to stop loop
    //         break;
    //     default:
    //         cout << "Invalid";
    //         break;
    //     }
    // }
    insert(50);
    insert(20);
    insert(10);
    insert(30);
    insert(40);
    display();
    Node *mid = middle();
    cout << "middle element" << mid->data;

    // sort();
    // display();
    // findMin();
    // findMax();
    // //reverse();
    // display();
    // Node* newhead=CopyReverse();
    // displayCopied(newhead);

    // displayBackward();
    // search(20);
    // deleteNode(10);
    // deleteNode(20);
    // deleteNode(30);
    // deleteNode(40);
    // display();
    return 0;
}