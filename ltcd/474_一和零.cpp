#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        //����ÿһ��strs[i]
        for (auto& str : strs) {    //��Ʒ
            int zeroNum = 0, oneNum = 0;
            for (auto& s : str) {
                if (s == '0') zeroNum++;
                else oneNum++;
            }
            for (int i = m; i >= zeroNum; i--) {       //������˫ά�ȣ�
                for (int j = n; j >= oneNum; j--) {
                    dp[i][j] = max(dp[i][j], dp[i - zeroNum][j - oneNum] + 1);
                }
            }
        }
        return dp[m][n];
    }
};