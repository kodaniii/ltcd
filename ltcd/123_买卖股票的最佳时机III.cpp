#include <iostream>
#include <vector>

using namespace std; 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        //dp[i][1, 2][0, 1]
        //i：天数，0起
        //1, 2：第几次交易
        //0, 1：持有/不持有股票
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(3, vector<int>(2, 0)));
        //初始化
        dp[0][1][0] = -prices[0];
        dp[0][2][0] = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            //第一次持有：前一天持有、之前一直未持有今天才买入
            dp[i][1][0] = max(dp[i - 1][1][0], 0 - prices[i]);
            //第一次交易后未持有：前一天未持有、前一天持有今天卖出
            dp[i][1][1] = max(dp[i - 1][1][1], dp[i - 1][1][0] + prices[i]);
            //第二次持有：前一天第二次持有、前一天为第一次未持有今天买入
            dp[i][2][0] = max(dp[i - 1][2][0], dp[i - 1][1][1] - prices[i]);
            //第二次交易后未持有：前一天第二次未持有、前一天第二次持有今天卖出
            dp[i][2][1] = max(dp[i - 1][2][1], dp[i - 1][2][0] + prices[i]);
        }
        return dp[prices.size() - 1][2][1];
    }
};