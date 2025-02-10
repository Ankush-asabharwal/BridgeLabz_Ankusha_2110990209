#include<iostream>
#include<queue>

using namespace std;

bool find(queue<int> q, int key){
    while(!q.empty()){
        if(q.front() == key) return true;
        q.pop();
    }
    return false;
}

int main() {
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);

    if(find(q,0)){
        cout << "Element found";
    }else{
        cout << "Element not found";
    }
}