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
    int traversal(TreeNode* node) {
        if (!node) return 0;
        //×ó
        int leftNum = traversal(node->left);
        if (node->left && !node->left->left && !node->left->right) {
            leftNum = node->left->val;
        }
        //ÓÒ
        int rightNum = traversal(node->right);
        //ÖÐ
        return leftNum + rightNum;
    }
    int leftNum, rightNum;
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return traversal(root);
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
