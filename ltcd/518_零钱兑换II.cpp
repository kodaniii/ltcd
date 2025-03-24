#include <iostream>
#include <vector>

using namespace std; 

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        //coins.size()行amount+1列
        vector<vector<uint64_t>> dp(coins.size(), vector<uint64_t>(amount + 1, 0));
        //初始化0行0列
        for (int i = 0; i < coins.size(); i++) {
            dp[i][0] = 1;   //凑齐0元有1种方案，这里初始化为0也没问题
        }
        for (int i = 0; i <= amount; i++) {
            if (i % coins[0] == 0) dp[0][i] = 1; //能够整除，dp[0][i] = 1，确保每个非0的方案都不同
        }
        for (int i = 1; i < coins.size(); i++) {
            for (int j = 0; j <= amount; j++) {
                if (coins[i] > j) dp[i][j] = dp[i - 1][j];
                /*若当前硬币面值小于等于要凑的金额，可选择使用或不使用该硬币*/
                //方案数等于不使用当前硬币(前i-1种硬币)的方案数 
                //加上使用至少一个当前硬币的方案数(第i行)
                //这利用了完全背包可重复性
                else dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i]];
            }
        }

        return dp[coins.size() - 1][amount];
    }
};

