#include<iostream>

using namespace std;

void merge(int arr[], int l, int r, int mid){
    int n1 = mid-l+1;
    int n2 = r-mid;

    int a[n1];
    int b[n2];

    for(int i=0;i<n1;i++){
        a[i] = arr[l+i];
    }
    for(int j=0;j<n2;j++){
        b[j] = arr[mid+1+j]; 
    }

    int i = 0;
    int j = 0;
    int k = l;

    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            arr[k] = a[i];
            k++, i++;
        }else{
            arr[k] = b[j];
            k++, j++;
        }
    }
    while(i<n1){
        arr[k] = a[i];
        k++, i++;
    }
    while(j<n2){
        arr[k] = b[j];
        k++, j++;
    }

}

void mergeSort(int arr[], int l, int r){
    if (l < r) {
    int mid = l + (r - l) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, r);
    merge(arr,l,r,mid);
    }
}

int main(){
    int arr[] = {1,3,5,7,2,4,6,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr, 0, n-1);

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    } 
}