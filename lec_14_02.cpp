

//HEIGHT OF TREE BY LEVELORDER TREE TRAVERSAL



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

/////////////////////////////////////////////////////////////////////////

int height(Node* root){
    int ans = 0;
    if(root == NULL) return 0;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        ans = max(ans,size);
        for(int i = 0;i<size;i++){
            Node* node = q.front();
            q.pop();
            if(node -> left != NULL) q.push(node -> left);
            if(node -> right != NULL) q.push(node -> right);
        } 
    }
    return ans;
}

/////////////////////////////////////////////////////////////////////////

void printLevelOrder(vector<vector<int>>& vec){
    int n = vec.size();
    for(int i = 0;i<n;i++){
        int m = vec[i].size();
        for(int j = 0;j<m;j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }

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