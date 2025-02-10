#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void insertAtBeginning(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (!head) {
        newNode->next = newNode;
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != head) temp = temp->next; // Reach the last node

    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}

void traverse(Node* head) {
    if (!head) return;
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    Node* head = new Node(2);
    head->next = new Node(3);
    head->next->next = head;

    cout << "Before Insertion: ";
    traverse(head);

    insertAtBeginning(head, 1);

    cout << "After Insertion at Beginning: ";
    traverse(head);

    return 0;
}
// 2*h3533Q