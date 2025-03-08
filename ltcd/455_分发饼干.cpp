#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());   //孩子需求g
        sort(s.begin(), s.end());   //饼干大小s
        int res = 0;
        int j = g.size() - 1;   //孩子需求指针
        //第一层选定一个饼干，找到匹配的孩子需求
        for (int i = s.size() - 1; i >= 0; i--) {
            while (j >= 0 && g[j] > s[i]) j--;  //不能满足孩子需求则跳过
            if (j >= 0) {
                j--;
                res++;
            }
        }
        return res;
    }
};