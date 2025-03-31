#include <iostream>
#include <vector>

using namespace std; 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //pd[i][0-2]
        //i������
        //0������״̬
        //1��δ����״̬
        //2���䶳�ڣ�ǰһ������
        vector<vector<int>> dp(prices.size(), vector<int>(3, 0));
        //��ʼ��
        dp[0][0] = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            //i����У�i-1���Ѿ����У�i-1���䶳��ת������
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i]);
            //i��δ���У�i-1��δ���У�i-1������
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
            //�䶳��
            dp[i][2] = dp[i - 1][1];
        }
        return max(dp[prices.size() - 1][1], dp[prices.size() - 1][2]);
    }
};