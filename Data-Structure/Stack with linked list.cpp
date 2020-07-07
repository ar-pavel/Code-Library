/**
**                                   **
**   Assignment on Stack             **
**                                   **
**   Submitted by-                   **
**   Atikur Rahman                   **
**   ID-2016200000058                **
**   Course Code - CSE1034           **
**   Sec- 3                          **
**                                   **
**/


#include <bits/stdc++.h>

using namespace std;

class MyStack
{
public:
    MyStack* prev;
    int Digit;

    MyStack()
    {

    }

    MyStack(const MyStack &st)
    {
        Digit = st.Digit;
        prev = st.prev;

    }

    ~MyStack()
    {

    }
};

MyStack* Stack;
int top = 0;

void push(int val);
int isEmpty();
void Display();
void pop();

int main()
{
    Stack = new MyStack;
    char s;
    int n;
    cout<<"Press 'i' to push \n"
        "Press 'd' to display \n"
        "press 'p' to pop \n"
        "press 's' to check number of elements \n"
        "press any other key to exit \n"
        "__________________________________________ \n";

    while(cin>>s)
    {
        if(s=='i')
        {
            cout<<"-27 to stop\n";
            while(cin>>n && n!=-27) push(n);
        }
        else if(s=='d') Display();

        else if(s=='p') pop();

        else if(s=='s') cout<<top<<"\n";

        else break;
    }
    return 0;
}

void push(int val)
{
    MyStack* tp;
    tp = new MyStack;
    tp->Digit = val;

    if(isEmpty()) tp->prev = NULL;

    else    tp->prev = Stack;

    Stack = tp;
    top++;
}

int isEmpty()               ///Function to check to Stack is empty or not
{
    return (top==0)?1:0;
}

void Display()          ///Function to Display the Stack
{
    if(isEmpty())
    {
        cout<<"Stack: Stack underflow \n";
        return;
    }
    MyStack* tp = Stack;
    while(tp->prev != NULL)
    {
        cout<<tp->Digit<<" ";
        tp = tp->prev;
    }
    cout<<tp->Digit<<"\n";
}

void pop()          ///Function to POP data
{
    if(isEmpty())
    {
        cout<<"Stack: Stack underflow \n";
        return;
    }

    MyStack* tp = Stack;
    cout<<"Pop : "<<tp->Digit<<"\n";
    Stack = tp->prev;
    top--;
}
