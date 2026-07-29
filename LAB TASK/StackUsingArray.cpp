#include <iostream>
using namespace std;
#define Max 5
int stack[Max];
int top = -1;
void push(int value)
{
    if (isFull())
    {
        cout << "Stack Overflow" << endl;
        return;
    }
    else
    {
        top++;
        stack[top] = value;
        cout << value << " pushed into the stack" << endl;
    }
}
void pop (){
    if(isempty()){
        cout <<" Stack underflow"<<endl;
        return;
    }
    else{
        cout<<stack[top]<<endl;
        top--;
    }
}
bool isempty(){
    return(top==-1);
}
bool isFull(){
    return (top==Max-1);
}
void peek(){
    if(isempty()){
        cout<<"Stack Underflow";
        return;
    }
    cout<<"Top element"<<stack[top];
}
void display(){
    if(top==-1){
        cout<<"stack  is empty"<<endl;
    
    }
    else{
        for(int i=top;i>=0;i--){
            cout<<stack[i]<<" ";
        }

    }
}
int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    pop();
    display();

    return 0;
}