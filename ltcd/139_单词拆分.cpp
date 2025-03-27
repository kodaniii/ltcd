#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std; 

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        //dp[i]表示s的前i个字符能否由字典中的单词拼接而成
        vector<bool> dp(s.size() + 1, false);
        //dp[0]表示字符串为空，但题目规定字符串不为空，这里设置为true是为了后面继续推导，不然后面全是false了
        dp[0] = true;
        //由于我们选定的wordDict字典不一定是按顺序，所以先遍历字符串s
        for (int i = 1; i <= s.size(); i++) {
            //从0到i-1遍历，从j位置开始截取长度为i-j的子串，并对比每个j位置为起点能否加上wordSet到达i节点
            for (int j = 0; j < i; j++) {
                string word = s.substr(j, i - j);
                if (dp[j] && wordSet.find(word) != wordSet.end()) dp[i] = true;
            }
        }
        return dp[s.size()];
    }
};