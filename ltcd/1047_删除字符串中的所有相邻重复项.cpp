#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        string res;
        for (auto& ele : s) {
            if (!res.empty() && res.back() == ele)   res.pop_back();
            else res.push_back(ele);
        }

        return res;
    }
};