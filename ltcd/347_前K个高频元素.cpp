#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std; 

class Solution {
private:
    class Cmp {
    public:
        bool operator()(pair<int, int>& a, pair<int, int>& b) {
            return a.second > b.second;
        }
    };
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (auto& num : nums) {
            m[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> q;
        for (auto& ele : m) {
            q.push(ele);
            if (q.size() > k) q.pop();
        }

        vector<int> res(k);
        for (int i = k - 1; i >= 0; i--) {
            res[i] = q.top().first;
            q.pop();
        }

        return res;
    }
};