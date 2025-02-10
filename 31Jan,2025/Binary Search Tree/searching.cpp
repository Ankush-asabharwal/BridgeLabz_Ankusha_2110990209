#include<iostream>
#include<queue>
using namespace std;

struct Tree{
    int data;
    Tree* left;
    Tree* right;
    Tree(int val){
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

bool search(Tree* root, int val){
    if(root == NULL) return false;
    queue<Tree*> q;
    q.push(root);
    while(!q.empty()){
        Tree* temp = q.front();
        q.pop();
        if(temp->data == val) return true;
        if(temp->left!=NULL) q.push(temp->left);
        if(temp->right!=NULL) q.push(temp->right);
    }
    return false;
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

    if(search(root,80)){
        cout << "Element Found";
    }else{
        cout<< "Element Not Found";
    }
}