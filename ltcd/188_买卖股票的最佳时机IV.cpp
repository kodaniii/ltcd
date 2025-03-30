#include <iostream>
#include <vector>

using namespace std; 

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() == 0) return 0;
        //dp[i][1,2,...,k][0,1]
        //i：[0, prices.size()-1]，天数
        //1,2,...,k：表示已达成几轮交易
        //0,1：持有股票/未持有股票
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(k + 1, vector<int>(2, 0)));
        //初始化
        for (int i = 0; i <= k; i++) {
            dp[0][i][0] = -prices[0];
        }
        for (int i = 1; i < prices.size(); i++) {
            for (int j = 1; j < k; j++) {
                //i天j轮持有股票：i-1天持有j轮股票、i-1天未持有j-1轮股票并i天买入j轮股票
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j - 1][1] - prices[i]);
                //i天j轮未来持有股票：i-1天j轮未持有股票、i-1天持有第j轮的股票并i天卖出
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j][0] + prices[i]);
            }
        }
        return dp[prices.size() - 1][k][1];
    }
};