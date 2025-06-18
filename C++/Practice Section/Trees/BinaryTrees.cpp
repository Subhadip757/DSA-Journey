#include <bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int d){
            val = d;
            left = nullptr;
            right = nullptr;
        }
};


int idx = -1;
TreeNode* buildTree(vector<int> &preorder){
    idx++;
    if(preorder[idx] == -1){
        return NULL;
    }
    
    TreeNode* node = new TreeNode(preorder[idx]);
    node -> left = buildTree(preorder);
    node -> right = buildTree(preorder);
    return node;
}

void preorder(TreeNode* root){
    if(root == NULL) return;

    cout<<root -> val<<" ";
    preorder(root -> left);
    preorder(root -> right);
}

void lot(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();

        for(int i = 0; i < size; i++){
            TreeNode* temp = q.front();
            cout<<temp -> val<<" ";
            q.pop();

            if(temp -> left){
                q.push(temp -> left);
            }
            if(temp -> right){
                q.push(temp -> right);
            }
        }
        cout<<endl;
    }
}


int main(){
    vector<int> arr = {1, 3, 7, -1, -1, 11, -1, -1, 5, 17, -1, -1, -1};
    TreeNode* node = buildTree(arr);

    preorder(node);
    cout<<endl;
    lot(node);
}
