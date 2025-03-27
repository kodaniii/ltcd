#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std; 

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        //dp[i]��ʾs��ǰi���ַ��ܷ����ֵ��еĵ���ƴ�Ӷ���
        vector<bool> dp(s.size() + 1, false);
        //dp[0]��ʾ�ַ���Ϊ�գ�����Ŀ�涨�ַ�����Ϊ�գ���������Ϊtrue��Ϊ�˺�������Ƶ�����Ȼ����ȫ��false��
        dp[0] = true;
        //��������ѡ����wordDict�ֵ䲻һ���ǰ�˳�������ȱ����ַ���s
        for (int i = 1; i <= s.size(); i++) {
            //��0��i-1��������jλ�ÿ�ʼ��ȡ����Ϊi-j���Ӵ������Ա�ÿ��jλ��Ϊ����ܷ����wordSet����i�ڵ�
            for (int j = 0; j < i; j++) {
                string word = s.substr(j, i - j);
                if (dp[j] && wordSet.find(word) != wordSet.end()) dp[i] = true;
            }
        }
        return dp[s.size()];
    }
};