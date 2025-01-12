#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int j = 0, i = 0;
        int sum = 0, result = INT_MAX;
        for (; j < nums.size(); j++) {
            sum += nums[j];
            
            while (sum >= target) {
                int sub_len = j - i + 1;
                result = min(result, sub_len);
                sum -= nums[i];
                i++;
            }
        }
        if (result == INT_MAX) return 0;
        return result;
    }
};
