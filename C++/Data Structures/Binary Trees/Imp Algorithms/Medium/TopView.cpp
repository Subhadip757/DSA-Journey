#include <bits/stc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

static int idx = -1;
Node *buildTree(vector<int> preorder)
{
    idx++;

    if (preorder[idx] == -1)
    {
        return NULL;
    }

    Node *root = new Node(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);

    return root;
}

void topView(Node* root){
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    map<int, int> m;

    while(!q.empty()){
        auto [front, dist] = q.front();
        q.pop();

        if(m.find(dist) == m.end()){
            m[dist] = front -> data;
        }

        if(front -> left){
            q.push({front -> left, dist - 1});
        }
        if(front -> right){
            q.push({front -> right, dist + 1});
        }
    }

    for(auto it : m){
        cout<<it.second<<" ";
    }
}

int main()
{
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node *root = buildTree(preorder);

    topView(root);
}