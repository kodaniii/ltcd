#include <iostream>
#include <vector>

using namespace std; 

class Solution {
private:
    int robHandler(vector<int> nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        vector<int> dp(nums.size() + 1);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[nums.size() - 1];
    }
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        return max(robHandler(vector<int>(nums.begin(), nums.end() - 1)), 
            robHandler(vector<int>(nums.begin() + 1, nums.end())));
    }
};