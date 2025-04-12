#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to build a tree from inorder traversal
TreeNode *bt(vector<int> &inorder, int start, int end)
{
    if (start > end)
    {
        return nullptr;
    }

    int mid = start + (end - start) / 2;
    TreeNode *root = new TreeNode(inorder[mid]);

    root->left = bt(inorder, start, mid - 1);
    root->right = bt(inorder, mid + 1, end);

    return root;
}

void printInorder(TreeNode *root)
{
    if (!root)
        return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main()
{
    vector<int> inorder = {1, 2, 3, 4, 5, 6, 7};
    TreeNode *root = bt(inorder, 0, inorder.size() - 1);

    cout << "Inorder Traversal of Constructed Tree: ";
    printInorder(root);
    cout << endl;

    return 0;
}
