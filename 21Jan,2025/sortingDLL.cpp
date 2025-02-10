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

void display(Node*& head){
    Node* temp = head;
    while(temp!=nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void sort(Node*& head){
    for(Node* i = head;i!=nullptr;i = i->next){
        for(Node* j = i->next;j!=nullptr;j = j->next){
            if(i->data > j->data){
                swap(i->data,j->data);
            }
        }
    }
}

int main() {
     Node* head = new Node(3);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(1);
    head->next->next->prev = head->next;
    sort(head);
    display(head);
}