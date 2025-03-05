#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std; 

class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIdx) {
        if (path.size() > 1) res.push_back(path);
        unordered_set<int> uset;    //每层一个uset
        for (int i = startIdx; i < nums.size(); i++) {
            if ((path.empty() || nums[i] >= path.back()) && uset.find(nums[i]) == uset.end()) {
                uset.insert(nums[i]);   //当前层已经用过nums[i]，再遇到nums[i]跳过
                path.push_back(nums[i]);
                backtracking(nums, i + 1);
                path.pop_back();
            }
            else continue;
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracking(nums, 0);
        return res;
    }
};