#include <iostream>
#include <stack>
using namespace std;
struct BSTNode
{
	int data;
	BSTNode *left;
	BSTNode *right;
};
BSTNode *root = NULL;
// insert
BSTNode *insert(BSTNode *cur, int value)
{
	if (cur == NULL)
	{

		BSTNode *temp = new BSTNode;
		temp->data = value;
		temp->left = temp->right = NULL;

		return temp;
	}
	if (value < cur->data)
	{
		cur->left = insert(cur->left, value);
	}
	else
	{
		cur->right = insert(cur->right, value);
	}
	return cur;
}
// display
void PreOrder(BSTNode *cur)
{
	if (cur != NULL)
	{

		cout << cur->data << "  ";
		PreOrder(cur->left);
		PreOrder(cur->right);
	}
}
void PostOrder(BSTNode *cur)
{
	if (cur != NULL)
	{

		PostOrder(cur->left);
		PostOrder(cur->right);
		cout << cur->data << " ";
	}
}
void InOrder(BSTNode *cur)
{
	if (cur != NULL)
	{

		InOrder(cur->left);
		cout << cur->data << " ";
		InOrder(cur->right);
	}
}
// postorder without recursion
void post()
{
	if (root == NULL)
	{
		return;

		stack<BSTNode *> s1, s2;
		s1.push(root);

		while (!s1.empty())
		{
			BSTNode *temp = s1.top();
			s1.pop();

			s2.push(temp);

			if (temp->left != NULL)
			{
				s1.push(temp->left);
			}
			if (temp->right != NULL)
			{
				s1.push(temp->right);
			}
		}
		while (!s2.empty())
		{
			cout << s2.top()->data << " ";
			s2.pop();
		}
	}
}
// without recursion
void Pre()
{
	if (root == NULL)
	{
		return;
	}
	stack<BSTNode *> s1;
	s1.push(root);
	while (!s1.empty())
	{
		BSTNode *temp = s1.top();
		s1.pop();
		cout << temp->data;
		if (temp->right != NULL)
		{
			s1.push(temp->right);
		}
		if (temp->left != NULL)
		{
			s1.push(temp->left);
		}
	}
}
void inorder(){
	if(root==NULL){
		return;
	}
	stack<BSTNode*>s;
	BSTNode* cur=root;

	while(cur!=NULL||!s.empty()){
		while(cur!=NULL){
			s.push(cur);
			cur=cur->left;
		}
		cur=s.top();
		s.pop();
		cout<<cur->data<<" ";
		cur=cur->right;

	}

}
// Search
void search(BSTNode *cur, int value)
{
	if (cur == NULL)
	{
		cout << "Not found" << " ";
		return;
	}
	if (cur->data == value)
	{
		cout << value << " found" << " ";
		return;
	}
	if (value < cur->data)
	{
		search(cur->left, value);
	}
	else
	{
		search(cur->right, value);
	}
}
BSTNode *FindMin(BSTNode *cur)
{
	while (cur != NULL && cur->left != NULL)
	{
		cur = cur->left;
	}
	return cur;
}
// DELETE
BSTNode *del(BSTNode *cur, int value)
{
	if (cur == NULL)
	{
		return NULL;
	}
	if (value < cur->data)
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
			BSTNode *temp = cur->right;
			delete cur;
			return temp;
		}
		else if (cur->right == NULL)
		{
			BSTNode *temp = cur->left;
			delete cur;
			return temp;
		}
		// Case 3: Two children
		else
		{
			BSTNode *temp = FindMin(cur->right);
			cur->data = temp->data;
			cur->right = del(cur->right, temp->data);
		}
	}

	return cur;
}
int maxdepth(BSTNode *Node)
{
	if (Node == NULL)
	{
		return 0;
	}
	int leftdepth = maxdepth(Node->left);
	int rightdepth = maxdepth(Node->right);
	return 1 + max(leftdepth, rightdepth);
}
int main()
{
	bool start = true;
	while (start)
	{
		cout << "\n======MENU======";
		cout << "\n1. Insert ";
		cout << "\n2. PreOrder ";
		cout << "\n3. PostOrder ";
		cout << "\n4. InOrder ";
		cout << "\n5. Delete ";
		cout << "\n6. Search ";
		cout << "\n7. maxdepth ";
		cout << "\n8. Exit ";

		int choice, value;
		cout << "\nEnter choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Enter value: ";
			cin >> value;
			root = insert(root, value);
			break;
		case 2:
			PreOrder(root);
			break;
		case 3:
			PostOrder(root);
			break;
		case 4:
			InOrder(root);
			break;
		case 5:
			cout << "Enter value: ";
			cin >> value;
			root = del(root, value);
			break;
		case 6:
			cout << "Enter value: ";
			cin >> value;
			search(root, value);
			break;
		case 7:
			start = false;
			cout << "Exit ";
			break;
		default:
			cout << "Invalid";
			break;
		}
	}
	return 0;
}
