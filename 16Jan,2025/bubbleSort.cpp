#include<iostream>
#include<string>

using namespace std;

void sort(int arr[], int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {2, 3, 5, 1, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr,n);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
}