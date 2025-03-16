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
        if (cur == nullptr) return 2;   //̰�ģ����ظ�Ҷ�ӽڵ�2��������ͷ���ǣ�
        int left = traversal(cur->left);    //��
        int right = traversal(cur->right);  //��
        //��
        //���ҽڵ㶼�����ǣ�̰��˼�벻��Ҫ�����������ͷ
        if (left == 2 && right == 2) return 0;
        //���ҽڵ�����һ��û������
        else if (left == 0 || right == 0) {
            res++;
            return 1;
        }
        //���ҽڵ�������һ��������ͷ
        else return 2;
    }
public:
    int minCameraCover(TreeNode* root) {
        if (traversal(root) == 0) res++;    //���ڵ��޸���
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
