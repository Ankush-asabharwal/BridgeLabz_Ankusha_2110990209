#include <cstddef>
#include<iostream>

using namespace std;

struct Tree {
    int data;
    Tree* left;
    Tree* right;
    Tree(int value) {
        data =  value;
        left = right = NULL;
    }
};

int height(Tree* root) {
    if(root == NULL) return 0;
    return max(height(root->left),height(root->right)) +1;
}

int main() {
    Tree* root = new Tree(1);
    root->left = new Tree(2);
    root->right = new Tree(3);
    root->left->left = new Tree(4);
    root->left->right = new Tree(5);
    root->right->left = new Tree(6);
    root->right->right = new Tree(7);

    cout << "Height of the tree is : " << height(root);
}