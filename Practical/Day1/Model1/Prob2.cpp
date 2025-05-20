#include <iostream>
using namespace std;


void missing(int arr1[],int arr2[],int size1,int size2) {
    for (int i=0;i< size2 ;i++) {
        bool found=0;
        for (int j=0;j<size1;j++) {
            if (arr2[i]==arr1[j]) {
                found=1;
            }
        }
        if (!found) {
            cout<<arr2[i]<<",";
        }
    }
}

int main() {

    int arr1[6]={10,5,1,50,40,100};
    int arr2[9]={40,1,30,50,100,5,20,97,10};
    missing(arr1,arr2,6,9);
}
