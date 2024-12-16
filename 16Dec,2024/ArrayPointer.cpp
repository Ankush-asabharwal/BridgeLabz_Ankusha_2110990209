#include<iostream>

using namespace std;

int main(){
    int arr[] = {1,2,3,4,5};
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
        int* ptr = arr + i;
        cout << *ptr << endl;
    }
    // int* ptr = arr+1;
    // cout << *ptr << endl;
}