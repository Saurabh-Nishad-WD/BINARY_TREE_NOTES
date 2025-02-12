

//BOUNDARY TRAVERSAL OF A BINARY TREE


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

bool isLeaf(Node *root){
    return root->left == NULL && root->right == NULL;
}


void addLeftBoundary(Node* root, vector<int> &res) {
    Node* cur = root->left;
    while (cur) {
        if (!isLeaf(cur)) res.push_back(cur->data);
        if (cur->left) cur = cur->left;
        else cur = cur->right;
    }
}

void addRightBoundary(Node* root, vector<int> &res) {
    Node* cur = root->right;
    vector<int> tmp;
    while (cur) {
        if (!isLeaf(cur)) tmp.push_back(cur->data);
        if (cur->right) cur = cur->right;
        else cur = cur->left;
    }
    for (int i = tmp.size()-1; i >= 0; --i) {
        res.push_back(tmp[i]);
    }
}

void addLeaves(Node* root, vector<int>& res) {
    if (isLeaf(root)) {
        res.push_back(root->data);
        return;
    }
    if (root->left) addLeaves(root->left, res);
    if (root->right) addLeaves(root->right, res);
}

vector<int> printBoundary(Node *root) {
    vector<int> res;
    if (!root) return res;
    if (!isLeaf(root)) res.push_back(root->data);
    addLeftBoundary(root, res);
    addLeaves(root, res);
    addRightBoundary(root, res);
    return res;
}


///////////////////////////////////////////////////////////////////////////

void printt(vector<int>& vec){
    if (vec.empty()) {  // Handle empty case
        cout << "Tree is empty!" << endl;
        return;
    }
    int n = vec.size();
    for(int i = 0;i<n;i++){
            cout<<vec[i]<<" ";
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
    vector<int> ans = printBoundary(root);
    printt(ans);
    free(root);
    return 0;
}