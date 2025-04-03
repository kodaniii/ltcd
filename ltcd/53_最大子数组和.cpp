#include <iostream>
#include <vector>

using namespace std; 

/*DP*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        //dp[i]��nums[0-i]��ǰ�±��������
        vector<int> dp(nums.size());
        //��ʼ��
        dp[0] = nums[0];
        int max_sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            // if(dp[i - 1] < 0) dp[i] = nums[i]; 
            // else dp[i] = dp[i - 1] + nums[i];
            max_sum = max(dp[i], max_sum);
        }
        return max_sum;
    }
};

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