

// MAXIMUM PATH SUM OF A BINARY TREE

// NOTR::::::  INITILIZE THE VALUE OF SUM WITH int_min VALUE FOR PREVENTING WHEN ALL TREE NAODE HAS -VE VALUE;


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
////////////////////////////////////////////////////////////////////////

bool isSame(Node* root1, Node* root2) {
    if (root1 == NULL && root2 == NULL) return true;
    if (root1 == NULL || root2 == NULL) return false;

    return (root1->data == root2->data) &&
           isSame(root1->left, root2->left) &&
           isSame(root1->right, root2->right);
}


///////////////////////////////////////////////////////////////////////////

void printLevelOrder(vector<int>& vec){
    int m = vec.size();
        for(int j = 0;j<m;j++){
            cout<<vec[j]<<" ";
        }
        cout<<endl;
}

void free(Node* root) {
    if (root == NULL) return;
    free(root->left);
    free(root->right);
    delete root;
}


int main(){
    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(9);
    root -> right -> left = new Node(4);
    root -> right -> right = new Node(0);
   cout<<isSame(root,root)<<endl;
    free(root);
    return 0;
}