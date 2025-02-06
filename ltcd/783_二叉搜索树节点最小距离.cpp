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
    TreeNode* last_node = nullptr;
    int minDiff = INT_MAX;
    void traversal(TreeNode* node) {
        if (!node) return;
        //��
        traversal(node->left);
        //�д���
        if (last_node) {
            int thisDiff = abs(node->val - last_node->val);
            if (thisDiff < minDiff) minDiff = thisDiff;
        }
        last_node = node;
        //��
        traversal(node->right);
        return;
    }
public:
    int minDiffInBST(TreeNode* root) {
        traversal(root);
        return minDiff;
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