#include <iostream>
#include <stdlib.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
Node *head = NULL;
//Insert at specfic position 
void SpecificPos(int value, int pos){
    Node* newNode= new Node;
    newNode->data=value;
    newNode->next=NULL;

    //postion 1
    if(pos==1){
        newNode->next=head;
        head=newNode;
        return;
    }
    Node* temp=head;
    for(int i=1; i<pos-1 && temp!=NULL; i++){
        temp=temp->next;
    }
    if(temp==NULL){
        cout <<"Invalid position";
        delete newNode;
        return;
    }
    newNode->next=temp->next;
    temp->next=newNode;
}
// sorted insertion
void sortInsert(int value)
{
    Node *temp = new Node;
    temp->data = value;
    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
        return;
    }
    if (value < head->data)
    {
        temp->next = head;
        head = temp;
        return;
    }
    Node *cur = head;
    while (cur->next != NULL && cur->next->data < value)
    {
        cur = cur->next;
    }
    temp->next = cur->next; //10,20
    cur->next = temp;
}

// Insert at end
void insert(int value)
{
    Node *temp = new Node; // create newnode using 'new' keyword

    //temp=(Node*)malloc(sizeof(Node));
    temp->data = value;
    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        Node *cur = head;
        while (cur->next != NULL)
        {
            cur = cur->next;
        }
        cur->next = temp;
    }
}

// Unique Insert
void uniqueInsert(int value)
{
    Node *temp = new Node;
    temp->data = value;
    temp->next = NULL;

    // If list is empty
    if (head == NULL)
    {
        head = temp;
        return;
    }

    // Check for duplicates
    Node *cur = head;
    while (cur != NULL)
    {
        if (cur->data == value)
        {
            cout << "Duplicate not allowed" << endl;
            delete temp; // avoid memory leak
            return;
        }
        cur = cur->next;
    }

    // Insert at the end
    cur = head;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = temp;
}

// Insert at first
void insertatbegin(int value)
{

    Node *cur = head;
    while (cur != NULL)
    {
        if (cur->data == value)
        {
            cout << "duplicate not allowed" << endl;
            // delete(cur);
            return;
        }
        cur = cur->next;
    }
    Node *temp = new Node;
    temp->data = value;
    temp->next = head;
    head = temp;
}

// Display
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
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Display using Recursion
void Recursivedisplay(Node *temp)
{
    if (temp == NULL)
    {
        cout << "NULL";
        return;
    }
    cout << temp->data << "->";

    Recursivedisplay(temp->next);
}
//update
void update(int oldVal, int newVal){
    Node*temp=head;
    while(temp!=NULL){
        if(temp->data==oldVal){
            temp->data=newVal;
            cout<<"Node updated successfully";
            return;
        }
        temp=temp->next;
    }
    cout<<"value not found";
}

// Search
void search(int value)
{
    int pos = 1;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            cout << temp->data << " found at positon  " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
}

// Searching for Multiple Occurrances
void Searching(int value)
{
    bool flag = false;
    int pos = 1;
    Node *temp = head;
    if (head == NULL)
    {
        cout << "Linkedlist is empty" << endl;
        return;
    }
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            flag = true;
            cout << value << " found at position " << pos << endl;
        }
        temp = temp->next;
        pos++;
    }
    if (flag == false)
    {
        cout << "Value not found " << endl;
    }
}

// copy and reverse
Node *copyReverse()
{
    Node *temp = head;

    if (head == NULL)
    {
        cout << "list is empty";
        return NULL;
    }
    Node *newHead = NULL;
    Node *tail = NULL;

    while (temp != NULL)
    {
        Node *newNode = new Node;
        newNode->data = temp->data;
        newNode->next = NULL;

        if (newHead == NULL)
        {
            newHead = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail=newNode ;
        }
        temp = temp->next;
    }
    // reverse
    Node *pre = NULL;
    Node *cur = newHead;
    Node *next = NULL;

    while (cur != NULL)
    {
        next = cur->next;//10 20 30
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}

// Delete
void deleteNode(int value)
{
    if (head == NULL)
    {
        cout << "linked list is empty" << endl;
        return;
    }
    if (head->data == value)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        cout << "Node deleted" << endl;
        return;
    }
    Node *pre = NULL;
    Node *cur = head;
    while (cur != NULL)
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
    // int choice = 0, value;

    // while (choice <= 4)
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
    //         break;
    //     default:
    //         cout << "Invalid";
    //         break;
    //     }
    // }
    // insertatbegin(30);
    // insertatbegin(20);
    // insertatbegin(10);
    // insertatbegin(10);

    uniqueInsert(10);
    uniqueInsert(20);
    // uniqueInsert(20);
    uniqueInsert(30);
    display();
    // Searching(20);
    // Searching(40);
    // cout << "before deletion" << endl;
   // Recursivedisplay(head);
    // search(20);
    // deleteNode(30);
    // cout << "after deletion" << endl;
    // display();
    //copyReverse();
    update(10,15);
    display();

    return 0;
}
