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
    TreeNode* traversal(vector<int>& in, vector<int>& post) {
        //������������ֹ
        if (post.size() == 0) return nullptr;
        //�����ҵ��м�ڵ�
        int root_val = post[post.size() - 1];
        TreeNode* root = new TreeNode(root_val);
        //if(post.size() == 1) return root;
        //����λ�м�ڵ�
        int idx;
        for (idx = 0; idx < in.size(); idx++) {
            if (in[idx] == root_val) break;
        }
        
        //�к����������
        vector<int> leftinorder(in.begin(), in.begin() + idx);
        vector<int> rightinorder(in.begin() + idx + 1, in.end());
        vector<int> leftpostorder(post.begin(), post.begin() + leftinorder.size());
        vector<int> rightpostorder(post.begin() + leftinorder.size(), post.end() - 1);

        root->left = traversal(leftinorder, leftpostorder);
        root->right = traversal(rightinorder, rightpostorder);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return traversal(inorder, postorder);
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