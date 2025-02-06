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
    int thisCnt = 0;
    int maxCnt = 0;
    TreeNode* pre = nullptr;
    vector<int> res;
    void traversal(TreeNode* node) {
        if (!node) return;
        //×ó
        traversal(node->left);
        //ÖÐ´¦Àí
        if (!pre) thisCnt = 1;
        else if (pre->val == node->val) thisCnt++;
        else thisCnt = 1;
        pre = node;
        if (thisCnt == maxCnt) res.push_back(node->val);
        if (thisCnt > maxCnt) {
            maxCnt = thisCnt;
            res.clear();
            res.push_back(node->val);
        }
        //ÓÒ
        traversal(node->right);
        return;
    }
public:
    vector<int> findMode(TreeNode* root) {
        traversal(root);
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