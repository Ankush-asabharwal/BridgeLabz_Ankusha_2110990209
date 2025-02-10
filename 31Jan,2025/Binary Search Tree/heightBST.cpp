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
    if(key < root->data) root->left = insert(root->left,key);
    else root->right = insert(root->right,key);
    return root;
}

int height(Tree* root) {
    if(root == NULL) return 0;
    return max(height(root->left),height(root->right)) + 1;
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

    cout << "Height of the tree is : " << height(root) << endl;

}