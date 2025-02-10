#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    vector<int> vec = {2, 3, 5, 1, 4};
    sort(vec.begin(), vec.end());
    for(int v : vec){
        cout << v << " ";
    }
}