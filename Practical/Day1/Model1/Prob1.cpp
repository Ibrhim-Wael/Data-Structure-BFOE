#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* left=nullptr;
    node* right=nullptr;
};


class bst {
public:
    int i=0;
    int order[10];
    node* root= nullptr;
    bool isEmpty() {
        return root==nullptr;
    }
    node* insert( int x, node* r) {
        if (r==nullptr) {
            node* new_node = new node();
            new_node->data= x;
            r=new_node;
            return r;
        }else{
            if (x > r->data) {
                r->right=insert(x,r->right);
            }else if (x<r->data){
                r->left=insert(x,r->left);
            }
        }
        return r;
    }

    void inorderTraversal(node* r) {
        if (r == nullptr) {
            return ;
        }else {
            inorderTraversal(r->left);
            order[i++]=r->data;
            cout<<r->data<<" ";
            inorderTraversal(r->right);
        }
    }
    void smallest_kth(int k) {
        cout <<"yes"<<order[k-1];
    }
};

int main() {
    bst b1;
    b1.root=b1.insert(10,b1.root);
    b1.root=b1.insert(5,b1.root);
    b1.root=b1.insert(1,b1.root);
    b1.root=b1.insert(50,b1.root);
    b1.root=b1.insert(40,b1.root);
    b1.root=b1.insert(100,b1.root);
    b1.inorderTraversal(b1.root);
    cout<<"\n"<<endl;
    b1.smallest_kth(5);
}
