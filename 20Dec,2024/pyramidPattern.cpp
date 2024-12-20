#include<iostream>

using namespace std;

void pyramidPat(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            cout << " ";
        }
        for(int j=0;j<2*i+1;j++){
            cout << "*";
        }

        for(int j =0;j<n-i-1;j++){
            cout<< " ";
        }
        cout<<endl;
    }
}

int main(){
    int n;
    pyramidPat(6);
}

