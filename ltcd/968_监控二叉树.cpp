#include <iostream>
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
    int res = 0;
    int traversal(TreeNode* cur) {
        if (cur == nullptr) return 2;   //贪心，返回给叶子节点2（被摄像头覆盖）
        int left = traversal(cur->left);    //左
        int right = traversal(cur->right);  //右
        //中
        //左右节点都被覆盖，贪心思想不需要处理这个摄像头
        if (left == 2 && right == 2) return 0;
        //左右节点至少一个没被覆盖
        else if (left == 0 || right == 0) {
            res++;
            return 1;
        }
        //左右节点至少有一个有摄像头
        else return 2;
    }
public:
    int minCameraCover(TreeNode* root) {
        if (traversal(root) == 0) res++;    //根节点无覆盖
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
