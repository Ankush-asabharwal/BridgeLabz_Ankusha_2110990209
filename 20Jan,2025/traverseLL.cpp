#include<iostream>
#include <new>

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

void traverse(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    traverse(head);
}