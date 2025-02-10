#include<iostream>

using namespace std;

void sort(int arr[], int n){
    int min = 0;
    for(int i=0;i<n;i++){
        min = arr[i];
        for(int j=i+1;j<n;j++){
            if(min > arr[j]){
                min = arr[j];
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {2, 4, 1, 5, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr,n);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
}