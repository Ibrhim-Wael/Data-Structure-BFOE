#include <iostream>
using namespace std;
void selection_sort(int a[],int size) {
    for (int i=0; i<size;i++) {
        int min=i;
        for (int j=i+1 ; j<size; j++ ) {
            if (a[j] > a[min]) {
                min=j;
            }
        }
        if (min != i) {
            int temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
}

int kthlargest(int arr[],int k,int size) {
    selection_sort(arr,size);
    if (k<0 || k>=size) {
        cout<<"Out of Range"<<endl;
        return 0;
    }else {
        return arr[k-1];
    }
}
int main() {
    int s[5]={1,90,374,973,23};
    cout<<kthlargest(s,3,5)<<endl;
}
