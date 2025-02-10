#include<iostream>

using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5 };

    // for(int i = 0; i<sizeof(arr)/sizeof(arr[0]);i++ ){
    //     int* r = &arr[i];
    //     cout << *r << " --> "<< r << endl;
    // }

    int* p = arr;
    for(int i = 0; i<sizeof(arr)/sizeof(arr[0]);i++ ){
        cout << p << endl;
        p++;
    }


}