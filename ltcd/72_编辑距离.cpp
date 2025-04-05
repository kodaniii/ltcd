#include <iostream>
#include <string>
#include <vector>

using namespace std; 

class Solution {
public:
    int minDistance(string word1, string word2) {
        //dp[i][j]��ʾword1[0��i-1]ת��Ϊword2[0��j-1]�������ٲ�������
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        //��ʼ��
        //��һ�к͵�һ�г�ʼ��������һ��wordΪ�գ���������Ϊ��ǰword����
        for (int i = 0; i <= word1.size(); i++) dp[i][0] = i;
        for (int j = 0; j <= word2.size(); j++) dp[0][j] = j;

        for (int i = 1; i <= word1.size(); i++) {
            for (int j = 1; j <= word2.size(); j++) {
                //��ǰ�ַ���ȣ�����Ҫ�������
                //����������������dp[i-1][j-1]���
                if (word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                //�ַ�����ȣ����ֲ���ȡ��������С�ģ�ɾ�����滻�����룬Ȼ���������+1
                //ɾ����dp[i-1][j]��word1ɾ��һ��Ԫ�أ���word1[0��i-2]ת��Ϊword2[0��i-1]�����ٲ�������
                //�滻��dp[i-1][j-1]����word1Ԫ���滻��word2
                //���룺dp[i][j-1]������һ��Ԫ�ؾ������Ԫ�أ��൱��word2ɾ��һ��Ԫ��
                else dp[i][j] = min({ dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1] }) + 1;
            }
        }
        return dp[word1.size()][word2.size()];
    }
};