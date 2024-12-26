#include<iostream>

using namespace std;

int wagePerHr =20;

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

int cond(int dailyhrs, int &days){
    int total=0;
    while(dailyhrs<100 && days<20){
        if(present()){
            int wage = emplIs(wagePerHr);
            if(wage==160){
                dailyhrs += 8;
                cout << "full-time" << endl;
            }
            else if(wage == 80){
                dailyhrs += 4;
                cout << "part-time" << endl;
            }else{
                dailyhrs += 0;
                cout << "No work" << endl;
            }
            total += wage;
            days++;
        }
    }
    cout << "Hours completed by employee : " << dailyhrs << endl;
    cout << "Days he was present : " << days << endl;
    return total;
}

int main(){
    srand(time(0));
    cout << "Welcome to Employee wage computation"<<endl;
    int workingDayInMonth =0;
    int dailyhrs=0;
    int totalWage = cond(dailyhrs, workingDayInMonth);
    cout << "Total wage of month is : " << totalWage;

}