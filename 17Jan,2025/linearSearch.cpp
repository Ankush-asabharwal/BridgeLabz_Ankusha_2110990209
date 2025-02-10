#include<iostream>

using namespace std;

int search(int arr[], int key, int n){
    for(int i = 0;i<n;i++){
        if(arr[i] == key){
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {12, 8, 20, 56, 43};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key;
    cin >> key;
    cout << search(arr,key,n) << endl;;
}