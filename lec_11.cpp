

// ITERATIVE POSTORDER TREE TRAVERSAL (2 - Stack)



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

vector<int> I_postorder(Node* root){
    vector<int> ans;
    if(root == NULL) return ans;
    stack<Node*> st1,st2;
    Node* node = root;
    st1.push(node);
    while(!st1.empty()){
        node = st1.top();
        st2.push(node);
        st1.pop();
        if(node->left != NULL)st1.push(node->left);
        if(node->right != NULL)st1.push(node->right);
    }
    while(!st2.empty()){
        ans.push_back(st2.top()->data);
        st2.pop();
    }
 return ans;
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
    vector<int> vec = I_postorder(root);
    printLevelOrder(vec);
    cout<<endl;
    free(root);
    return 0;
}