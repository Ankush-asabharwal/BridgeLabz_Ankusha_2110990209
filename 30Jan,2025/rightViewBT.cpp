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

void rightView(Tree* root){
    if(root == NULL) return;

    queue<Tree*> q;
    q.push(root);
    
    while(!q.empty()){
        int n = q.size();
        for(int i=0;i<n;i++){
            cout << q.size() << endl;
            Tree* temp = q.front();
            q.pop();
            cout << q.size() << endl;
            if(i == n-1){
                cout << temp->data << " ";
            }
            if(temp->left!=NULL){
                q.push(temp->left);
            }
            if(temp->right!=NULL){
                q.push(temp->right);
            }
        }
    }
}

int main() {
    Tree* root = new Tree(1);
    root->left = new Tree(2);
    root->right = new Tree(3);
    root->left->left = new Tree(4);
    root->left->right = new Tree(5);
    root->right->left = new Tree(6);
    root->right->right = new Tree(7);

    cout << "Right view of binary Tree : " << endl;
    rightView(root);
}