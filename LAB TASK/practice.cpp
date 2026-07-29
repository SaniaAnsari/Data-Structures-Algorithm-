#include <iostream>
using namespace std;

struct Node
{
    int data;
    int index;
    Node *next;
    Node *pre;
};

Node *head = NULL;
Node *tail = NULL;
int count = 0;


// Insert at End
void insert(int value)
{
    Node *temp = new Node;

    temp->data = value;
    temp->index = count++;
    temp->next = NULL;
    temp->pre = NULL;

    if(head == NULL)
    {
        head = tail = temp;
        return;
    }

    tail->next = temp;
    temp->pre = tail;
    tail = temp;
}


// Print Doubly Linked List
void print()
{
    Node *cur = head;

    while(cur != NULL)
    {
        cout << "Index: " << cur->index 
             << " Data: " << cur->data << endl;

        cur = cur->next;
    }
}


// Partition for Quick Sort
Node* Partition(Node *low, Node *high)
{
    int pivot = high->data;

    Node *i = low->pre;


    for(Node *j = low; j != high; j = j->next)
    {
        if(j->data <= pivot)
        {
            if(i == NULL)
                i = low;
            else
                i = i->next;


            // Swap data
            int temp = i->data;
            i->data = j->data;
            j->data = temp;
        }
    }


    if(i == NULL)
        i = low;
    else
        i = i->next;


    // Swap pivot
    int temp = i->data;
    i->data = high->data;
    high->data = temp;


    return i;
}


// Quick Sort
void QuickSort(Node *low, Node *high)
{
    if(high != NULL && low != high && low != high->next)
    {
        Node *pivot = Partition(low, high);

        QuickSort(low, pivot->pre);
        QuickSort(pivot->next, high);
    }
}


int main()
{
    insert(7);
    insert(3);
    insert(9);
    insert(1);
    insert(5);


    cout << "Before Sorting:" << endl;
    print();


    QuickSort(head, tail);


    cout << "\nAfter Sorting:" << endl;
    print();


    return 0;
}


#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    float data;
    Node *left;
    Node *right;
};

Node* insert(Node *root, float value)
{
    // New node create
    Node *newNode = new Node;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    // Agar tree empty hai
    if(root == NULL)
        return newNode;

    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if(temp->left == NULL)
        {
            temp->left = newNode;
            return root;
        }
        else
        {
            q.push(temp->left);
        }

        if(temp->right == NULL)
        {
            temp->right = newNode;
            return root;
        }
        else
        {
            q.push(temp->right);
        }
    }

    return root;
}

void mirror(Node *root)
{
    if(root == NULL)
        return;

    Node *temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);
}

void inorder(Node *root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    Node *root = NULL;
    int n;
    float value;

    cout << "Enter number of nodes: ";
    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        cout << "Enter value: ";
        cin >> value;
        root = insert(root, value);
    }

    cout << "\nInorder Before Mirror: ";
    inorder(root);

    mirror(root);

    cout << "\nInorder After Mirror: ";
    inorder(root);

    return 0;
}



#include<iostream>
#include<queue>
#include<stack>
using namespace std;

struct Node
{
    float data;
    Node *left,*right;
};

Node* insert(Node* root,float val)
{
    Node* temp=new Node;
    temp->data=val;
    temp->left=temp->right=NULL;

    if(root==NULL)
        return temp;

    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node* cur=q.front();
        q.pop();

        if(cur->left==NULL)
        {
            cur->left=temp;
            return root;
        }
        else
            q.push(cur->left);

        if(cur->right==NULL)
        {
            cur->right=temp;
            return root;
        }
        else
            q.push(cur->right);
    }

    return root;
}

bool DFS(Node* root,float x)
{
    if(root==NULL)
        return false;

    if(root->data==x)
        return true;

    return DFS(root->left,x) || DFS(root->right,x);
}

void preorder(Node* root)
{
    if(root==NULL)
        return;

    stack<Node*> st;
    st.push(root);

    while(!st.empty())
    {
        Node* cur=st.top();
        st.pop();

        cout<<cur->data<<" ";

        if(cur->right)
            st.push(cur->right);

        if(cur->left)
            st.push(cur->left);
    }
}

