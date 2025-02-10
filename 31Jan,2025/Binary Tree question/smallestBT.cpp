#include <cstddef>
#include<iostream>
#include<queue>

using namespace std;

struct Tree {
    int data;
    Tree* left;
    Tree* right;
    Tree(int value){
        data = value;
        left = right = NULL;
    }
};

int smallest (Tree* root){
    if(root==NULL) return -1;
    int small=root->data;
    queue<Tree*> q;
    q.push(root);
    while(!q.empty()){
        Tree* temp = q.front();
        q.pop();
        small = min(small, temp->data);
        if(temp->left!=NULL) q.push(temp->left);
        if(temp->right!=NULL) q.push(temp->right);
    }
    return small;
}

int main() {
    Tree* root = new Tree(5);
    root->left = new Tree(9);
    root->right = new Tree(8);
    root->left->left = new Tree(4);
    root->left->right = new Tree(5);
    root->right->left = new Tree(6);
    root->right->right = new Tree(7);

    cout << "Smallest Element : " << smallest(root) << endl;
}