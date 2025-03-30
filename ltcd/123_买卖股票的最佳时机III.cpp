#include <iostream>
#include <vector>

using namespace std; 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        //dp[i][1, 2][0, 1]
        //i��������0��
        //1, 2���ڼ��ν���
        //0, 1������/�����й�Ʊ
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(3, vector<int>(2, 0)));
        //��ʼ��
        dp[0][1][0] = -prices[0];
        dp[0][2][0] = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            //��һ�γ��У�ǰһ����С�֮ǰһֱδ���н��������
            dp[i][1][0] = max(dp[i - 1][1][0], 0 - prices[i]);
            //��һ�ν��׺�δ���У�ǰһ��δ���С�ǰһ����н�������
            dp[i][1][1] = max(dp[i - 1][1][1], dp[i - 1][1][0] + prices[i]);
            //�ڶ��γ��У�ǰһ��ڶ��γ��С�ǰһ��Ϊ��һ��δ���н�������
            dp[i][2][0] = max(dp[i - 1][2][0], dp[i - 1][1][1] - prices[i]);
            //�ڶ��ν��׺�δ���У�ǰһ��ڶ���δ���С�ǰһ��ڶ��γ��н�������
            dp[i][2][1] = max(dp[i - 1][2][1], dp[i - 1][2][0] + prices[i]);
        }
        return dp[prices.size() - 1][2][1];
    }
};