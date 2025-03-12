#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        //初始化所有人糖果为最低1
        vector<int> c(ratings.size(), 1);
        //只检测右边孩子，如果比左边高就+1
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) c[i] = c[i - 1] + 1;
        }
        //检测左边孩子，比右边高+1，同时比较上一轮检测的结果，取最高者
        for (int i = ratings.size() - 1; i > 0; i--) {
            if (ratings[i - 1] > ratings[i]) c[i - 1] = max(c[i - 1], c[i] + 1);
        }
        int res = 0;
        for (auto& _c : c) {
            res += _c;
        }
        return res;
    }
};