#include <iostream>
#include <vector>
#include <string>

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
    void traversal(TreeNode* node, vector<int>& path, vector<string>& res) {
        //中
        path.push_back(node->val);
        //遍历到叶子节点，该路径结束
        if (!node->left && !node->right) {
            string s_path;
            for (int i = 0; i < path.size() - 1; i++) {
                s_path += to_string(path[i]);
                s_path += "->";
            }
            s_path += to_string(path[path.size() - 1]);
            res.push_back(s_path);

            return;
        }
        //左右
        if (node->left) {
            traversal(node->left, path, res);
            path.pop_back();
        }
        if (node->right) {
            traversal(node->right, path, res);
            path.pop_back();
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        vector<int> path;
        if (!root) return res;
        traversal(root, path, res);
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