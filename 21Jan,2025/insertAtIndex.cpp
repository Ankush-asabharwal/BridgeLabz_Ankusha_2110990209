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

void insert(int value, int index, Node*& head){
    Node* newNode = new Node(value);
    if(!head){
        head = newNode;
        return;
    }
    Node* temp = head;
    int count = 1;
    while(count<index){
        temp = temp->next;
        count++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void display(Node*& head){
    Node* temp = head;
    while(temp!=nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
     Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    insert(54,2,head);
    display(head);
}