#include<iostream>
using namespace std;
struct Node{
	int value;
	Node*next;
};
Node*top=NULL;
void push(int value){
	Node*temp=new Node;
	temp->value=value;
	temp->next=top;
	top=temp;
}
void pop(){
	if(top==NULL){
		cout<<"Underflow"<<endl;
		return;
	}
	Node*temp=top;
	cout<<temp->value<<" popped"<<endl;
	top=top->next;
	delete(temp);
}
void display(){
	if(top==NULL){
		cout<<"Stack is empty"<<endl;
		return;
	}
	Node*temp=top;
	while(temp!=NULL){
		cout<<temp->value<<"->";
		temp=temp->next;
	}
	cout<<"NULL\n";
}
int main(){
	push(25);
	push(35);
	push(45);
	display();
	pop();
	display();
}