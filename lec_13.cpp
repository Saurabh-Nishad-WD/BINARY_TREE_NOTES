

// ITERATIVE [PRE-IN-POST] ORDER IN SINGLE TREE TRAVERSAL                    



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

vector<vector<int>> all_in_one(Node* root){
    Node* node = root;
stack<pair<Node*,int>> st;
st.push({node,1});
vector<int> pre,in,post;
while(!st.empty()){
    auto it = st.top();
    st.pop();
    if(it.second == 1){
        pre.push_back(it.first -> data);
        it.second++;
        st.push(it);
        if(it.first -> left != NULL){
            st.push({it.first -> left,1});
        }
    }
    else if(it.second == 2){
        in.push_back(it.first -> data);
        it.second++;
        st.push(it);
        if(it.first -> right != NULL){
            st.push({it.first -> right,1});
        }
    }
    else{
        post.push_back(it.first -> data);
    }
}
return {pre,in,post};
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
   vector< vector<int>> vec = all_in_one(root);

    cout<<"PRE : ";
    printLevelOrder(vec[0]);
    cout<<"IN : ";

    printLevelOrder(vec[1]);
    cout<<"POST : ";

    printLevelOrder(vec[2]);
    cout<<endl;
    free(root);
    return 0;
}