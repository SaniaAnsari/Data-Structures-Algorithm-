#include <iostream>
#include <stack>
using namespace std;
struct Node
{
    char data;
    Node *left;
    Node *right;
};
bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
Node *postfixTree(string postfix)
{
    stack<Node *> st;

    for (int i = 0; i < postfix.length(); i++)
    {
        char ch = postfix[i];
        if (!isOperator(ch))
        {
            Node *temp = new Node;
            temp->data = ch;
            temp->left = NULL;
            temp->right = NULL;
            st.push(temp);
        }
        else
        {
            Node *right = st.top();
            st.pop();
            Node *left = st.top();
            st.pop();

            Node *temp = new Node;
            temp->data = ch;
            temp->left = left;
            temp->right = right;

            st.push(temp);
        }
    }
    return st.top();
}
// Inorder traversal
void inorder(Node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data;
    inorder(root->right);
}
int main()
{
    string postfix = "ab+c-";

    Node *root = postfixTree(postfix);

    cout << "Inorder: ";
    inorder(root);

    return 0;
}