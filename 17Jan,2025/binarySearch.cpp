#include<iostream>

using namespace std;

bool search(int arr[], int key, int n){
    int l = 0;
    int r = n-1;
    while(l<=r){
        int mid = (l+r)/2;
        if(arr[mid] == key){
            return true;
        }
        if(key > arr[mid]){
            l = mid+1;
        }else {
            r = mid-1;
        }
    }
    return false;
}

int main() {
    int arr[] = {8, 12, 20, 43, 56};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key;
    cin >> key;
    if(search(arr,key,n)) cout << "Element found" << endl;
    else cout << "Element not found" << endl;
}