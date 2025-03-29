#include <iostream>
#include <vector>

using namespace std;

/*DP*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        //dp[][0]持有股票，dp[][1]未持有股票
        vector<vector<int>> dp(prices.size(), vector<int>(2));
        //初始化
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < prices.size(); i++) {
            //i天持有股票：i-1天就已经持有，i-1天没有持有
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            //i-1天未持有股票：i-1天持有，i-1天没持有
            dp[i][1] = max(dp[i - 1][0] + prices[i], dp[i - 1][1]);
        }
        return dp[prices.size() - 1][1];
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for (int i = 1; i < prices.size(); ++i) {
            res += max(0, prices[i] - prices[i - 1]);
        }
        return res;
    }
};