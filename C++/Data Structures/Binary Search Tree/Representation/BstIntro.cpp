#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int size)
    {
        data = size;
        left = right = NULL;
    }
};

// Insert a node into the BST
Node *insert(Node *root, int x)
{
    if (root == NULL)
    {
        Node *temp = new Node(x);
        return temp;
    }
    if (root->data > x)
    {
        root->left = insert(root->left, x);
    }
    else
    {
        root->right = insert(root->right, x);
    }
    return root;
}

// Search for a value in the BST
bool search(Node *root, int x)
{
    if (root == nullptr)
    {
        return false;
    }
    if (root->data == x)
    {
        return true;
    }
    else if (root->data > x)
    {
        return search(root->left, x);
    }
    else
    {
        return search(root->right, x);
    }
}

// Find the minimum value node in a BST
Node *findMin(Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

// Delete a node from the BST
Node *deleteNode(Node *root, int x)
{
    if (root == NULL)
    {
        return root; // Node not found
    }
    if (!root->left && !root->right)
    {
        delete root;
        return NULL;
    }
    if (x < root->data)
    {
        root->left = deleteNode(root->left, x);
    }
    else if (x > root->data)
    {
        root->right = deleteNode(root->right, x);
    }
    else
    {
        // Node to be deleted found
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: Get inorder successor
        Node *temp = findMin(root->right);
        root->data = temp->data;                           // Copy the inorder successor's value
        root->right = deleteNode(root->right, temp->data); // Delete the successor
    }
    return root;
}

// Inorder traversal of the BST
void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    vector<int> arr = {20, 9, 5, 19, 36, 15, 26, 17, 30, 21};
    Node *root = NULL;

    // Insert nodes into the BST
    for (int i = 0; i < arr.size(); i++)
    {
        root = insert(root, arr[i]);
    }

    // Insert another node
    insert(root, 31);

    // Perform inorder traversal
    cout << "Inorder traversal before deletion: ";
    inorder(root);
    cout << endl;

    cout << "Preorder traversal before deletion: ";
    preorder(root);
    cout << endl;

    // Delete a node
    root = deleteNode(root, 19);

    // Perform preorder traversal after deletio
    cout << "PreOrder traversal after deleting 19: ";
    preorder(root);
    cout << endl;

    cout << "Inorder traversal after deleting 19: ";
    inorder(root);
    cout << endl;

    // Search for a value in the BST
    cout << (search(root, 21) ? "Present" : "Not Present") << endl;

    return 0;
}
