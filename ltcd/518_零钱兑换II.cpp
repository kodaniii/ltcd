#include <iostream>
#include <vector>

using namespace std; 

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        //coins.size()��amount+1��
        vector<vector<uint64_t>> dp(coins.size(), vector<uint64_t>(amount + 1, 0));
        //��ʼ��0��0��
        for (int i = 0; i < coins.size(); i++) {
            dp[i][0] = 1;   //����0Ԫ��1�ַ����������ʼ��Ϊ0Ҳû����
        }
        for (int i = 0; i <= amount; i++) {
            if (i % coins[0] == 0) dp[0][i] = 1; //�ܹ�������dp[0][i] = 1��ȷ��ÿ����0�ķ�������ͬ
        }
        for (int i = 1; i < coins.size(); i++) {
            for (int j = 0; j <= amount; j++) {
                if (coins[i] > j) dp[i][j] = dp[i - 1][j];
                /*����ǰӲ����ֵС�ڵ���Ҫ�յĽ���ѡ��ʹ�û�ʹ�ø�Ӳ��*/
                //���������ڲ�ʹ�õ�ǰӲ��(ǰi-1��Ӳ��)�ķ����� 
                //����ʹ������һ����ǰӲ�ҵķ�����(��i��)
                //����������ȫ�������ظ���
                else dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i]];
            }
        }

        return dp[coins.size() - 1][amount];
    }
};

