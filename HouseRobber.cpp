#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

// DFS function returning {rob, notRob}
pair<int,int> dfs(TreeNode* root) {
    if (!root) return {0, 0};

    auto left = dfs(root->left);
    auto right = dfs(root->right);

    int rob = root->val + left.second + right.second;
    int notRob = max(left.first, left.second) +
                 max(right.first, right.second);

    return {rob, notRob};
}

int rob(TreeNode* root) {
    auto res = dfs(root);
    return max(res.first, res.second);
}

int main() {
    /*
        Example 1:
              3
             / \
            2   3
             \   \
              3   1
        Output: 7
    */

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(1);

    cout << "Maximum money robbed: " << rob(root) << endl;

    return 0;
}
