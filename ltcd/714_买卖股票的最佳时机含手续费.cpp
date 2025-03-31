#include <iostream>
#include <vector>

using namespace std; 

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        //dp[i][0-1]
        //i������
        //0-1������/δ����
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        //��ʼ��
        dp[0][0] = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            //i����У�i-1����С�i-1��δ����i������
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            //i��δ���У�i-1��δ���С�i�����i��������֧��������
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
        }
        return dp[prices.size() - 1][1];
    }
};