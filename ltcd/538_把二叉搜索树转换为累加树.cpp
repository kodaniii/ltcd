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
    int pre = 0;
    TreeNode* traversal(TreeNode* node) {
        if (!node) return nullptr;
        //ÓÒ
        node->right = traversal(node->right);
        //ÖÐ´¦Àí
        node->val += pre;
        pre = node->val;
        //×ó
        node->left = traversal(node->left);
        return node;
    }
public:
    TreeNode* convertBST(TreeNode* root) {
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