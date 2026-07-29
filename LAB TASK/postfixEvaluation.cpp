#include <iostream>
using namespace std;
#define Max 20
//==========STACK OPERATOR==========
char stack[Max];
int top = -1;
void push(char ch)
{
    if (top == Max - 1)
    {
       // cout << "Stack Overflow" << endl;
        return;
    }
    else
    {
        top++;
        stack[top] = ch;
        //cout << ch << " pushed into the stack" << endl;
    }
}
char pop()
{
    if (top == -1)
    {
        cout << " Stack underflow" << endl;
        return -1;
    }
    return stack[top--];
}
//==========PRECEDENCE CHECK==========
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
//==========INFIX TO POSTFIX CONVERSION==========
string infixtopostfix(string infix)
{
    string postfix;
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

        //cout << "Postfix expression: " << postfix << endl;
    }
    while (top != -1)
    {
        postfix += pop();
    }
    return postfix;
}
//==========STACK OPERAND==========
int Intstack[Max];
int t = -1;
void Intpush(int val)
{
    if (t == Max - 1)
    {
        cout << "Stack Overflow" << endl;
        return;
    }
    else
    {
        t++;
        stack[t] = val;
       // cout << val << " pushed into the stack" << endl;
    }
}
int Intpop()
{
    if (t == -1)
    {
        cout << " Stack underflow" << endl;
        return -1;
    }
    return stack[t--];
}

int getvalue(char ch)
{

    int value;
    cout << "Enter value of " << ch <<":";
    cin >> value;
    return value;
}
//==========POSTFIX EVALUATION==========
int postfixEvaluate(string postfix)
{
    for (int i = 0; i < postfix.length(); i++)
    {
        char ch = postfix[i];

        if (ch >= 'A' && ch <= 'Z')
        {
            Intpush(getvalue(ch));
        }
        else if (ch >= 'a' && ch <= 'z')
        {
            Intpush(getvalue(ch));
        }

        else if (ch >= '0' && ch <= '9')
        {
            Intpush(ch - '0');
        }
        else
        {
            int val1 = Intpop();
            int val2 = Intpop();

            switch (ch)
            {
            case '+':
                Intpush(val2+ val1);
                break;
            case '-':
                Intpush(val2 - val1);
                break;
            case '*':
                Intpush(val2 * val1);
                break;
            case '/':
                Intpush(val2 / val1);
                break;
            }
        }
    }
    return Intpop();
}
int main()
{

    string infix;

    cout << "Enter infix expression: ";
    cin >> infix;

    string postfix=infixtopostfix(infix);
    cout<< "======postifx expression====== "<< endl << postfix <<endl; 

    int result=postfixEvaluate(postfix);
    cout<< "======postfixEvaluation======" << endl << result;

    return 0;
}