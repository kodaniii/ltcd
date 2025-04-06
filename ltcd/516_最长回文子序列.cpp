#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        //dp[i][j]��ʾ�ַ����Ӵ�s[i��j]����������г���
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        //��ʼ���������ַ��������һ������Ϊ1�Ļ���������
        for (int i = 0; i < s.size(); i++) dp[i][i] = 1;
        //�����Ӵ�������ʽ�����ַ�����ĩβ��ǰ��������Ϊ����״̬��Ҫ�õ�ǰ��Ľ��
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i + 1; j < s.size(); j++) {
                //�����β�ַ���ͬ��˵��������dp[i+1][j-1]�Ļ�������չ������+2
                if (s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1] + 2;
                //����ͬ�������ȡs[i+1��j]��s[i��j-1]���ȵ����ֵ
                //ֻ��Ƚϳ��ȣ����迼�������о������ݣ�����Ҫ���ǵ�ǰ��βԪ�غ�֮ǰ���������Ƿ���ڵ�ǰ������
                else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        return dp[0][s.size() - 1];
    }
};