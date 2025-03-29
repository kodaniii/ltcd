#include <iostream>
#include <vector>

using namespace std; 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        //dp[][0]���й�Ʊ�У�dp[][1]δ���й�Ʊ
        vector<vector<int>> dp(prices.size(), vector<int>(2));
        //��ʼ��0��
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < prices.size(); i++) {
            //i����й�Ʊ�������i-1����Ѿ����С�i�����벢��ʼ����
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            //i��δ���й�Ʊ�������i-1��δ���С�i-1�����i������
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