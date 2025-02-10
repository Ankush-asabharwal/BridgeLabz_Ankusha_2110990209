#include<iostream>
#include<queue>

using namespace std;

void sorting(queue<int>& q){
    vector<int> v;
    while(!q.empty()){
        v.push_back(q.front());
        q.pop();
    }

    sort(v.begin(),v.end());

    for(int val : v){
        q.push(val);
    }
}

void traverse(queue<int> q) {
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    queue<int> q;
    q.push(40);
    q.push(10);
    q.push(30);
    q.push(50);

    cout << "Before Sorting : ";
    traverse(q);

    cout << "After Sorting : ";
    sorting(q);
    traverse(q);

}