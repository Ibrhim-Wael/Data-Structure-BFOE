#include <iostream>
using namespace std;
#define size 100

///We used the same stack implentation but with Char instead of integers
class Stack_Char {
private:
    char a[size];
public:
    int top;
    //A constructor setting the queue to the empty state
    Stack_Char() :top(-1){};
    //checking if empty and full using boolean functions
    bool isEmpty() {
        return top == -1;
    }
    bool isFull() {
        return top == size-1;
    }
    //Pushing Algorithm
    void push(char x) {
        if (isFull()) {
            cout << "Stack is full" << endl;
        }else {
            a[++top] = x;
        }
    }

    //Popping Algorithm
    char pop() {
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





//Making a function that accpts a string value and then return 1 if brackets are closed and 0 if not 
bool closed_Brackets(string s) {
    Stack_Char st;
    bool flag = false;
    //Traversing all over the string
    for (int i=0;i<s.length();i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
         st.push(s[i]);
        }
        //Checking for each type of the brackets
        else if (s[i] == ')' ) {
            if (st.top == '(') {
               st.pop();
            }
        }else if (s[i] == '}' ) {
            if (st.top == '{') {
               st.pop();
            }
        }else if (s[i] == ']' ) {
            if (st.top == '[') {
                st.pop();
            }
        }
    }
    /*If after the traversing the stack is not empty which indicates there is a non closed bracket or more
    the function will return 0 if not will return 1 */
    if (st.isEmpty()) {
        flag = true;
    }
    return flag;
}


int main() {
    string s;
    cout<<"please enter a string: "<<endl;
    cin >> s;
    if (closed_Brackets(s)) {
        cout << "Closed Brackets" << endl;
    }else {
        cout << "Open Brackets" << endl;
    }
    return 0;
}
