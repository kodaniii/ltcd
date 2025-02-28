#include <iostream>
#include <vector>
#include <string>

using namespace std; 

class Solution {
private:
    const string letterMap[10] = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz", // 9
    };
    vector<string> res;
    string path;
    void backtracking(string digits, int idx) {
        if (digits.size() == 0) return;
        //ÖÕÖ¹Ìõ¼þ
        if (digits.size() == idx) {
            res.push_back(path);
            return;
        }
        int d = digits[idx] - '0';
        string letter = letterMap[d];
        for (int i = 0; i < letter.size(); i++) {
            path.push_back(letter[i]);
            backtracking(digits, idx + 1);
            path.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        backtracking(digits, 0);
        return res;
    }
};