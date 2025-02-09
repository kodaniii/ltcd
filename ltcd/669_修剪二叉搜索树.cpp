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
    TreeNode* traversal(TreeNode* node, int low, int high) {
        if (!node) return nullptr;
        if (node->val < low) {
            return traversal(node->right, low, high);
        }
        if (node->val > high) {
            return traversal(node->left, low, high);
        }
        node->left = traversal(node->left, low, high);
        node->right = traversal(node->right, low, high);
        return node;
    }
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return traversal(root, low, high);
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