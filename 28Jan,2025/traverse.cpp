#include<iostream>
#include<queue>

using namespace std;

void traverse(queue<int> q){
    while(!q.empty()){
        cout<< q.front() << " ";
        q.pop();
    }
}

int main() {
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    traverse(q);
}