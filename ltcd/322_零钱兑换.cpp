#include <iostream>
#include <vector>

using namespace std; 

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        vector<int> dp(amount + 1, INT_MAX);
        //初始化
        for (int i = 0; i <= amount; i++) {
            if (i % coins[0] == 0) dp[i] = i / coins[0];    //dp[i]保存的是最小硬币数
        }
        for (int i = 1; i < coins.size(); i++) {
            for (int j = coins[i]; j <= amount; j++) {
                //如果没有方案，跳过，dp[j]不变，避免溢出
                if (dp[j - coins[i]] == INT_MAX) continue;
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }

        if (dp[amount] == INT_MAX) return -1;
        return dp[amount];
    }
};