#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        //dp[i][j]��ʾ�±�Ϊi-1��text1��j-1��text2������������г���
        //dp[0][]��dp[][0]��ʼ��Ϊ0
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        int res = INT_MIN;
        for (int i = 1; i <= text1.size(); i++) {
            for (int j = 1; j <= text2.size(); j++) {
                if (text1[i - 1] == text2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};