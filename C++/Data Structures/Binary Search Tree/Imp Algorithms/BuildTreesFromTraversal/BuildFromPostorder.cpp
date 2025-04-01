#include <iostream>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to construct tree from Postorder
TreeNode *buildTree(int post[], int &postIndex, int size)
{
    if (postIndex < 0)
        return nullptr;

    int rootValue = post[postIndex--];
    TreeNode *root = new TreeNode(rootValue);

    // Construct right and left subtrees
    root->right = buildTree(post, postIndex, size);
    root->left = buildTree(post, postIndex, size);

    return root;
}

int main()
{
    int post[] = {9, 15, 7, 20, 3};
    int size = sizeof(post) / sizeof(post[0]);
    int postIndex = size - 1;

    TreeNode *root = buildTree(post, postIndex, size);

    cout << "Tree constructed from Postorder Traversal." << endl;

    return 0;
}