int main()
{
    Node* root=NULL;

    root=insert(root,10.5);
    root=insert(root,20.3);
    root=insert(root,30.8);
    root=insert(root,40.1);
    root=insert(root,50.2);

    float x;
    cout<<"Search value : ";
    cin>>x;

    if(DFS(root,x))
        cout<<"Found\n";
    else
        cout<<"Not Found\n";

    cout<<"Preorder : ";
    preorder(root);
}


#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

int arr[100];
int size = 0;

// Insert in BST
Node* insert(Node* root, int val)
{
    if (root == NULL)
    {
        Node* temp = new Node;
        temp->data = val;
        temp->left = temp->right = NULL;
        return temp;
    }

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// BST -> Array (Inorder)
void inorder(Node* root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    arr[size++] = root->data;
    inorder(root->right);
}

// Array -> Balanced BST
Node* arrayToBST(int start, int end)
{
    if (start > end)
        return NULL;

    int mid = (start + end) / 2;

    Node* temp = new Node;
    temp->data = arr[mid];

    temp->left = arrayToBST(start, mid - 1);
    temp->right = arrayToBST(mid + 1, end);

    return temp;
}

// Preorder Traversal
void preorder(Node* root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// BST Search
Node* search(Node* root, int x)
{
    if (root == NULL || root->data == x)
        return root;

    if (x < root->data)
        return search(root->left, x);

    return search(root->right, x);
}

int main()
{
    Node* root = NULL;

    root = insert(root, 5);
    root = insert(root, -2);
    root = insert(root, 8);
    root = insert(root, 0);
    root = insert(root, -5);
    root = insert(root, 9);

    // Convert BST to Array
    inorder(root);

    cout << "Array: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    cout << endl;

    // Convert Array to BST
    Node* newRoot = arrayToBST(0, size - 1);

    cout << "Preorder: ";
    preorder(newRoot);

    int x;
    cout << "\nEnter value to search: ";
    cin >> x;

    if (search(newRoot, x))
        cout << "Value Found";
    else
        cout << "Value Not Found";

    return 0;
}



#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Level Order Insertion (Binary Tree)
Node* insert(Node* root, int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    if (root == NULL)
        return newNode;

    queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        if (temp->left == NULL)
        {
            temp->left = newNode;
            return root;
        }
        else
            q.push(temp->left);

        if (temp->right == NULL)
        {
            temp->right = newNode;
            return root;
        }
        else
            q.push(temp->right);
    }

    return root;
}

// Preorder Without Recursion
void preorder(Node* root)
{
    if (root == NULL)
        return;

    stack<Node*> s;
    s.push(root);

    while (!s.empty())
    {
        Node* temp = s.top();
        s.pop();

        cout << temp->data << " ";

        // Pehle right push karte hain
        if (temp->right != NULL)
            s.push(temp->right);

        // Phir left push karte hain
        if (temp->left != NULL)
            s.push(temp->left);
    }
}

int main()
{
    Node* root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 60);

    cout << "Preorder (Without Recursion): ";
    preorder(root);

    return 0;
}


#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = NULL;

// Insert at end (list banane ke liye)
void insertEnd(int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Display
void display()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Length
int length()
{
    int count = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

// Special Insert
void specialInsert(int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    int digit = value % 10;
    int len = length();
    int pos;

    // Even -> Head se
    if (digit % 2 == 0)
        pos = digit;

    // Odd -> Tail se
    else
        pos = len - digit;

    if (pos <= 0)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node *temp = head;

    for (int i = 1; i < pos && temp->next != NULL; i++)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;
}

int main()
{
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertEnd(40);
    insertEnd(50);
    insertEnd(60);
    insertEnd(70);
    insertEnd(80);
    insertEnd(90);
    insertEnd(100);

    cout << "Original List:\n";
    display();

    specialInsert(38);
    display();

    specialInsert(23);
    display();
}

void preSuc(Node *root, string x)
{
    if (root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    Node *prev = NULL;
    Node *pre = NULL;
    Node *suc = NULL;

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp->data == x)
        {
            pre = prev;

            if (!q.empty())
                suc = q.front();

            break;
        }

        prev = temp;

        if (temp->left)
            q.push(temp->left);

        if (temp->right)
            q.push(temp->right);
    }

    if (pre)
        cout << "Predecessor: " << pre->data << endl;
    else
        cout << "No Predecessor" << endl;

    if (suc)
        cout << "Successor: " << suc->data << endl;
    else
        cout << "No Successor" << endl;
}