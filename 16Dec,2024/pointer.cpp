#include<iostream>

using namespace std;

int incrementBy(int* a){
    return ++*a;
}

int main(){
    int* a = new int(10);
    incrementBy(a);
    cout << *a;
}