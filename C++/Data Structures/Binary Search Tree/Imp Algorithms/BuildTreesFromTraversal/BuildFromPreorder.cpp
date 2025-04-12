#include <iostream>
#include <climits>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Helper function to build BST from preorder traversal
TreeNode *bt(int preorder[], int &index, int minVal, int maxVal, int size)
{
    if (index >= size)
        return nullptr;

    int key = preorder[index];
    if (key < minVal || key > maxVal)
        return nullptr;

    TreeNode *root = new TreeNode(key);
    index++;

    root->left = bt(preorder, index, minVal, key, size);
    root->right = bt(preorder, index, key, maxVal, size);

    return root;
}

// Wrapper function
TreeNode *constructBST(int preorder[], int size)
{
    int index = 0;
    return bt(preorder, index, INT_MIN, INT_MAX, size);
}

// Inorder traversal for checking
void inorderTraversal(TreeNode *root)
{
    if (!root)
        return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

// Driver code
int main()
{
    int preorder[] = {10, 5, 1, 7, 40, 50};
    int size = sizeof(preorder) / sizeof(preorder[0]);

    TreeNode *root = constructBST(preorder, size);

    cout << "Inorder Traversal of Constructed BST: ";
    inorderTraversal(root);
    return 0;
}