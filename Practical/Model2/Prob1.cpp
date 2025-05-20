#include <iostream>
using namespace std;
#define size 200

class StackCh {
private:

public:
    char c[size];
    int top=-1;
    bool is_Full() {
        return top==(size-1) ;
    }
    bool isEmpty() {
        return top==-1;
    }

    void push(char l) {
        if (is_Full()) {
            cout<<"cant Push the stack is Full"<<endl;
        }
        else {
            c[++top]=l;
        }
    }

    char get_top() {
        return c[top];
    }
    char pop() {
        if (isEmpty()) {
            cout<<"The Stack is Empty cant pop"<<endl;
        }else{
            return c[top--];
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
        }
        else {
            for (int i = top ;i>=0;i-- ) {
                cout << c[i] << endl;
            }
        }
    }
};


void Reverse_last_K_word(string &s, int k) {
    // the idea is we are going to keep decresing the i until the kth space is foun
    // then traversing each word from 0 normally to i
    // after this we pop from the stack the reversed words سعني هعكس كل الكلام لحد مكان الفراغ اللي هو عايزة
    int word_end = s.length() - 1;
    int word_start;
    int wordCount = 0;
    while (word_end >= 0 && wordCount < k) {
        while (word_end >= 0 && s[word_end] == ' ') {
            word_end--;
        }
        if (word_end < 0) break;
        word_start = word_end;
        while (word_start >= 0 && s[word_start] != ' ') {
            word_start--;
        }
        StackCh stack;
        for (int i = word_start + 1; i <= word_end; i++) {
            stack.push(s[i]);
        }
        for (int i = word_start + 1; i <= word_end; i++) {
            s[i] = stack.pop();
        }
        word_end = word_start - 1;
        wordCount++;
    }
}
int main() {
    string s = "Hema is the goat";
    StackCh s1;
    Reverse_last_K_word(s, 3);
    cout << s;
}
