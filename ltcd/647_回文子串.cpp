#include <iostream>
#include <string>
#include <vector>

using namespace std; 

class Solution {
public:
    int countSubstrings(string s) {
        //dp[i][j]��ʾ�ַ���s[i��j]�ǲ��ǻ����Ӵ�
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int cnt = 0;    //��¼�����Ӵ�����
        //����˳��i�Ӻ���ǰ������j��ǰ�������������dp����������
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i; j < s.size(); j++) {
                //�ж��ַ���s[i...j]�ǲ��ǻ����Ӵ�
                //������β�ַ���ͬ��s[i] != s[j]һ��Ϊfalse
                //������β�ַ���ͬ��s[i] == s[j]�������������
                //���1��j - i <= 1������Ӵ�����Ϊ1��2��һ���ǻ����Ӵ�
                //���2��dp[i+1][j-1]==true����ʾȥ����β�ַ�����Ӵ������ǻ����Ӵ�
                if (s[i] == s[j]) {
                    //���1
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