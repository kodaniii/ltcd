#include <iostream>
#include <vector>

using namespace std; 

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        //length <= 30, stones[i] <= 100
        //vector<int> dp(1500 + 1);
        int sum = 0;
        for (auto& stone : stones) {
            sum += stone;
        }
        int target = sum / 2;
        vector<int> dp(target + 1);
        for (int i = 0; i < stones.size(); i++) { //物品
            for (int j = target; j >= stones[i]; j--) { //重量
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        return sum - dp[target] - dp[target];
    }
};