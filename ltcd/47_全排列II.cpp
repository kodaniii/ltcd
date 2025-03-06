#include <iostream>
#include <vector>

using namespace std; 

class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int>& nums, vector<bool>& used) {
        if (path.size() == nums.size()) res.push_back(path);
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i - 1] == nums[i] && used[i - 1] == false) continue;
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(nums, used);
            used[i] = false;
            path.pop_back();
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return res;
    }
};