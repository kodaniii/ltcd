#include <iostream>
#include <string>
#include <vector>

using namespace std; 

class Solution {
public:
    //完整序列s，子序列t
    int numDistinct(string s, string t) {
        //dp[i][j]表示s[0到i-1]和t[0到i-1]最长子序列长度
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
        //初始化
        for (int i = 0; i <= s.size(); i++) dp[i][0] = 1;   //dp[i][0]表示子序列为空的样例数
        for (int j = 1; j <= t.size(); j++) dp[0][j] = 0;
        //s="baagg" t="bag"的两种转移情况：
        //如果此元素相等，求s的前面有多少个"ba" + 前面有多少个完整的"bag"
        //如果元素不相等，求s的前面有多少个"bag"
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 1; j <= t.size(); j++) {
                //元素相等的情况：
                //1、使用s[i-1]匹配t[j-1]，数量dp[i-1][j-1]，即求s的前面有多少个"ba
                //2、不使用s[i-1]匹配t[j-1]，数量dp[i-1][j]，即求s的前面有多少个完整的"bag"
                if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];   //j是子序列串，因此不是j-1
                else dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[s.size()][t.size()];
    }
};