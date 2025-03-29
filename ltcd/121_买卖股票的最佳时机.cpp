#include <iostream>
#include <vector>

using namespace std; 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        //dp[][0]持有股票中，dp[][1]未持有股票
        vector<vector<int>> dp(prices.size(), vector<int>(2));
        //初始化0天
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < prices.size(); i++) {
            //i天持有股票的情况：i-1天就已经持有、i天买入并开始持有
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            //i天未持有股票的情况：i-1天未持有、i-1天持有i天卖出
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }
        return dp[prices.size() - 1][1];
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        int min_price = prices[0];
        int res = 0;
        for (auto& price : prices) {
            res = max(res, price - min_price);
            min_price = min(min_price, price);
        }

        return res;
    }
};