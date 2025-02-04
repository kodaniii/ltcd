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
private:
    TreeNode* traversal(vector<int>& nums) {
        //终止条件
        if (nums.size() == 0) return nullptr;
        //找到中间节点
        int maxIdx = -1, maxVal = INT_MIN;
        for (int idx = 0; idx < nums.size(); idx++) {
            if (nums[idx] > maxVal) {
                maxIdx = idx;
                maxVal = nums[idx];
            }
        }
        TreeNode* root = new TreeNode(maxVal);
        
        vector<int> leftNums(nums.begin(), nums.begin() + maxIdx);
        vector<int> rightNums(nums.begin() + maxIdx + 1, nums.end());

        root->left = traversal(leftNums);
        root->right = traversal(rightNums);

        return root;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return traversal(nums);
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