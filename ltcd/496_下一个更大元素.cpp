#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std; 

class Solution {
public:
    //找到nums1每个元素在nums2中对应元素的下一个元素
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //存储nums2元素
        stack<int> st;
        vector<int> res(nums1.size(), -1);

        //key：nums1的元素，value：nums1的索引
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
                    //检查这个元素在不在nums1中
                    if (umap.count(st.top()) > 0) {
                        //获取nums1的索引
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