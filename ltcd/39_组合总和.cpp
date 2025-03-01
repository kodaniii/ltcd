#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int>& cand, int targ, int sum, int startIdx) {
        if (sum > targ) return;
        if (sum == targ) {
            res.push_back(path);
            return;
        }
        for (int i = startIdx; i < cand.size(); i++) {
            path.push_back(cand[i]);
            backtracking(cand, targ, sum + cand[i], i);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracking(candidates, target, 0, 0);
        return res;
    }
};