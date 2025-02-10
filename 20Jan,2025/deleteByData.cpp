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

void display(Node* head){
    Node* temp = head;
    while(temp!=nullptr){
        cout << temp->data << " " ;
        temp = temp->next;
    }
    cout << endl;
}

void remove(int value, Node*& head){
    Node* temp = head;
    while(temp!=nullptr && temp->next != nullptr){
        if(temp->next->data == value){
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }else{
            temp = temp->next;
        }
    }
}

int main(){
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(40);
    head->next->next->next = new Node(30);

    display(head);

    remove(40,head);

    display(head);
}