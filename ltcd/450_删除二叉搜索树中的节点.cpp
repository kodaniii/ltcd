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
    TreeNode* traversal(TreeNode* node, int key) {
        //遍历结束，未找到对应节点
        if (!node) return nullptr;
        //找到被删除节点
        if (node->val == key) {
            if (!node->left && !node->right) return nullptr;
            else if (!node->left && node->right) return node->right;
            else if (node->left && !node->right) return node->left;
            else {
                TreeNode* cur = node->right;
                while (cur->left) cur = cur->left;
                cur->left = node->left;
                
                return node->right;
            }
        }
        //递归
        if (node->val < key) node->right = traversal(node->right, key);
        if (node->val > key) node->left = traversal(node->left, key);
        return node;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        return traversal(root, key);
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