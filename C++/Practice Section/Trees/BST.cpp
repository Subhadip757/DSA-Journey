#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    int data;
    Node* left, *right;

    Node(int size){
        data = size;
        left = right = NULL;
    }
};

Node* insert(Node* root, int x){
    if(root == NULL){
        Node* temp = new Node(x);
        return temp;
    }
    if(root->data > x){
        root -> left = insert(root->left, x);
    }
    else{
        root->right = insert(root->right, x);
    }
    return root;
}

bool search(Node* root, int x){
    if(root == nullptr){
        return false;
    }
    if(root->data == x){
        return true;
    }
    else if(root->data > x){
        return search(root->left, x);
    }
    else{
        return search(root->right, x);
    }
}

Node* deleteNode(Node* root, int x){
    
}

void inorder(Node* root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data <<" ";
    inorder(root->right);
}

int main(){
    vector<int> arr = {2, 9 ,5, 19, 36, 26, 17, 30, 21};
    Node* root = NULL;
    
    for(int i = 0; i < arr.size(); i++){
        root = insert(root, arr[i]);    
    }

    insert(root, 31);

    inorder(root);
    cout<<endl;
    cout<<(search(root, 28) ? "Present" : "Not Present");
}