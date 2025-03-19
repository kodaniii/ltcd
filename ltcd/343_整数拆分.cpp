#include <iostream>
#include <vector>

using namespace std; 

class Solution {
public:
    int integerBreak(int n) {
        //2 = 1 + 1, 3 = 1 + 2, 2 + 1
        vector<int> dp(n + 1);
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            for (int j = 1; j < i - 1; j++) {
                dp[i] = max(max(j * dp[i - j], j * (i - j)), dp[i]);
            }
        }
        return dp[n];
    }
};

