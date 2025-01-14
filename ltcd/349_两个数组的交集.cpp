#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> res;
        unordered_set<int> nums1_set(nums1.begin(), nums1.end());

        for (auto& num : nums2) {
            if (nums1_set.find(num) != nums1_set.end()) {
                res.insert(num);
            }
        }

        return vector<int>(res.begin(), res.end());
    }
};