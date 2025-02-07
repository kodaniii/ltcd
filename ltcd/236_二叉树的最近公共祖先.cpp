#include <iostream>

using namespace std; 

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    TreeNode* traversal(TreeNode* node, TreeNode* p, TreeNode* q) {
        if (!node) return NULL;
        if (node == p || node == q) return node;
        //◊Û”“
        TreeNode* left = traversal(node->left, p, q);
        TreeNode* right = traversal(node->right, p, q);
        //÷–¥¶¿Ì
        if (left && right) return node;
        else if (!left && right) return right;
        else if (left && !right) return left;
        else return NULL;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return traversal(root, p, q);
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */