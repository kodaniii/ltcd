#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int curDistance = 0;    //本轮跳跃覆盖到最远距离下标
        int nextDistance = 0;   //下一轮最远距离下标，使得i在cur和next之间移动
        int cnt = 0;            //走的步数

        for (int i = 0; i < nums.size(); i++) {
            nextDistance = max(nums[i] + i, nextDistance);
            //i在cur和next之间移动
            //当i走到cur，表示已经走到了本轮跳跃的终点
            if (i == curDistance) {
                cnt++;
                curDistance = nextDistance;
                if (nextDistance >= nums.size() - 1) break;
            }
        }

        return cnt;
    }
};