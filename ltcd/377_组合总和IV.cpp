#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int combinationSum4(std::vector<int>& nums, int target) {
        //dp[i]���ճ�Ŀ��������Ϊi����������
        vector<unsigned long long> dp(target + 1, 0);
        //dp[0]��ʼ��
        dp[0] = 1;
        for (int i = 0; i <= target; i++) {   //�ȱ�����Ʒ
            for (int j = 0; j < nums.size(); j++) {   //�ٱ�������
                if (i >= nums[j]) {
                    dp[i] += dp[i - nums[j]];
                }
            }
        }
        return dp[target];
    }
};

class Solution_FALSE_SOLUTION {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, 0));
        //��ʼ��0��0��
        if (target % nums[0] == 0) {    //������nums[0]
            dp[0][target / nums[0]] = 1;
        }
        for (int i = 0; i < nums.size(); i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j <= target; j++) {
                if (nums[i] > j) dp[i][j] = dp[i - 1][j];
                dp[i][j] = dp[i - 1][j] + dp[i][j - nums[i]];
            }
        }
        return dp[nums.size() - 1][target];
    }
};