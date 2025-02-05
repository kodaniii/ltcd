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
    /*µÝ¹é*/
    TreeNode* traversal(TreeNode* node, int& val) {
        if (!node || node->val == val) return node;
        TreeNode* result = nullptr;
        if (val < node->val) result = traversal(node->left, val);
        if (val > node->val) result = traversal(node->right, val);
        return result;
    }

    /*µü´ú*/
    TreeNode* search(TreeNode* node, int& val) {
        while (node) {
            if (val < node->val) node = node->left;
            else if (val > node->val) node = node->right;
            else return node;
        }
        return nullptr;
    }
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        return traversal(root, val);
        //return search(root, val);
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