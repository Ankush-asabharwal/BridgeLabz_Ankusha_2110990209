#include<iostream>

using namespace std;

void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int l, int r){
    int pivot = arr[l];
    int i = l+1;
    int j = r;
    while(i<=j){
        while(arr[i]<=pivot && i<=r){
            i++;
        }
        while(arr[j]>pivot && j>=l){
            j--;
        }
        if(i < j){
            swap(arr,i,j);
        }
    }
    swap(arr, l,j);
    return j;
}

void sort(int arr[], int l, int r){
    if(l < r){
        int pIndex = partition(arr,l,r);
        sort(arr,l,pIndex-1);   
        sort(arr,pIndex+1,r);   
    }
}

int main() {
    int arr[] = {4, 6, 2, 5, 7, 9, 1, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr,0,n-1);

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
}