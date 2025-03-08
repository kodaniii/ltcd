#include <iostream>
#include <vector>

using namespace std; 

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() == 1) return 1;
        int preDiff = 0;    //上一次差值
        int curDiff = 0;    //当前差值
        int res = 1;        //峰值个数，默认最左侧有一个峰值
        for (int i = 0; i < nums.size() - 1; i++) {
            curDiff = nums[i + 1] - nums[i];
            if ((preDiff <= 0 && curDiff > 0) || (preDiff >= 0 && curDiff < 0)) {
                res++;
                preDiff = curDiff;  //摆动变化时更新preDiff
            }
            cout << preDiff << " " << curDiff << endl;
        }
        return res;
    }
};