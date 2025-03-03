#include <iostream>
#include <vector>
#include <string>

using namespace std; 

class Solution {
private:
    vector<string> res;
    void backtracking(string& s, int startIdx, int pointNum) {
        //三个小数点都确定，结束
        if (pointNum == 3) {
            //判断第四段是否合法，[]
            if (isValid(s, startIdx, s.size() - 1)) {
                res.push_back(s);
            }
            return;
        }
        for (int i = startIdx; i < s.size(); i++) {
            //判断当前区间作为字段是否合法
            if (isValid(s, startIdx, i)) {
                s.insert(s.begin() + i + 1, '.');   //在i的后面加一个.
                backtracking(s, i + 2, pointNum + 1);
                s.erase(s.begin() + i + 1);
            }
            else break;
        }
    }
    // 判断字符串s在左闭右闭区间[start, end]所组成的数字是否合法
    bool isValid(const string& s, int start, int end) {
        if (start > end) {
            return false;
        }
        if (s[start] == '0' && start != end) { // 0开头的数字不合法
            return false;
        }
        int num = 0;
        for (int i = start; i <= end; i++) {
            if (s[i] > '9' || s[i] < '0') { // 遇到非数字字符不合法
                return false;
            }
            num = num * 10 + (s[i] - '0');
            if (num > 255) { // 如果大于255了不合法
                return false;
            }
        }
        return true;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        if (s.size() < 4 || s.size() > 12) return res;
        backtracking(s, 0, 0);
        return res;
    }
};