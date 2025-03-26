#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int combinationSum4(std::vector<int>& nums, int target) {
        //dp[i]：凑成目标正整数为i的排列数量
        vector<unsigned long long> dp(target + 1, 0);
        //dp[0]初始化
        dp[0] = 1;
        for (int i = 0; i <= target; i++) {   //先遍历物品
            for (int j = 0; j < nums.size(); j++) {   //再遍历背包
                if (i >= nums[j]) {
                    dp[i] += dp[i - nums[j]];
                }
            }
        }
        return dp[target];
    }
};

class Solution_FALSE_SOLUTION {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, 0));
        //初始化0行0列
        if (target % nums[0] == 0) {    //能整除nums[0]
            dp[0][target / nums[0]] = 1;
        }
        for (int i = 0; i < nums.size(); i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j <= target; j++) {
                if (nums[i] > j) dp[i][j] = dp[i - 1][j];
                dp[i][j] = dp[i - 1][j] + dp[i][j - nums[i]];
            }
        }
        return dp[nums.size() - 1][target];
    }
};