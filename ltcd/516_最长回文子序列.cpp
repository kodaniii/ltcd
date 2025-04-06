#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        //dp[i][j]表示字符串子串s[i到j]最长回文子序列长度
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        //初始化：单个字符本身就是一个长度为1的回文子序列
        for (int i = 0; i < s.size(); i++) dp[i][i] = 1;
        //回文子串遍历方式：从字符串的末尾向前遍历，因为后续状态需要用到前面的结果
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i + 1; j < s.size(); j++) {
                //如果首尾字符相同，说明可以在dp[i+1][j-1]的基础上扩展，长度+2
                if (s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1] + 2;
                //不相同的情况，取s[i+1到j]和s[i到j-1]长度的最大值
                //只需比较长度，无需考虑子序列具体内容，不需要考虑当前首尾元素和之前的子序列是否等于当前子序列
                else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        return dp[0][s.size() - 1];
    }
};