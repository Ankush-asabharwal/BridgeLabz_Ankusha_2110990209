#include<iostream>

using namespace std;

int main(){
    int a = 10;
    int* ptr = &a;
    cout<< "Value of a : " << a << endl;
    cout << "Address of a : "<< ptr << endl;
    cout << endl;

    char b = 'a';
    char* cptr = &b;
    cout<< "Value of b : " << b << endl;
    cout << "Address of b : "<< cptr << endl;
    cout << endl;

    float c = 12.3;
    float* fptr = &c;
    cout<< "Value of c : " << c << endl;
    cout << "Address of c : "<< fptr << endl;
    cout << endl;

    double d = 22.34;
    double* dptr = &d;
    cout<< "Value of d : " << d << endl;
    cout << "Address of d : "<< dptr << endl;
    cout << endl;

    short e = 12345;
    short* sptr = &e;
    cout<< "Value of e : " << e << endl;
    cout << "Address of e : "<< sptr << endl;
    cout << endl;

    long f = 1234567898;
    long* lptr = &f;
    cout<< "Value of f : " << f << endl;
    cout << "Address of f : "<< lptr << endl;
    cout << endl;

    signed int g = -10;
    signed int* gptr = &g;
    cout<< "Value of g : " << g << endl;
    cout << "Address of g : "<< gptr << endl;
    cout << endl;

    unsigned int h = 10;
    unsigned int* hptr = &h;
    cout<< "Value of h : " << h << endl;
    cout << "Address of h : "<< hptr << endl;
    cout << endl;

    int arr[] = {1,2,3,4,5};
    int* aptr = &arr[2];
    cout << "printing all the values of array : " << endl;
    for(int i =0;i<sizeof(arr)/sizeof(arr[0]);i++){
        int* ptr = arr +i;
        cout << *ptr <<" ";
    }
    cout<< endl;
    cout << "adress of array is starting from : " << aptr << endl;
    cout<< endl;

}