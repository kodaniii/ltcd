#include <iostream>
#include <vector>

using namespace std; 

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        vector<int> dp(amount + 1, INT_MAX);
        //��ʼ��
        for (int i = 0; i <= amount; i++) {
            if (i % coins[0] == 0) dp[i] = i / coins[0];    //dp[i]���������СӲ����
        }
        for (int i = 1; i < coins.size(); i++) {
            for (int j = coins[i]; j <= amount; j++) {
                //���û�з�����������dp[j]���䣬�������
                if (dp[j - coins[i]] == INT_MAX) continue;
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }

        if (dp[amount] == INT_MAX) return -1;
        return dp[amount];
    }
};