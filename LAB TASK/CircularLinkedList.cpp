#include <iostream>
#include <stdlib.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
Node *head = NULL;
// Insert
void insert(int value)
{
    Node *temp = new Node; // create newnode using 'new' keyword

    // // temp=(Node*)malloc(sizeof(Node));
    temp->data = value;
    // temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
        temp->next = head;
    }
    else
    {
        Node *cur = head;
        while (cur->next != head)
        {
            cur = cur->next;
        }
        cur->next = temp;
        temp->next = head;
    }
}
// Display
void display()
{
    if (head == NULL)
    {
        cout << "Linked List is empty\n";
        return;
    }
    cout << "Linked List: " << endl;
    Node *temp = head;
    do
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
}
// Search
void search(int value)
{
    int pos = 1;
    Node *temp = head;
    do
    {
        if (temp->data == value)
        {
            cout << endl
                 << temp->data << " found at positon  " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);
}
// Delete
void deleteNode(int value)
{
    if (head == NULL)
    {
        cout << "linked list is empty" << endl;
        return;
    }
    Node *cur = head;
    if (head->data == value)
    {
        while (cur->next != head)    //traverse the list and go to end 
        {
            cur = cur->next;
        }
        Node *temp = head;
        head = head->next;
        cur->next = head;
        delete temp;
        cout << "Node deleted" << endl;
        return;
    }
    Node *pre = head;
    cur = head->next;
    while (cur != head)
    {
        if (cur->data == value)
        {
            pre->next = cur->next;
            delete cur;
            cout << "Node deleted" << endl;
            return;
        }

        pre = cur;
        cur = cur->next;
    }
    cout << "Not found" << endl;
}

int main()
{
    insert(10);
    insert(20);
    insert(30);
    // cout << "before deletion" << endl;
    display();
    search(20);
    deleteNode(10);
    deleteNode(20);
    deleteNode(30);
    //  cout << "after deletion" << endl;
    display();

    return 0;
}
