#include<iostream>
#include<queue>

using namespace std;

void insert(queue<int> &q, int value){
    queue<int> temp;
    temp.push(value);
    while(!q.empty()){
        temp.push(q.front());
        q.pop();
    }
    q = temp;
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

    insert(q,5);
    cout << "After insertion : ";
    traverse(q);
}