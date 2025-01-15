#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> s;
        int cnt = 0;
        for (auto& num_1 : nums1) {
            for (auto& num_2 : nums2) {
                s[num_1 + num_2]++;
            }
        }

        for (auto& num_3 : nums3) {
            for (auto& num_4 : nums4) {
                auto find_iter = s.find(0 - num_3 - num_4);
                if (find_iter != s.end()) {
                    cnt += find_iter->second;
                }
            }
        }

        return cnt;
    }
};