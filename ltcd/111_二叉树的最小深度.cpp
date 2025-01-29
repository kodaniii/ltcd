#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int getMinDepth(TreeNode* root) {
        if (!root) return 0;
        int leftDepth = getMinDepth(root->left);
        int rightDepth = getMinDepth(root->right);
        if (!root->left && root->right) return rightDepth + 1;
        if (root->left && !root->right) return leftDepth + 1;
        return min(leftDepth, rightDepth) + 1;
    }
public:
    int minDepth(TreeNode* root) {
        return getMinDepth(root);
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
