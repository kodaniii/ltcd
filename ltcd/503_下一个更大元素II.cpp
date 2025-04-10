#include <iostream>
#include <vector>
#include <stack>

using namespace std; 

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        //拼接nums
        vector<int> nums_tmp(nums.begin(), nums.end());
        nums.insert(nums.end(), nums_tmp.begin(), nums_tmp.end());
        //单调栈，栈口存储的是最小的元素对应下标
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