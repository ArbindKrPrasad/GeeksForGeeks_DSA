#include<bits/stdc++.h>
using namespace std;
struct Node{
    int key;
    Node *left;
    Node *right;
    Node(int k){
        key = k;
        left = NULL;
        right = NULL;
    }
};
void inorderTraversal(Node* root){
    if(root!=NULL){
        inorderTraversal(root->left);
        cout<<root->key<<" ";
        inorderTraversal(root->right);
    }
}
void preorderTraversal(Node *root){
    if(root!=NULL){
        cout<<root->key<<" ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}
void postorderTraversal(Node* root){
    if(root!=NULL){
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout<<root->key<<" ";
    }
}

int height(Node* root){
    if(root==NULL) return 0;
    return (1+max(height(root->left),height(root->right)));
}

int main(){
    Node  *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);

    cout<<"Inorder Traversal: ";
    inorderTraversal(root);
    cout<<"\nPreorder Traversal: ";
    preorderTraversal(root);
    cout<<"\nPostOrder Traversal: ";
    postorderTraversal(root);

    cout<<"\nheight: "<<height(root);
}