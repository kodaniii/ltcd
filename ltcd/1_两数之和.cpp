#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            auto find_iter = m.find(target - nums[i]);
            if (find_iter != m.end()) {
                return { i, find_iter->second };    //·µ»ØµÄÊÇvector<int>
            }
            //m.insert(make_pair(nums[i], i));
            m.insert(pair<int, int>(nums[i], i));
        }

        return {};
    }
};