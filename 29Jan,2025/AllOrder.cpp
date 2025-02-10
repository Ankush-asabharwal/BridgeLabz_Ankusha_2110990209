#include <cstddef>
#include<iostream>

using namespace std;

struct Tree {
    int data;
    Tree* left;
    Tree* right;
    Tree(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void inorder(Tree* root) {
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Tree* root){
    if(root==NULL) return;
    cout << root->data<< " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Tree* root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data<< " ";
}

int main() {
    Tree* root = new Tree(1);
    root->left = new Tree(2);
    root->right = new Tree(3);
    root->left->left = new Tree(4);
    root->left->right = new Tree(5);

    cout << "Inorder Traversal : ";
    inorder(root);
    cout<<endl;

    cout << "Preorder Traversal : ";
    preorder(root);
    cout<<endl;

    cout << "Postorder Traversal : ";
    postorder(root); 

}