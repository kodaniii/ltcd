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

class Solution1 {
private:
    long long last_val = LONG_MIN;
    bool traversal(TreeNode* node) {
        if (!node) return true;
        //左
        bool left = traversal(node->left);
        //中处理
        if (last_val < node->val) {
            last_val = node->val;
        }
        else return false;
        //右
        bool right = traversal(node->right);
        return left && right;
    }
public:
    bool isValidBST(TreeNode* root) {
        return traversal(root);
    }
};

class Solution {
private:
    TreeNode *pre = nullptr;
    bool traversal(TreeNode* node) {
        if (!node) return true;
        //左
        bool left = traversal(node->left);
        //中处理
        if (!pre) pre = node;
        else if (pre->val < node->val) pre = node;
        else return false;
        //右
        bool right = traversal(node->right);
        return left && right;
    }
public:
    bool isValidBST(TreeNode* root) {
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