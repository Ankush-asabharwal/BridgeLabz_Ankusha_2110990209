#include<iostream>

using namespace std;

class Node{
    public :
    int data;
    Node* prev;
    Node* next;
    Node(int data){
        this->data = data;
        prev = nullptr;
        next = nullptr;
    }
};

bool search(Node*& head, int value){
    Node* temp = head;
    while(temp!=nullptr){
        if(temp->data == value){
            return true;
        }else{
            temp = temp->next;
        }
    }
    return false;
}

int main() {
     Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    if(search(head,25)){
        cout << "Found" << endl;
    }else{
        cout << "Not Found" << endl;
    }
}