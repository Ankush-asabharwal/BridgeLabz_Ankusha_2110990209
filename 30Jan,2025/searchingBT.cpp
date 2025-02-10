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

bool search(Tree* root, int key) {
    if(root == NULL) return false;;
    queue<Tree*> q;
    q.push(root);
    while(!q.empty()){
        Tree* temp = q.front();
        q.pop();

        if(temp->data == key){
            return true;
        }
        if(temp->left!=NULL) q.push(temp->left);
        if(temp->right!=NULL) q.push(temp->right);
    }
    return false;
}

int main() {
    Tree* root = new Tree(1);
    root->left = new Tree(2);
    root->right = new Tree(3);
    root->left->left = new Tree(4);
    root->left->right = new Tree(5);
    root->right->left = new Tree(6);
    root->right->right = new Tree(7);

    if(search(root,8)){
        cout << "Element Found";
    }
    else{
        cout << "Element not Found";
    }
}