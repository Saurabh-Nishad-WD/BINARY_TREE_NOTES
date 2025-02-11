

// PREORDER TREE TRAVERSAL


#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int a){
        data = a;
        left = right = NULL;
    }
};


void preorder(Node* node){
    if(node == NULL){
        return;
    }
    cout<<node-> data<<" ";
    preorder(node->left);
    preorder(node->right);
}


int main(){
    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> right -> left = new Node(4);
    root -> right -> right = new Node(0);
    preorder(root);
    cout<<endl;
    return 0;
}