#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

class Solution {
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });
        if (intervals.size() == 0) return res;
        //left初始化为第一个数组的左边界
        int left = intervals[0][0];
        for (int i = 1; i < intervals.size(); i++) {
            //i相比i-1不能合并
            if(intervals[i][0] > intervals[i - 1][1]){
                res.push_back(vector<int>(left, intervals[i - 1][1]));
                left = intervals[i - 1][1] + 1;
            }
            else {
                //更新i的右边界为i和i-1的最大右边界
                intervals[i][1] = max(intervals[i][1], intervals[i - 1][1]);
            }
        }
        return res;
    }
};