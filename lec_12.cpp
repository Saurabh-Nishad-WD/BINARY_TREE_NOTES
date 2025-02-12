

// ITERATIVE POSTORDER TREE TRAVERSAL (1 - Stack)                    ERROR ERROR  ERROR ERROR  ERROR ERROR  ERROR ERROR 



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
    stack<Node*> st;
    Node* node = root;
    st.push(node);
   while(node != NULL || !st.empty()){
    if(node != NULL){
        st.push(node);
        node = node -> left;
    }
else{
    Node* temp = st.top() -> right;
    if(temp == NULL){
        temp = st.top();
        st.pop();
        ans.push_back(temp -> data);
        while(!st.empty() && temp == st.top() -> right){
            temp = st.top();
            st.pop();
            ans.push_back(temp -> data);
        }
    }
    else{
        node = temp;
    }
}
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