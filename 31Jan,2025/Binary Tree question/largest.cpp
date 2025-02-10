#include<iostream>
#include<queue>

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

int largest(Tree* root) {
    if(root == NULL) return -1;
    int large = root->data;
    queue<Tree*> q;
    q.push(root);
    while(!q.empty()){
        Tree* temp = q.front();
        q.pop();
        large = max(large, temp->data);
        if(temp->left!=NULL) q.push(temp->left);
        if(temp->right!=NULL) q.push(temp->right);
    }
    return large;
}

int main() {
    Tree* root = new Tree(5);
    root->left = new Tree(9);
    root->right = new Tree(8);
    root->left->left = new Tree(4);
    root->left->right = new Tree(5);
    root->right->left = new Tree(6);
    root->right->right = new Tree(7);

    cout << "Largest value : " << largest(root) << endl;
}