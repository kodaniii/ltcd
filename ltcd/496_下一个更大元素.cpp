#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std; 

class Solution {
public:
    //�ҵ�nums1ÿ��Ԫ����nums2�ж�ӦԪ�ص���һ��Ԫ��
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //�洢nums2Ԫ��
        stack<int> st;
        vector<int> res(nums1.size(), -1);

        //key��nums1��Ԫ�أ�value��nums1������
        unordered_map<int, int> umap;
        for (int i = 0; i < nums1.size(); i++) {
            umap[nums1[i]] = i;
        }

        st.push(nums2[0]);
        for (int i = 1; i < nums2.size(); i++) {
            if (nums2[i] <= st.top()) {
                st.push(nums2[i]);
            }
            else {
                while (!st.empty() && nums2[i] > st.top()) {
                    //������Ԫ���ڲ���nums1��
                    if (umap.count(st.top()) > 0) {
                        //��ȡnums1������
                        int idx = umap[st.top()];
                        res[idx] = nums2[i];
                    }
                    st.pop();
                }
                st.push(nums2[i]);
            }
        }
        return res;
    }
};