#include <iostream>
#include <vector>

using namespace std; 

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        int max_ret = INT_MIN;
        for (auto& dp_num : dp) {
            max_ret = max(max_ret, dp_num);
        }
        return max_ret;
    }
};