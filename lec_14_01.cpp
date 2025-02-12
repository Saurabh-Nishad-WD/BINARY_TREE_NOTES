

// HEIGHT OF THE TREE                    



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

int height(Node* root){
    if(root == NULL) return 0;
    int lh = height(root -> left);
    int rh = height(root -> right);
    return 1+max(lh,rh);
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
    
    cout<<height(root)<<endl;
    free(root);
    return 0;
}