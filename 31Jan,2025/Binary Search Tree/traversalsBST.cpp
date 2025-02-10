#include<iostream>

using namespace std;

struct Tree {
    int data;
    Tree* left;
    Tree* right;
    Tree( int val){
        data = val;
        left = right = NULL;
    }
};

Tree* insert(Tree* root, int key){
    if(root == NULL) return new Tree(key);
    if(key < root->data) root->left = insert(root->left,key);
    else root->right = insert(root->right,key);
    return root;
}

void inorder(Tree* root) {
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Tree* root) {
    if(root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Tree* root) {
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    Tree* root = NULL;
    root = insert(root,50);
    insert(root,30);
    insert(root,70);
    insert(root,20);
    insert(root,40);
    insert(root,60);
    insert(root,80);

    cout << "Inorder Traversal : ";
    inorder(root);
    cout << endl;

    cout << "Preorder Traversal : ";
    preorder(root);
    cout << endl;

    cout << "Postorder Traversal : ";
    postorder(root);
    cout << endl;
}