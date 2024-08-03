#include <iostream>

using namespace std;

class node{
    public:
        int data;
        node* left = NULL;
        node* right = NULL;

    node(int val){
        this -> data = val;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node* buildTree(node* &root){
    cout<<"Enter data for root node: ";
    int data;
    cin >> data;

    root = new node(data);
    
    cout<<endl;

    if(data == -1){
        return NULL;
    }

    cout<<"Enter the value at left of "<<data<<endl;
    root -> left = buildTree(root -> left);

    cout<<"Enter the value at right of "<<data<<endl;
    root -> right = buildTree(root -> right);

    return root;
}

void inorder(node* root){
    if(root == NULL){
        return;
    }

    inorder(root -> left);
    cout<<root->data<<" ";
    inorder(root -> right);
}

int main(){
    node* root = NULL;

    root = buildTree(root);

    cout<<endl;

    inorder(root);


    return 0;
}