#include<iostream>

#include<string>

using namespace std;

bool isAlphaNumeric(char ch){
    if(ch>='0' && ch<='9' ||
       tolower(ch)>='a' && tolower(ch)<='z'){
        return true;
       }
       return false;
}

bool isPlaindrome(string s){
    int st = 0, end = s.length()-1;
    while(st<=end){
        if(!isAlphaNumeric(st)){
            st++;
            continue;
        }
        if(!isAlphaNumeric(end)){
            end--;
            continue;
        }
        if(tolower(s[st]) != tolower(s[end])){
            return false;
        }
    }
    return true;
}

int main(){
    string s = "a#e?3e&a";
    cout << isPlaindrome(s) << endl;
    
    // string str = "ankusha";
    // string result = str;
    // reverse(str.begin(),str.end());
    // if(str == result){
    //     cout << "yes it is a palindrome";
    // }else{
    //     cout << "No it is not a palindrome";
    // }
    // cout << endl;
}