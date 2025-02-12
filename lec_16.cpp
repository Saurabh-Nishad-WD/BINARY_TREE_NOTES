

// CHECKING FOR A BALANCED BINARY TREE

// NOTR::::::  IF WE MAKE BOOL RETURN TYPE FUNCTION FOR CHEKING BALANCING THAN ITS TC BECOME O(n^2) THAT'S WHY WE TRY TO RETURN INTEGAR FOR O(n^1) TC



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

int diameter(Node* root,int &dia){
    if(root == NULL){ 
        return 0;
    }
    int lh = diameter(root -> left,dia);
    int rh = diameter(root -> right,dia);
    dia = max(dia,lh+rh);
    return max(lh,rh)+1;
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
    int dia = 0;
   diameter(root,dia);
   cout<<dia<<endl;
    free(root);
    return 0;
}