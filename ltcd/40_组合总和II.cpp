#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

class Solution {
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int>& cand, int targ, int sum, int startIdx, vector<bool>& used) {
        if (sum > targ) return;
        if (sum == targ) {
            res.push_back(path);
            return;
        }
        for (int i = startIdx; i < cand.size(); i++) {
            // used[i - 1] == true，说明同一树枝candidates[i - 1]使用过
            // used[i - 1] == false，说明同一树层candidates[i - 1]使用过
            // 跳过用过的元素
            if (i > 0 && cand[i] == cand[i - 1] && used[i - 1] == false) {
                continue;
            }
            path.push_back(cand[i]);
            used[i] = true;
            backtracking(cand, targ, sum + cand[i], i + 1, used);
            used[i] = false;
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> used(candidates.size(), false);
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0, used);
        return res;
    }
};