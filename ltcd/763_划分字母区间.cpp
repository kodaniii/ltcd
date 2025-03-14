#include <iostream>
#include <vector>
#include <string>

using namespace std; 

class Solution {
private:
    //记录了最后一次出现的位置
    int last_pos[26] = { 0 };
public:
    vector<int> partitionLabels(string s) {
        //初始化last_pos数组
        for (int i = 0; i < s.size(); i++) {
            last_pos[s[i] - 'a'] = i;
        }
        vector<int> res;
        //left为区间左端点，right为右端点，左闭右闭
        int left = 0, right = 0;
        for (int i = 0; i < s.size(); i++) {
            right = max(right, last_pos[s[i] - 'a']);
            if (i == right) {
                res.push_back(right - left + 1);
                left = i + 1;
            }
        }
        return res;
    }
};