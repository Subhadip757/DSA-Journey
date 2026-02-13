#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class SegmentTree{
public:
    class Node{
    public:
        int val;
        pair<int, int> range;
        Node* left;
        Node* right;

        Node(pair<int, int> range){
            this -> range = range;
            this -> left = NULL;
            this -> right = NULL;
        }
    };

    Node* root;
    SegmentTree(vector<int> arr){
        this -> root = construct(arr, 0, arr.size() - 1);
    }

    Node* construct(vector<int> arr, int start, int end){
        if(start == end){
            Node* leaf = new Node({start, end});
            leaf -> val = arr[start];
            return leaf;
        }
        
        Node* node = new Node({start, end});
        int mid = start + (end - start)/2;

        node -> left = this -> construct(arr, start, mid);
        node -> right = this -> construct(arr, mid + 1, end);
        node -> val = node -> left -> val + node -> right -> val;
        return node;
    }

    private:
    int query(int start, int end){
        return this -> query(this -> root, start, end);
    }

    public:
    int query(Node* root, int start, int end){
        if(root -> range.first >= start && root -> range.second <= end) 
            return root -> val;
        else if(root -> range.first > start || root -> range.second < end) 
            return 0; 
        return this -> query(root -> left, start, end) + query(root -> right, start, end);
    }

    private:
    void update(int idx, int value){
        update(root, idx, value);
    }

    public:
    int update(Node* root, int index, int value){
        if(index >= root -> range.first && index <= root -> range.second){
            if(index == root -> range.first && index == root -> range.second){
                root -> val = value;
                return root -> val;
            }
            int leftVal = 0, rightVal = 0;
            if(root->left && index <= root->left->range.second)
                leftVal = update(root -> left, index, value);
            if(root->right && index >= root->right->range.first)
                rightVal = update(root -> right, index, value);

            root->val = (root->left ? root->left->val : 0) + (root->right ? root->right->val : 0);
            return root->val;
        }
        return root->val;
    }

    public:
    void display() {
        display(this->root, 0);
    }

    private:
    void display(Node* node, int level) {
        if (!node) return;

        // indentation to visualize tree depth
        for (int i = 0; i < level; i++) cout << "    ";

        cout << "[" << node->range.first << ", "
             << node->range.second << "] -> "
             << node->val << "\n";

        display(node->left, level + 1);
        display(node->right, level + 1);
    }
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr = {2, 3, 7, -5};

    SegmentTree *tree = new SegmentTree(arr);

    tree -> display();

    return 0;
}