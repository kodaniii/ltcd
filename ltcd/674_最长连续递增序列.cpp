#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] < nums[i]) dp[i] = max(dp[i], dp[i - 1] + 1);
        }
        int max_ret = INT_MIN;
        for (auto& dp_num : dp) {
            max_ret = max(max_ret, dp_num);
        }
        return max_ret;
    }
};