#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        //�������ڵ�
        for (int i = 2; i <= n; i++) {
            cout << "i = " << i << endl;
            //������������n=3�����ڵ�i=1ʱ��������0���ڵ㣬������2���ڵ㣨2��3��
            //��������ѡ�ķ�Χ[0, i - 1]
            for (int j = 0; j < i; j++) {
                cout << "j = " << j << ", i - j - 1 = " << i - j - 1<< endl;
                dp[i] += dp[j] * dp[i - j - 1];
            }
            cout << "dp[" << i << "] = " << dp[i] << endl;
        }
        return dp[n];
    }
};