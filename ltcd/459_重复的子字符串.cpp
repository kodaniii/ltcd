#include <iostream>
#include <vector>
#include <string>
using namespace std; 

class Solution {
public:
    /*KMP*/
    bool repeatedSubstringPattern(string s) {
        vector<int> next(s.size());
        getNext(next, s);

        int len = s.size();
        if (next[len - 1] != 0 && len % (len - (next[len - 1])) == 0) {
            return true;
        }
        else return false;
    }

    /*掐头去尾法*/
    bool repeatedSubstringPattern(string s) {
        string ss = s + s;
        /*掐头去尾*/
        ss.erase(ss.begin());
        ss.erase(ss.end() - 1);

        //存在s
        if (ss.find(s) != string::npos) return true;
        else return false;
    }

private:
    void getNext(vector<int>& next, const string& s) {
        //init
        int j = 0;
        next[0] = 0;
        for (int i = 1; i < s.size(); i++) {
            //处理前后缀不相等，回退
            while (j > 0 && s[i] != s[j]) {
                j = next[j - 1];
            }
            //处理前后缀相等
            if (s[i] == s[j]) {
                j++;
            }
            //更新next
            next[i] = j;
        }
    }
};