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

void traverse(Node* head){
    Node* temp = head;
    while(temp!=nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void insertEnd(int value, Node*& head){
    Node* temp = head;
    Node* newNode = new Node(value);
    while(temp->next!=nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    insertEnd(40,head);

    traverse(head);
}
