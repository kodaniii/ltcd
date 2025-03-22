#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int m = nums.size();
        int sum = 0;
        for (auto& num : nums) {
            sum += num;
        }
        if (sum % 2) return false;
        int target = sum / 2;
        //m��sum/2�У��б�ʾ�Ѽӵ���i��nums���б�ʾ���ͣ��������С�����ͣ�
        vector<vector<int>> dp(m, vector<int>(target + 1, 0));

        //��ʼ��0��
        for (int i = nums[0]; i <= target; i++) {
            dp[0][i] = nums[0];
        }

        for (int i = 1; i < nums.size(); i++) {
            for (int j = 1; j <= target; j++) { //j=0һ��Ϊ0�����ñ���
                //�����������jС�ڵ�ǰֵnums[i]
                if (j < nums[i]) dp[i][j] = dp[i - 1][j];
                else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - nums[i]] + nums[i]);
            }
        }

        return dp[nums.size() - 1][target] == target;
    }
};

//1D-dp
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto& num : nums) {
            sum += num;
        }
        //sumΪ��������false����Ϊ��������һ�����Ӽ�Ϊtarget����һ���������������
        if (sum % 2) return false;
        int target = sum / 2;
        vector<int> dp(target + 1);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = target; j >= nums[i]; j--) {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        return dp[target] == target;
    }
};


