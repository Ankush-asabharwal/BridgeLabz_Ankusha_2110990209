#include<iostream>

using namespace std;

struct Tree {
    int data;
    Tree* left;
    Tree* right;
    Tree(int v) {
        data = v;
        left = right = NULL;
    }
};

Tree* insert(Tree* root, int key){
    if(root == NULL) return new Tree(key);
    if(key<root->data) root->left = insert(root->left, key);
    else root->right = insert(root->right,key);
    return root;
}

int lca(Tree* root, int A, int B) {
    if(root == NULL) return -1;
    if(root->data == A || root->data == B) return root->data;
    if(root->data > A && root->data > B) return lca(root->left, A, B);
    if(root->data < A && root->data < B) return lca(root->right, A, B);
    return root->data;
}

int main() {
    Tree* root = NULL;
    root = insert(root,50);
    insert(root,30);
    insert(root,20);
    insert(root,40);
    insert(root,70);
    insert(root,60);
    insert(root,80);
    cout << "LCA(20,40) : " << lca(root,20,40) << endl;
    cout << "LCA(60,80) : " << lca(root,60,80) << endl;
    cout << "LCA(20,80) : " << lca(root,20,80) << endl;
}