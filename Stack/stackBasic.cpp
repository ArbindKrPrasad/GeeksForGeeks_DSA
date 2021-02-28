#include <iostream>
using namespace std;

class MyStack
{
    public:
    int *arr;
    int top;
    int cap;
    MyStack(int c)
    {
        cap = c;
        arr = new int[cap];
        top = -1;
    }

    void push(int x)
    {
        if (top == cap - 1)
        {
            cout << "overflow"<<endl;
            return;
        }
        top++;
        arr[top] = x;
    }

    int pop()
    {
        if (top == -1)
        {
            cout << "underflow"<<endl;
            return -1;
        }
        int res = arr[top];
        top--;
        return res;
    }

    int peek()
    {
        if (top == -1)
        {
            cout << "empty stack"<<endl;
            return -1;
        }
        return arr[top];
    }
    int size()
    {
        return top + 1;
    }

    bool isEmpty()
    {
        return top==-1;
    }

    void print(){
        for(int i=0; i<=top; i++){
            cout<<arr[i]<<" ";
        }
    }
};

int main(){
    MyStack s(5);
    s.push(5);
    s.push(10);
    s.push(15);
    s.push(20);
    s.push(25);
    s.push(30);
    s.print();

}