#include <iostream>
using namespace std;

void Sort_the_first_nth(int arr[], int n, int totalSize) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1]=key;
    }
}

int main() {
    int a[7]={67,26,59,13,87,17,19};
    cout<<"Before Sort"<<endl;
    for (int i=0;i<7;i++) {
        cout<<a[i]<<" ";
    }
    Sort_the_first_nth(a,6,7);
    cout<<"\nAfter Sorting"<<endl;
    for (int i=0;i<7;i++) {
        cout<<a[i]<<" ";
    }
}
