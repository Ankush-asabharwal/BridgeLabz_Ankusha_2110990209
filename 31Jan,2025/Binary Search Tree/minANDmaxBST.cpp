#include<iostream>
#include<queue>
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

int findMin(Tree* root){
    // //by queue
    // if(root == NULL) return -1;
    // int mini = root->data;
    // queue<Tree*> q;
    // q.push(root);
    // while(!q.empty()){
    //     Tree* temp = q.front();
    //     q.pop();
    //     mini = min(mini, temp->data);
    //     if(temp->left!=NULL) q.push(temp->left);
    //     if(temp->right!=NULL) q.push(temp->right);
    // }
    // return mini;
    while(root->left){
        root = root->left;
    }
    return root->data;
}

int findMax(Tree* root){
    //by queue
    // if(root == NULL) return -1;
    // int maxi = root->data;
    // queue<Tree*> q;
    // q.push(root);
    // while(!q.empty()){
    //     Tree* temp = q.front();
    //     q.pop();
    //     maxi = max(maxi, temp->data);
    //     if(temp->left!=NULL) q.push(temp->left);
    //     if(temp->right!=NULL) q.push(temp->right);
    // }
    // return maxi;
   
    while(root->right) root = root->right;
    return root->data;
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

    cout << "Minimum element in Tree is : " << findMin(root) << endl;
    cout << "Maximum element in Tree is : " << findMax(root) << endl;

}