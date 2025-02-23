#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(int n, int k, int sum, int startIndex) {
        if (sum > n) return;
        if (path.size() == k) {
            if (n == sum) res.push_back(path);
            return;
        }
        for (int i = startIndex; i <= 9; i++) {
            path.push_back(i);
            sum += i;
            backtracking(n, k, sum, i + 1);
            sum -= i;
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(n, k, 0, 1);
        return res;
    }
};