#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next=nullptr;
};

class linked_list {
private:
    node* head=NULL;
public:
    bool isEmpty() {
        return head==NULL;
    }
    void insert(int x) {
        node* new_node= new node();
        new_node->data=x;
        if (isEmpty()) {
            head=new_node;
        }else {
            node* temp = head;
            while (temp->next != NULL) {
                temp=temp->next;
            }
            temp->next=new_node;
        }
    }

    void insertAtFirst(int x) {
        if (isEmpty()) {
            insert(x);
        }else {
            node* new_node= new node();
            new_node->next=head;
            head=new_node;
        }
    }


    void print() {
        if (isEmpty()) {
            cout<<"Cant Print the ll is empty"<<endl;
        }else {
            node* temp= new node();
            temp=head;
            while (temp!=NULL) {
                cout << temp->data <<"->";
                temp=temp->next;
            }
        }
    }

    int count() {
        int c=1;
        if (isEmpty()) {
            return 0;
        }else {
            node* temp= new node();
            temp=head;
            while (temp!=NULL) {
                temp=temp->next;
                c++;
            }
            return c;
        }
    }

    void sqauremiddle() {
        int middle=count()/2;
        int c=1;
        node*temp=head;
        while (c!=middle) {
            temp=temp->next;
            c++;
        }
        temp->data*=(temp->data);
    }
};


int main() {
    linked_list l1;
    l1.insert(10);
    l1.insert(9);
    l1.insert(4);
    l1.insert(56);
    l1.insert(8);
    l1.insert(4);
    cout<<"\nThe Linked list Before Squaring the middle"<<endl;
    l1.print();
    l1.sqauremiddle();
    cout<<"\nThe Linked list after Squaring the middle"<<endl;
    l1.print();

}
