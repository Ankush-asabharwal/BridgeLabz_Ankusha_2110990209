#include<iostream>

using namespace std;

int emplIs(int wagePerHr){
    int randN = rand()%3;
    switch(randN){
        case 0 :
            return 0;
            break;
        case 1 :
            return 8 * wagePerHr;
            break;
        case 2 : 
            return 4 * wagePerHr;
            break;
        default:
            return 0; 
    }
}

bool present(){
    int randN = rand()%2;
    if(randN==0){
        return true;
    }else{
        return false;
    }
}

int calMonthlyWage(int workingDayInMonth){
    int wagePerHr =20;
    int total = 0;
    for(int i=0;i<workingDayInMonth;i++){
        if(present()){
            int dailyWage = emplIs(wagePerHr);
            total += dailyWage;
        }else{
            total = total +0;
        }
    }
    
    return total;
}

int main(){
    srand(time(0));
    cout << "Welcome to Employee wage computation"<<endl;
    int workingDayInMonth =20;
    int totalWage = calMonthlyWage(workingDayInMonth);
    cout << "Total wage of month is : " << totalWage;

}