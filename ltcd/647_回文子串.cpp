#include <iostream>
#include <string>
#include <vector>

using namespace std; 

class Solution {
public:
    int countSubstrings(string s) {
        //dp[i][j]表示字符串s[i到j]是不是回文子串
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int cnt = 0;    //记录回文子串数量
        //遍历顺序：i从后往前遍历，j从前往后遍历，遍历dp上三角区域
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i; j < s.size(); j++) {
                //判断字符串s[i...j]是不是回文子串
                //对于首尾字符不同，s[i] != s[j]一定为false
                //对于首尾字符相同，s[i] == s[j]，考虑下列情况
                //情况1：j - i <= 1，如果子串长度为1或2，一定是回文子串
                //情况2：dp[i+1][j-1]==true，表示去掉首尾字符后的子串依旧是回文子串
                if (s[i] == s[j]) {
                    //情况1
                    if (j - i <= 1) {
                        dp[i][j] = true;
                        cnt++;
                    }
                    else if (dp[i + 1][j - 1]) {
                        dp[i][j] = true;
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};