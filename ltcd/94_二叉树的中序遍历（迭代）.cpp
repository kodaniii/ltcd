#include <iostream>
#include <vector>
#include <stack>

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
    //����������
    vector<int> inorderTraversal(TreeNode* root) {
        //init
        TreeNode* cur = root;
        while (cur || !st.empty()) {
            //������������浽stack
            if (cur) {
                st.push(cur);
                cur = cur->left;
            }
            //�սڵ㣬��ջ�д�������Ԫ�أ�Ȼ��cur����
            else {
                cur = st.top();
                st.pop();
                res.push_back(cur->val);
                cur = cur->right;
            }
        }
        return res;
    }
private:
    vector<int> res;
    stack<TreeNode*> st;
    TreeNode* cur = nullptr;
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