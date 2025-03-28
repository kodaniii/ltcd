#include <iostream>
#include <vector>

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
public:
    //dp[0]≤ªÕµ£¨dp[1]Õµ
    vector<int> robTree(TreeNode* node) {
        if (node == nullptr) return vector<int>{ 0, 0 };
        //◊Û”“÷–
        vector<int> left = robTree(node->left);
        vector<int> right = robTree(node->right);
        //Õµ
        int first_val = node->val + left[0] + right[0];
        //≤ªÕµ
        int second_val = max(left[0], left[1]) + max(right[0], right[1]);
        return vector<int>{second_val, first_val};
    }
    int rob(TreeNode* root) {
        vector<int> res = robTree(root);
        return max(res[0], res[1]);
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