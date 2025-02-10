#include <iostream>
#include <algorithm> // For sorting
using namespace std;

#define MAX 100  // Maximum size of stack

int stack[MAX];  // Stack array
int top = -1;    // Top pointer

int main() {
    int choice, value;

    do {
        cout << "\nChoose an operation:\n";
        cout << "1. Push\n2. Pop\n3. Peek\n4. Display\n5. Search\n6. Sort\n7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) { // Push
            if (top >= MAX - 1) {
                cout << "Stack Overflow!\n";
            } else {
                cout << "Enter value to push: ";
                cin >> value;
                stack[++top] = value;
                cout << value << " pushed into the stack.\n";
            }
        } 
        else if (choice == 2) { // Pop
            if (top < 0) {
                cout << "Stack Underflow!\n";
            } else {
                cout << stack[top--] << " popped from the stack.\n";
            }
        } 
        else if (choice == 3) { // Peek
            if (top < 0) {
                cout << "Stack is empty!\n";
            } else {
                cout << "Top element: " << stack[top] << endl;
            }
        } 
        else if (choice == 4) { // Display
            if (top < 0) {
                cout << "Stack is empty!\n";
            } else {
                cout << "Stack elements: ";
                for (int i = top; i >= 0; i--) {
                    cout << stack[i] << " ";
                }
                cout << endl;
            }
        } 
        else if (choice == 5) { // Search
            cout << "Enter element to search: ";
            cin >> value;
            bool found = false;
            for (int i = 0; i <= top; i++) {
                if (stack[i] == value) {
                    cout << value << " found in stack at position " << (top - i) << endl;
                    found = true;
                    break;
                }
            }
            if (!found) cout << value << " not found in stack.\n";
        } 
        else if (choice == 6) { // Sort
            if (top < 0) {
                cout << "Stack is empty!\n";
            } else {
                sort(stack, stack + top + 1);
                cout << "Stack sorted in ascending order.\n";
            }
        } 
        else if (choice == 7) { // Exit
            cout << "Exiting...\n";
        } 
        else {
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 7);

    return 0;
}
