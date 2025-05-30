#include <bits/stc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
};

pair<int, int> calculateSubtree(Node *root, double &maxAvg)
{
    if (!root)
    {
        return {0, 0};
    }

    auto left = calculateSubtree(root->left, maxAvg);
    auto right = calculateSubtree(root->right, maxAvg);

    int sum = root->data + left.first + right.first;
    int count = 1 + left.second + right.second;

    double avg = static_cast<double>(sum) / count;
    maxAvg = std::max(maxAvg, avg);

    return {sum, count};
}

double maxSubtreeAverage(Node *root)
{
    if (!root)
        return 0.0;

    double maxAvg = -1e9; // Initialize to a very small number
    calculateSubtree(root, maxAvg);

    return maxAvg;
}