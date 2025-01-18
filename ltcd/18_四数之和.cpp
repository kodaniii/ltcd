#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int k = 0; k < nums.size(); k++) {
            //一级剪枝
            if (nums[k] > 0 && nums[k] > target) break;
            //去重
            if (k > 0 &&  nums[k] == nums[k - 1]) continue;

            for (int i = k + 1; i < nums.size(); i++) {
                //二级剪枝
                if (nums[i] > 0 && nums[k] + nums[i] > target) break;
                //去重, 注意i > k+1，而不是 i > 1
                if (i > k + 1 && nums[i] == nums[i - 1]) continue;


                int left = i + 1, right = nums.size() - 1;
                while (left < right) {
                    if ((long)nums[k] + nums[i] + nums[left] + nums[right] > target) right--;
                    else if ((long)nums[k] + nums[i] + nums[left] + nums[right] < target) left++;
                    else {
                        res.push_back({ nums[k], nums[i], nums[left], nums[right] });
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        while (left < right && nums[right] == nums[right - 1]) right--;

                        left++, right--;
                    }
                }
            }
        }

        return res;
    }
};
