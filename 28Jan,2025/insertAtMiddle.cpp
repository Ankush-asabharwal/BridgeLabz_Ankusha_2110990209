#include<iostream>
#include<queue>

using namespace std;

void insert(queue<int>& q, int value){
    queue<int> temp;
    int mid = q.size()/2;
    for(int i=0;i<mid;i++){
        temp.push(q.front());
        q.pop();
    }
    temp.push(value);
    for(int i=mid;i<=q.size()+1;i++){
        temp.push(q.front());
        q.pop();
    }
    q=temp;
}

void traverse(queue<int> q){
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
}

int main() {
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Before insertion : ";
    traverse(q);
    cout << endl;

    insert(q,15);
    cout << "After insertion : ";
    traverse(q);
}