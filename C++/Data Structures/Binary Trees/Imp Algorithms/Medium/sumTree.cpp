#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

Node *buildTreeFromPreorder(const std::vector<int> &preorder, int &idx)
{
    if (idx >= preorder.size() || preorder[idx] == -1)
    {
        idx++;
        return nullptr;
    }

    Node *root = new Node(preorder[idx++]);

    root->left = buildTreeFromPreorder(preorder, idx);
    root->right = buildTreeFromPreorder(preorder, idx);

    return root;
}

// Convert a binary tree to a Sum Tree
template<typename T>
T toSumTreeUtil(Node* root) {
    if (!root) return 0;
    int old_val = root->data;

    int left_sum = toSumTreeUtil<int>(root->left);
    int right_sum = toSumTreeUtil<int>(root->right);
    
    root->data = left_sum + right_sum;
    return root->data + old_val;
}

void toSumTree(Node* root) {
    toSumTreeUtil<int>(root);
}

// Inorder traversal to print the tree
void inorder(Node* root) {
    if (!root) return;

    inorder(root->left);
    cout << root->data << ' ';
    inorder(root->right);
}

int main()
{
    /*
        26
       /  \
      10   3
     / \    \
    4   6    3
    */

    // Example: Build tree from preorder with -1 as NULL
    vector<int> preorder = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    cout << "Preorder array used to build tree: ";

    for (int v : preorder) cout << v << ' ';
    cout << endl;
    int idx = 0;

    Node *root2 = buildTreeFromPreorder(preorder, idx);

    toSumTree(root2);
    cout << "Inorder traversal of the Sum Tree: ";
    inorder(root2);
    cout << endl;

    return 0;
}