#include<iostream>

using namespace std;

class Node{
    public: 
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        next = nullptr;
    }
};

bool search(int find, Node* head){
    Node* temp = head;
    while(temp!=nullptr){
        if(temp->data == find){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main(){
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    if(search(50,head)){
        cout << "Found" << endl;
    }else{
        cout << "Not Found" << endl;
    }
}