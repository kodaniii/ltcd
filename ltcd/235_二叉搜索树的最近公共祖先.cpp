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
        if (node->val > p->val && node->val > q->val) {
            return traversal(node->left, p, q);
        }
        if (node->val < p->val && node->val < q->val) {
            return traversal(node->right, p, q);
        }
        return node;
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