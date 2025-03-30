#include <iostream>
#include <vector>

using namespace std; 

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() == 0) return 0;
        //dp[i][1,2,...,k][0,1]
        //i��[0, prices.size()-1]������
        //1,2,...,k����ʾ�Ѵ�ɼ��ֽ���
        //0,1�����й�Ʊ/δ���й�Ʊ
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(k + 1, vector<int>(2, 0)));
        //��ʼ��
        for (int i = 0; i <= k; i++) {
            dp[0][i][0] = -prices[0];
        }
        for (int i = 1; i < prices.size(); i++) {
            for (int j = 1; j < k; j++) {
                //i��j�ֳ��й�Ʊ��i-1�����j�ֹ�Ʊ��i-1��δ����j-1�ֹ�Ʊ��i������j�ֹ�Ʊ
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j - 1][1] - prices[i]);
                //i��j��δ�����й�Ʊ��i-1��j��δ���й�Ʊ��i-1����е�j�ֵĹ�Ʊ��i������
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j][0] + prices[i]);
            }
        }
        return dp[prices.size() - 1][k][1];
    }
};