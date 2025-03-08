#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());   //��������g
        sort(s.begin(), s.end());   //���ɴ�Сs
        int res = 0;
        int j = g.size() - 1;   //��������ָ��
        //��һ��ѡ��һ�����ɣ��ҵ�ƥ��ĺ�������
        for (int i = s.size() - 1; i >= 0; i--) {
            while (j >= 0 && g[j] > s[i]) j--;  //�������㺢������������
            if (j >= 0) {
                j--;
                res++;
            }
        }
        return res;
    }
};