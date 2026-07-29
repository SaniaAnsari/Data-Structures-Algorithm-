#include <iostream>
using namespace std;
#define Max 20
char stack[Max];
int top = -1;
void push(char ch)
{
    if (top == Max - 1)
    {
        cout << "Stack Overflow" << endl;
        return;
    }
    else
    {
        top++;
        stack[top] = ch;
       // cout << ch << " pushed into the stack" << endl;
    }
}
char pop()
{
    if (top == -1)
    {
        cout << " Stack underflow" << endl;
        return '\0';
    }
    return stack[top--];
}
int precedence(char op)
{
    switch (op)
    {
    case '*':
    case '/':
    case '%':
        return 2; // higher precedence
    case '+':
    case '-':
        return 1; // lower precedence
    }
    return 0;
}
int main()
{
    string postfix;
    string infix;

    cout << "Enter infix expression: ";
    cin >> infix;

    for (int i = 0; i < infix.length(); i++)
    {
        if (infix[i] >= 'A' && infix[i] <= 'Z')
        {
            postfix += infix[i];
        }
        else if (infix[i] >= 'a' && infix[i] <= 'z')
        {
            postfix += infix[i];
        }
        else if (infix[i] >= '0' && infix[i] <= '9')
        {
            postfix += infix[i];
        }
        else if (infix[i] == '(')
        {
            push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                postfix += pop();
            }
            pop(); // remove '('
        }
        else
        {
            if (top == -1)
            {
                push(infix[i]);
            }
            else
            {
                while (top != -1 && precedence(stack[top]) >= precedence(infix[i]))
                {
                    postfix += pop();
                }
                push(infix[i]);
            }
        }
    }
    while (top != -1)
    {
        postfix += pop();
    }
    cout << "Postfix expression: " << postfix << endl;
    return 0;
}