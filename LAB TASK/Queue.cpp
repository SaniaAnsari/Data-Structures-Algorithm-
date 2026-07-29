#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
Node *front = NULL;
Node *rear = NULL;
void EnQueue(int value)
{
    Node *temp = new Node;
    temp->data = value;
    temp->next = NULL;
    if (rear == NULL)
    {
        front = rear = temp;
    }else{
    rear->next = temp;
    rear = temp;
    }
}
void DeQueue()
{
    if (front == NULL)
    {
        cout << "Queue is empty" << endl;
        return;
    }
    Node *cur = front;
    
    front = front->next;
    if (front == NULL)
    {
        rear = NULL;
    }
    cout<< "DeQueued: "<< front->data<<endl;
    free(cur);
}
void display(){
    if(front==NULL){
        cout<<"Queue is empty"<<endl;
        return;
    }
    cout<<"Queue elements"<<endl;
    Node*temp=front;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    EnQueue(5);
    EnQueue(25);
    EnQueue(35);
    EnQueue(45);
    display();
    DeQueue();
    display();
    return 0;

}