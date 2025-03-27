#include <iostream>
#include <vector>

using namespace std; 

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        vector<int> dp(nums.size());
        //≥ı ºªØ
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int j = 2; j < nums.size(); j++) {
            dp[j] = max(dp[j - 2] + nums[j], dp[j - 1]);
        }
        return dp[nums.size() - 1];
    }
};