#include <iostream>
#include <vector>

using namespace std; 

class Solution {
public:
    void qsort(vector<int>& q, int l, int r) {
        if (l >= r) return;
        int i = l - 1, j = r + 1;
        int x = q[(l + r) / 2];
        while (i < j) {
            do i++; while (q[i] < x);
            do j--; while (q[j] > x);
            if (i < j) swap(q[i], q[j]);
        }
        qsort(q, l, j);
        qsort(q, j + 1, r);
    }
    vector<int> sortArray(vector<int>& nums) {
        qsort(nums, 0, nums.size() - 1);
        return nums;
    }
};