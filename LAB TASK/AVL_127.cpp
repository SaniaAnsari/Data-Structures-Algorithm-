#include <iostream>
using namespace std;

struct AVLNode
{
    int data;
    AVLNode *left;
    AVLNode *right;
    int height;
};
AVLNode *root = NULL;

// height
int getHeight(AVLNode *node)
{
    if (node == NULL)
        return -1;
    return node->height;
}

// Maximum function
int maximum(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

// Right Rotation (LL)
AVLNode *rotateRight(AVLNode *node)
{
    AVLNode *temp = node->left;
    node->left = temp->right;
    temp->right = node;

    node->height = maximum(getHeight(node->left), getHeight(node->right)) + 1;
    temp->height = maximum(getHeight(temp->left), getHeight(temp->right)) + 1;

    return temp;
}

// Left Rotation (RR)
AVLNode *rotateLeft(AVLNode *node)
{
    AVLNode *temp = node->right;
    node->right = temp->left;
    temp->left = node;

    node->height = maximum(getHeight(node->left), getHeight(node->right)) + 1;
    temp->height = maximum(getHeight(temp->left), getHeight(temp->right)) + 1;

    return temp;
}

// Left-Right Rotation (LR)
AVLNode *rotateLeftRight(AVLNode *node)
{
    node->left = rotateLeft(node->left);
    return rotateRight(node);
}

// Right-Left Rotation (RL)
AVLNode *rotateRightLeft(AVLNode *node)
{
    node->right = rotateRight(node->right);
    return rotateLeft(node);
}

// Insert function
AVLNode *insert(AVLNode *node, int value)
{

    // Node creation
    if (node == NULL)
    {
        AVLNode *temp = new AVLNode;
        temp->data = value;
        temp->left = temp->right = NULL;
        temp->height = 0;
        return temp;
    }

    // Insert left
    if (value < node->data)
    {
        node->left = insert(node->left, value);

        if (getHeight(node->left) - getHeight(node->right) == 2)
        {
            if (value < node->left->data)
                node = rotateRight(node); // LL
            else
                node = rotateLeftRight(node); // LR
        }
    }
    // Insert right
    else
    {
        node->right = insert(node->right, value);

        if (getHeight(node->right) - getHeight(node->left) == 2)
        {
            if (value > node->right->data)
                node = rotateLeft(node); // RR
            else
                node = rotateRightLeft(node); // RL
        }
    }

    node->height = maximum(getHeight(node->left), getHeight(node->right)) + 1;
    return node;
}

// Inorder traversal
void inorder(AVLNode *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// search
void search(AVLNode *node, int value)
{
    if (node == nullptr)
    {
        cout << "not found" << endl;
        return;
    }
    if (node->data == value)
    {
        cout << node->data << " found";
        return;
    }
    if (value < node->data)
    {
        search(node->left, value);
    }
    else
    {
        search(node->right, value);
    }
}
AVLNode *FindMin(AVLNode *cur)
{
    while (cur != NULL && cur->left != NULL)
    {
        cur = cur->left;
    }
    return cur;
}
// DELETE
AVLNode *del(AVLNode *cur, int value)
{
    if (cur == NULL)
    {
        return NULL;
    }
    else if (value < cur->data)
    {
        cur->left = del(cur->left, value);
    }
    else if (value > cur->data)
    {
        cur->right = del(cur->right, value);
    }
    else
    {
        // case 0 child
        if (cur->left == NULL && cur->right == NULL)
        {
            delete (cur);
            return NULL;
        }
        // case 1 child
        else if (cur->left == NULL)
        {
            AVLNode *temp = cur->right;
            delete cur;
            return temp;
        }
        else if (cur->right == NULL)
        {
            AVLNode *temp = cur->left;
            delete cur;
            return temp;
        }
        // Case 3: Two children
        else
        {
            AVLNode *temp = FindMin(cur->right);
            cur->data = temp->data;
            cur->right = del(cur->right, temp->data);
        }
    }
    //  update height
    cur->height = maximum(getHeight(cur->left), getHeight(cur->right)) + 1;

    //  check balance
    int balance = getHeight(cur->left) - getHeight(cur->right);

    // LL
    if (balance == 2 && getHeight(cur->left->left) >= getHeight(cur->left->right))
        return rotateRight(cur);

    // LR
    if (balance == 2 && getHeight(cur->left->left) < getHeight(cur->left->right))
        return rotateLeftRight(cur);

    // RR
    if (balance == -2 && getHeight(cur->right->right) >= getHeight(cur->right->left))
        return rotateLeft(cur);

    // RL
    if (balance == -2 && getHeight(cur->right->right) < getHeight(cur->right->left))
        return rotateRightLeft(cur);

    return cur;
}
// Main
int main()
{
    root = insert(root, 120);
    root = insert(root, 110);
    root = insert(root, 150);
    root = insert(root, 130);
    root = insert(root, 140);
    root = insert(root, 146);
    root = insert(root, 136);
    root = insert(root, 134);
    root = insert(root, 160);
    root = insert(root, 154);
    root = insert(root, 156);
    root = insert(root, 132);
    root = insert(root, 125);
    root = insert(root, 128);

    cout << "Inorder Traversal: ";
    inorder(root);

    return 0;
}