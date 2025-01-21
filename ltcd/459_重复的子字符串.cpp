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

    /*��ͷȥβ��*/
    bool repeatedSubstringPattern(string s) {
        string ss = s + s;
        /*��ͷȥβ*/
        ss.erase(ss.begin());
        ss.erase(ss.end() - 1);

        //����s
        if (ss.find(s) != string::npos) return true;
        else return false;
    }

private:
    void getNext(vector<int>& next, const string& s) {
        //init
        int j = 0;
        next[0] = 0;
        for (int i = 1; i < s.size(); i++) {
            //����ǰ��׺����ȣ�����
            while (j > 0 && s[i] != s[j]) {
                j = next[j - 1];
            }
            //����ǰ��׺���
            if (s[i] == s[j]) {
                j++;
            }
            //����next
            next[i] = j;
        }
    }
};