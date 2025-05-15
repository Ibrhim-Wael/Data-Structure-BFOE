#include <iostream>
using namespace std;
#define size 5

class Stack {
    public:
    int top;
    int a[size];
    public:
    //A constructor setting the queue to the empty state
    Stack() :top(-1){};

    //checking if empty and full using boolean functions
    bool isEmpty() {
        return top == -1;
    }
    bool isFull() {
        return top == size-1;
    }

    //Pushing Algorithm
    void push(int x) {
        if (isFull()) {
            cout << "Stack is full" << endl;
        }else {
            a[++top] = x;
        }
    }

    //Popping Algorithm
    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
        }
        else {
            return a[top--];
        }
    }

    //Display
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
        }
        else {
            for (int i = top ;i>=0;i-- ) {
                cout << a[i] << endl;
            }
        }
    }

};


int main() {
    Stack s;
    s.push(10);
    s.push(56);
    s.push(98);
    s.display();
    cout<<"============="<<endl;
    s.pop();
    s.pop();
    s.display();
}
