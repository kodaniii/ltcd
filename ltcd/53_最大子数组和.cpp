#include <iostream>
#include <vector>

using namespace std; 

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans_max = INT_MIN;  //最大连续和
        int ans = 0;      //当前连续和
        for (auto& num : nums) {
            ans += num;
            if (ans < 0) {
                ans = 0;
                continue;
            }
            ans_max = max(ans, ans_max);
        }
        return ans_max;
    }
};