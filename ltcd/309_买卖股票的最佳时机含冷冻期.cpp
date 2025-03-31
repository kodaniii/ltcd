#include <iostream>
#include <vector>

using namespace std; 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //pd[i][0-2]
        //i：天数
        //0：持有状态
        //1：未持有状态
        //2：冷冻期，前一天卖出
        vector<vector<int>> dp(prices.size(), vector<int>(3, 0));
        //初始化
        dp[0][0] = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            //i天持有：i-1天已经持有，i-1天冷冻期转出买入
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i]);
            //i天未持有：i-1天未持有，i-1天卖出
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
            //冷冻期
            dp[i][2] = dp[i - 1][1];
        }
        return max(dp[prices.size() - 1][1], dp[prices.size() - 1][2]);
    }
};