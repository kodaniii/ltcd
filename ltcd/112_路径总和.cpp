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
    bool traversal(TreeNode* node, int sum, int& target) {
        //叶子节点，遍历结束
        if (!node->left && !node->right) {
            return (target == sum);
        }
        bool leftRet, rightRet;
        if (node->left) {
            leftRet = traversal(node->left, sum + node->left->val, target);
        }
        if (node->right) {
            rightRet = traversal(node->right, sum + node->right->val, target);
        }
        return leftRet || rightRet;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        int sum = root->val;
        return traversal(root, sum, targetSum);
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