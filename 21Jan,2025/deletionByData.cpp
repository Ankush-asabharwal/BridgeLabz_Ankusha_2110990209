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

void remove(int value, Node*& head){
    Node* temp = head;
    while(temp != nullptr){
        if(temp->data == value){
            if(temp == head){
                head = temp->next;
                if(head != nullptr){
                    head->prev = nullptr;
                }
            } else {
                if(temp->prev != nullptr){
                    temp->prev->next = temp->next;
                }
                if(temp->next != nullptr){
                    temp->next->prev = temp->prev;
                }
            }
            delete temp; 
            return;      
        }
        temp = temp->next;
    }
}

int main() {
     Node* head = new Node(3);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(1);
    head->next->next->prev = head->next;
    remove(1,head);
    display(head);
}