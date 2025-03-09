#include <iostream>
#include <vector>

using namespace std; 

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans_max = INT_MIN;  //���������
        int ans = 0;      //��ǰ������
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