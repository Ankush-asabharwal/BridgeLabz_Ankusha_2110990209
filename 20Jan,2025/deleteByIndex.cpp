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

void display(Node* head){
    Node* temp = head;
    while(temp!=nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void remove(Node*& head,int index){
    if (index <= 0) return;  
    if (index == 1) { 
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    int count = 1;
    Node* temp = head;
    while(count!=index){
        temp = temp->next;
        count++;
    }
    if (temp != nullptr && temp->next != nullptr) {
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }
}

int main(){
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(40);
    head->next->next->next = new Node(30);

    remove(head,2);

    display(head);
}