#include <iostream>
#include <string>
#include <vector>

using namespace std; 

class Solution {
public:
    //��������s��������t
    int numDistinct(string s, string t) {
        //dp[i][j]��ʾs[0��i-1]��t[0��i-1]������г���
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
        //��ʼ��
        for (int i = 0; i <= s.size(); i++) dp[i][0] = 1;   //dp[i][0]��ʾ������Ϊ�յ�������
        for (int j = 1; j <= t.size(); j++) dp[0][j] = 0;
        //s="baagg" t="bag"������ת�������
        //�����Ԫ����ȣ���s��ǰ���ж��ٸ�"ba" + ǰ���ж��ٸ�������"bag"
        //���Ԫ�ز���ȣ���s��ǰ���ж��ٸ�"bag"
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 1; j <= t.size(); j++) {
                //Ԫ����ȵ������
                //1��ʹ��s[i-1]ƥ��t[j-1]������dp[i-1][j-1]������s��ǰ���ж��ٸ�"ba
                //2����ʹ��s[i-1]ƥ��t[j-1]������dp[i-1][j]������s��ǰ���ж��ٸ�������"bag"
                if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];   //j�������д�����˲���j-1
                else dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[s.size()][t.size()];
    }
};