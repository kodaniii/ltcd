#include <iostream>
#include <vector>

using namespace std; 

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        //positiveSum=(target+sum)/2
        int sum = 0;
        for (auto& num : nums) {
            sum += num;
        }
        if (abs(target) > sum) return 0;
        if ((target + sum) % 2) return 0;   //正数数量不是整数，说明没有结果
        int positiveSum = (target + sum) / 2;
        vector<int> dp(positiveSum + 1);
        //初始化：装满背包容量为0的方案有1种，放0种物品
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = positiveSum; j >= nums[i]; j--) {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[positiveSum];
    }
};