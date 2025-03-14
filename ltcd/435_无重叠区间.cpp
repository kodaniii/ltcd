#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution { 
private:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return 0;
        int res = 0;
        sort(intervals.begin(), intervals.end(), cmp);
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i - 1][1] <= intervals[i][0]) {
                
            }
            else {
                intervals[i][1] = min(intervals[i - 1][1], intervals[i][1]);
                res++;
            }
        }
        return res;
    }
};