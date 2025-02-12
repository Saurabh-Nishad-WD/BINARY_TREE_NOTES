

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

int maxPathSum(Node* root,int &sum){
    if(root == NULL){ 
        return 0;
    }
    int ls = max(0, maxPathSum(root->left, sum));
    int rs = max(0, maxPathSum(root->right, sum));    
    sum = max(sum,(root->data)+(ls+rs));
    return (root->data)+max(ls,rs);
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
    int sum = INT_MIN;
   maxPathSum(root,sum);
   cout<<sum<<endl;
    free(root);
    return 0;
}