#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution {
private:
    vector<vector<string>> res;
    vector<string> path;
    void backtracking(const string& s, int startIdx) {
        if (startIdx >= s.size()) {
            res.push_back(path);
            return;
        }
        for (int i = startIdx; i < s.size(); i++) {
            //是回文串
            if (isPalindrome(s, startIdx, i)) {
                string str = s.substr(startIdx, i - startIdx + 1);
                cout << "push " << str << endl;
                path.push_back(str);
            }
            //不是回文，直接遍历下个树枝
            else continue;
            backtracking(s, i + 1);
            cout << "pop " << path.back() << endl;
            path.pop_back();
        }
    }
    bool isPalindrome(const string& s, int begin, int end) {
        for (int i = begin, j = end; i < j; i++, j--) {
            if (s[i] != s[j]) return false;
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        backtracking(s, 0);
        return res;
    }
};

