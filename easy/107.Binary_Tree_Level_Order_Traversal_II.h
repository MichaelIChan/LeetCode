/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values.
(ie, from left to right, level by level from leaf to root).

For example:

Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7

return its bottom-up level order traversal as:

[
  [15,7],
  [9,20],
  [3]
]
*/

#include <algorithm>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> levelOrder = vector<vector<int>>();
        if (root == nullptr) return levelOrder;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> level = vector<int>();
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front(); q.pop();
                level.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            levelOrder.push_back(level);
        }
        std::reverse(levelOrder.begin(), levelOrder.end());
        return levelOrder;
    }
};