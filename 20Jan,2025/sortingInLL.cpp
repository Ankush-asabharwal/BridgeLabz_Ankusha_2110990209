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

void display(Node*& head){
    Node* temp = head;
    while(temp!=nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void sort(Node*& head){
    for(Node* i = head;i!=nullptr;i=i->next){
        for(Node* j = i->next;j!=nullptr;j=j->next){
            if(i->data > j->data){
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(30);
    head->next->next = new Node(20);

    sort(head);

    display(head);
}