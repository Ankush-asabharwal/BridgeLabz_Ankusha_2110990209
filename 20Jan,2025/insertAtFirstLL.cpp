#include<iostream>

using namespace std;

class Node {
    public :
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        next = nullptr;
    }
};

void traverse (Node* head)
{
    Node* temp = head;
    while(temp!= nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void insertAtFirst(int value, Node*& head){
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    insertAtFirst(0,head);

    traverse(head);
}