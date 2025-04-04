#include <iostream>
#include <string>
#include <vector>

using namespace std; 

class Solution {
public:
    bool isSubsequence(string s, string t) {
        //dp[i][j]��ʾs[0��i-1]��t[0��i-1]������г���
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
        //dp[0][]��dp[][0]û�����壬�Ѿ���ʼ��Ϊ0
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 1; j <= t.size(); j++) {
                if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        return dp[s.size()][t.size()] == s.size();
    }
};

class Solution {
public:
    bool isSubsequence(string s, string t) {
        /*�ж�s�Ƿ���t��������*/
        if (s.size() == 0) return true;
        if (s.size() > t.size()) return false;
        //˫ָ�룬iָ��s��jָ��t
        int i = 0, j = 0;
        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) {
                i++, j++;
            }
            else {
                j++;
            }
        }
        if (i > s.size() - 1) return true;
        else if (j > t.size() - 1) return false;

        return false;   //û�д�����ߵ�������������Ѿ�����ǰ���ж���
    }
};