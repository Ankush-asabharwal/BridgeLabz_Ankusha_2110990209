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

void reverse(Node*& head){
    Node* temp = head;
    while(temp!=nullptr){
        temp = temp->next;
    }
    while(temp!=head){
        cout
    }
}

int main() {

}