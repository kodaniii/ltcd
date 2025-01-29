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
    //普通二叉树
    int getCount(TreeNode* node) {
        if (!node) return 0;
        int leftCnt = getCount(node->left);
        int rightCnt = getCount(node->right);
        return leftCnt + rightCnt + 1;
    }
    //完全二叉树
    int getCount(TreeNode* node) {
        /*终止条件*/
        if (!node) return 0;
        //判断满二叉树
        TreeNode* left = node->left;
        TreeNode* right = node->right;
        int leftDepth = 0, rightDepth = 0;
        while (left) {
            left = left->left;
            leftDepth++;
        }
        while (right) {
            right = right->right;
            rightDepth++;
        }
        if (leftDepth == rightDepth) return (2 << leftDepth) - 1;

        //递归处理
        int leftCnt = getCount(node->left);
        int rightCnt = getCount(node->right);
        return leftCnt + rightCnt + 1;
    }
public:
    int countNodes(TreeNode* root) {
        return getCount(root);
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
