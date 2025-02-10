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

int find(Tree* root){
    if(root == NULL) return 0;
    int count = 0;
    queue<Tree*> q;
    q.push(root);
    while(!q.empty()){
        Tree* temp = q.front();
        count++;
        q.pop();
        if(temp->left!=NULL) q.push(temp->left);
        if(temp->right!=NULL) q.push(temp->right);
    }
    return count;
}

int main() {
    Tree* root = new Tree(1);
    root->left = new Tree(2);
    root->right = new Tree(3);
    root->left->left = new Tree(4);
    root->left->right = new Tree(5);
    root->right->left = new Tree(6);
    root->right->right = new Tree(7);
    // root->left->left->left = new Tree(8);
    cout << "Count of all the Nodes : " << find(root);
}