

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

vector<vector<int>> zic_zac(Node* root){
    vector<vector<int>> ans;
    if(root == NULL){
        return ans;
    }
    queue<Node*> q;
    q.push(root);
    bool flg = true;
    while(!q.empty()){
        int size = q.size();
        vector<int> row(size);
        for(int i = 0;i<size;i++){
            Node* node = q.front();
            q.pop();
            int index = (flg)?i:(size-i-1);
            row[index] = node->data;
            if(node->left){
                q.push(node->left);
            }
            if(node -> right){
                q.push(node->right);
            }
        }
        flg = !flg;
        ans.push_back(row);
    }
    return ans;

}


///////////////////////////////////////////////////////////////////////////

void printt(vector<vector<int>>& vec){
    if (vec.empty()) {  // Handle empty case
        cout << "Tree is empty!" << endl;
        return;
    }
    int n = vec.size();
    for(int i = 0;i<n;i++){
        int m = vec[i].size();
        for(int j = 0;j<m;j++){
            cout<<vec[i][j]<<" ";
        }
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
    vector<vector<int>> result = zic_zac(root);
    printt(result);
    free(root);
    return 0;
}