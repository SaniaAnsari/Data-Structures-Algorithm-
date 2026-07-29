#include <iostream>
using namespace std;
#define size 5
int Queue[size];
int rear = -1;
int front = -1;
void EnQueue(int data)
{
    if (front == (rear + 1) % size)
    {
        cout << "Queue is Full" << endl;
        return;
    }
    if (front == -1)     ///insertion at 1st position
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = (rear + 1) % size;
    }
    Queue[rear] = data;
}
void DeQueue()
{
    if (front == -1)
    {
        cout << "Queue is  empty" << endl;
        return;
    }
    if (front == rear)    // to deque last element
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % size;
    }
}
void display(){
    if(front==-1){
        cout<<"Queue is Empty";
        return;
    }
    int i=front;
    while(true){
        cout<<Queue[i]<<" ";
        if(i==rear){     // stop when last element reached
            break;
        }
        i=(i+1)%size;   //move to next index circularly
    }
}

int main()
{
    EnQueue(10);
    EnQueue(20);
    EnQueue(30);
    EnQueue(40);
    EnQueue(50);
    EnQueue(60);
    display();
    
    // DeQueue();
    // DeQueue();
    // display();
     
    // EnQueue(40);
    // EnQueue(50);
    // EnQueue(60);
    // display();
}