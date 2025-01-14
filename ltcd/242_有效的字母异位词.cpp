#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> cnt(26);
        
        if (s.size() != t.size()) return false;
        for (int i = 0; i < s.size(); i++) {
            cnt[s[i] - 'a']++;
            cnt[t[i] - 'a']--;
        }

        for (auto& _c: cnt) {
            if (_c) return false;
        }

        return true;
    }
};