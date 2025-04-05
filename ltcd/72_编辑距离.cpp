#include <iostream>
#include <string>
#include <vector>

using namespace std; 

class Solution {
public:
    int minDistance(string word1, string word2) {
        //dp[i][j]表示word1[0到i-1]转换为word2[0到j-1]所需最少操作次数
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        //初始化
        //第一行和第一列初始化，当另一个word为空，操作次数为当前word长度
        for (int i = 0; i <= word1.size(); i++) dp[i][0] = i;
        for (int j = 0; j <= word2.size(); j++) dp[0][j] = j;

        for (int i = 1; i <= word1.size(); i++) {
            for (int j = 1; j <= word2.size(); j++) {
                //当前字符相等，不需要额外操作
                //不操作：操作数和dp[i-1][j-1]相等
                if (word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                //字符不相等，三种操作取操作数最小的：删除、替换、插入，然后操作次数+1
                //删除：dp[i-1][j]，word1删除一个元素，即word1[0到i-2]转移为word2[0到i-1]的最少操作次数
                //替换：dp[i-1][j-1]，将word1元素替换成word2
                //插入：dp[i][j-1]，插入一个元素就是添加元素，相当于word2删除一个元素
                else dp[i][j] = min({ dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1] }) + 1;
            }
        }
        return dp[word1.size()][word2.size()];
    }
};