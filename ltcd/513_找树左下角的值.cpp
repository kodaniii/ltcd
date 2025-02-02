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
    int maxDepth = -1;
    int res;
    void traversal(TreeNode* node, int depth) {
        if (!node->left && !node->right) {
            if (depth > maxDepth) {
                maxDepth = depth;
                res = node->val;
            }
            return;
        }
        //×óÓÒ
        if (node->left) {
            traversal(node->left, depth + 1);
        }
        if (node->right) {
            traversal(node->right, depth + 1);
        }
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        traversal(root, 0);
        return res;
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