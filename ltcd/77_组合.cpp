#include <iostream>
#include <vector>

using namespace std; 

class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(int n, int k, int startIdx) {
        if (path.size() == k) {
            res.push_back(path);
            return;
        }
        //for (int i = startIdx; i <= n; i++) {
        /*¼ôÖ¦*/
        for(int i = startIdx; i < n - (k - path.size()) + 1; i++){
            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return res;
    }
};