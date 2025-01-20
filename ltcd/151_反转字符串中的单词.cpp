#include <iostream>
#include <string>
using namespace std; 

class Solution {
public:
    string reverseWords(string s) {
        rmExtraSpaces(s);

        reverseStr(s, 0, s.size());
        //slowָ���ʾɨ�赽�������ʵ���idx��fast��ʾ���һ��λ�õ���һ��
        int slow = 0;
        for (int fast = 0; fast < s.size(); fast++) {
            //�ҵ����ʽ�βfast
            if (s[fast] == ' ') {
                reverseStr(s, slow, fast);
                slow = fast + 1;
                fast++;
            }
        }
        //�������һ������
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