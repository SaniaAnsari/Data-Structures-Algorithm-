#include<iostream>
#include<queue>
using namespace std;

struct Node{
    float data;
    Node*left;
    Node*right;
};
Node* Root=NULL;
Node* insert(Node* root, float val){
    Node* newnode= new Node;
    newnode->data=val;
    newnode->left=newnode->right=NULL;


    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        Node*temp=q.front();
        q.pop();

        if(temp->left==NULL){
            temp->left=newnode;
        }else{
            q.push(temp->left);
        }

         if(temp->right==NULL){
            temp->right=newnode;
        }else{
            q.push(temp->right);
        }
    }
    return root;
}

void search(Node*root, float x){
    if(root==NULL){
        return;
    }
    if(root->data==x){
        cout<< "value found"<< root->data;
    }
    search(root->left,x);
    search(root->right,x);
}
int countnodes(Node*root){
    if (root==NULL){
        return;
    }
    return 1+countnodes(root->left)+countnodes(root->right);
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
int main(){

}