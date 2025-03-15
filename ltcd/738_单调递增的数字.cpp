#include <iostream>
#include <string>

using namespace std; 

class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string str = to_string(n);
        //flag记录了需要赋值9的下标，这个下标后面全要赋值为9
        int flag = str.size();
        //遍历位数更高的一位，并修改低位
        //如果高位<低位，高位--，低位变为9
        for (int i = str.size() - 1; i > 0; i--) {
            if (str[i - 1] > str[i]) {
                flag = i;
                str[i - 1]--;
            }
        }
        for (int i = flag; i < str.size(); i++) {
            str[i] = '9';
        }
        return stoi(str);
    }
};