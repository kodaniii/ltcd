#include <iostream>
#include <vector>
#include <stack>

using namespace std; 

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        //ƴ��nums
        vector<int> nums_tmp(nums.begin(), nums.end());
        nums.insert(nums.end(), nums_tmp.begin(), nums_tmp.end());
        //����ջ��ջ�ڴ洢������С��Ԫ�ض�Ӧ�±�
        stack<int> st;
        vector<int> res(nums.size(), -1);
        st.push(0);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= nums[st.top()]) {
                st.push(i);
            }
            else {
                while (!st.empty() && nums[i] > nums[st.top()]) {
                    res[st.top()] = nums[i];
                    st.pop();
                }
                st.push(i);
            }
        }
        res.resize(nums.size() / 2);
        return res;
    }
};