#include <iostream>
#include <vector>
#include <deque>

using namespace std; 

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        //初始化第一个滑动窗口
        int i = 0;
        for (; i < k; i++) {
            push(nums[i]);
        }
        res.push_back(front());
        for (; i < nums.size(); i++) {
            pop(nums[i - k]);
            push(nums[i]);
            res.push_back(front());
        }

        return res;
    }
private:
    deque<int> q;
    void pop(int val) {
        if (!q.empty() && q.front() == val) q.pop_front();
    }
    void push(int val) {
        while (!q.empty() && q.back() < val) q.pop_back();
        q.push_back(val);
    }
    int front() {
        return q.front();
    }
};