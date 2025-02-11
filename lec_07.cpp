

// POSTORDER TREE TRAVERSAL



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


void postorder(Node* node){
    if(node == NULL){
        return;
    }
    postorder(node->left);
    postorder(node->right);
    cout<<node-> data<<" ";
}


int main(){
    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> right -> left = new Node(4);
    root -> right -> right = new Node(0);
    postorder(root);
    cout<<endl;
    return 0;
}