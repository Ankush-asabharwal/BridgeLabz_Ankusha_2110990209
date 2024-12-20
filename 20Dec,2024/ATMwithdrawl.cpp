#include<iostream>

using namespace std;

void note(int amountRequired){
    int d[] = {500,200,100,20,10};
    int notes[] = {5,5,5,5,5};
    int r = amountRequired;
    for(int i=0;i<5;i++){
        int notesRemoved = min(r/d[i],notes[i]);
        notes[i] = notes[i] - notesRemoved;
        r -= notesRemoved*d[i];
        cout << d[i] << " x " << notesRemoved << endl;
    } 
    if(r==0){
        cout << "Withdrawal Successfully" << endl;
        
    }
    else{
        cout << "Insufficient Notes" <<endl;
    }

}

void withdrawl(int totalBalance, int aR){
    if(aR%100!=0){
        cout << "Enter the amount which is multiple of 100"<<endl;
    }else{
        if(aR > totalBalance){
            cout << "Insuffiecient Balance"<<endl;
        }else{
            note(aR);
            cout << totalBalance-aR << " balance is remaining"<< endl;
        }
    }
}

int main(){
    const int totalBalance = 50000;
    int amountRequired;
    cout << "How much you want to withdrawl?" << endl;
    cin >> amountRequired;
    withdrawl(totalBalance, amountRequired);
}