#include <iostream>
#include <string>
using namespace std; 

class Solution {
public:
    string reverseWords(string s) {
        rmExtraSpaces(s);

        reverseStr(s, 0, s.size());
        //slow指针表示扫描到完整单词的首idx，fast表示最后一个位置的下一个
        int slow = 0;
        for (int fast = 0; fast < s.size(); fast++) {
            //找到单词结尾fast
            if (s[fast] == ' ') {
                reverseStr(s, slow, fast);
                slow = fast + 1;
                fast++;
            }
        }
        //处理最后一个单词
        reverseStr(s, slow, s.size());

        return s;
    }

private:
    void rmExtraSpaces(string& s) {
        int slow = 0;
        for (int fast = 0; fast < s.size(); fast++) {
            if (s[fast] != ' ') {
                if (slow != 0) {
                    s[slow++] = ' ';
                }
                while (fast < s.size() && s[fast] != ' ') {
                    s[slow++] = s[fast++];
                }
            }
        }
        s.resize(slow);
    }

    //[start, end)
    void reverseStr(string& s, int start, int end) {
        for (int i = start, j = end - 1; i < (end + start) / 2; i++, j--) {
            swap(s[i], s[j]);
        }
    }
};