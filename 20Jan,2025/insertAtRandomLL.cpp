#include<iostream>

using namespace std;

class Node{
    public :
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        next = nullptr;
    }
};

void display(Node*& head){
    Node* temp = head;
    while(temp!=nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void insertRandom(int value, Node*& head, int index){
    int count = 1;
    Node* temp = head;
    Node* newNode = new Node(value);
    while(count!=index){
        temp = temp->next;
        count++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(40);

    insertRandom(30,head,2);

    display(head);
}