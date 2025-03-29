#include <iostream>
#include <vector>

using namespace std;

/*DP*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        //dp[][0]���й�Ʊ��dp[][1]δ���й�Ʊ
        vector<vector<int>> dp(prices.size(), vector<int>(2));
        //��ʼ��
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < prices.size(); i++) {
            //i����й�Ʊ��i-1����Ѿ����У�i-1��û�г���
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            //i-1��δ���й�Ʊ��i-1����У�i-1��û����
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