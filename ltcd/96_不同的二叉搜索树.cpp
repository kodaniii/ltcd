#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        //遍历根节点
        for (int i = 2; i <= n; i++) {
            cout << "i = " << i << endl;
            //左右子树，当n=3，根节点i=1时，左子树0个节点，右子树2个节点（2、3）
            //左子树可选的范围[0, i - 1]
            for (int j = 0; j < i; j++) {
                cout << "j = " << j << ", i - j - 1 = " << i - j - 1<< endl;
                dp[i] += dp[j] * dp[i - j - 1];
            }
            cout << "dp[" << i << "] = " << dp[i] << endl;
        }
        return dp[n];
    }
};