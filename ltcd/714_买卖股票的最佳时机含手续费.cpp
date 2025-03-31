#include <iostream>
#include <vector>

using namespace std; 

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        //dp[i][0-1]
        //i：天数
        //0-1：持有/未持有
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        //初始化
        dp[0][0] = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            //i天持有：i-1天持有、i-1天未持有i天买入
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            //i天未持有：i-1天未持有、i天持有i天卖出并支付手续费
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
        }
        return dp[prices.size() - 1][1];
    }
};